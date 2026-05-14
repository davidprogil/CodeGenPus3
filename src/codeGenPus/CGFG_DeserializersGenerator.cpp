/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>



/* Application Includes ******************************************************/
#include "CGFG_DeserializersGenerator.h"
#include "CGFG_FillersGenerator.h"

//from CGFG_FillersGenerator
void fprintfCopyright(FILE *fh);
void fprintfLabel(FILE *fh,std::string label);
void fprintfSystemIncldudes(FILE *fh);
std::string stringToUpperString(std::string in);
CGDM_Field *getFieldFromName(std::string name,std::vector <CGDM_Field>  *brotherFields);
CGDM_TypeEnum *getEnumByName(std::string name,CGDM_Interface *interface);
//eof from CGFG_FillersGenerator


//privates
void generateDeserializersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
void generateDeserializersStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);

/* Public Methods  ***********************************************************/
CGFG_DeserializersGenerator::CGFG_DeserializersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGFG_DeserializersGenerator::GenerateHeader(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhHeader);
	fprintf(this->fhHeader,"\n");
	fprintf(this->fhHeader,"#ifndef %sF_Serializers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#define %sF_Serializers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"system includes");
	fprintf(this->fhHeader,"/* none */");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"application includes");
	fprintf(this->fhHeader,"#include <myTypes.h>");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"component includes");
	fprintf(this->fhHeader,"#include <%s_Fillers.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#include <%s_DeserializersUser.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"macros");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"macros");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"types");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"public variables");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"public functions");
	fprintf(this->fhHeader,"%s_DeserializerFunction_t *%sD_GetDeserializerFunction(uint16_t packetId);\n",interface->preffix.c_str(),interface->preffix.c_str());
	generateDeserializersFunctions(this->fhHeader,interface,true);
	fprintf(this->fhHeader,"\n");
	//end if
	fprintf(this->fhHeader,"#endif\n");
}

void CGFG_DeserializersGenerator::GenerateSource(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfSystemIncldudes(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"application includes includes");
	fprintf(this->fhSource,"#include <LIB_Endian.h>\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"component includes");
	fprintf(this->fhSource,"#include <%s_Deserializers.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local macros");
	fprintf(this->fhSource,"#define %sD_DESERIALIZER_FUNCTION_NO (%ld)\n",interface->preffix.c_str(),interface->packets.size());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local types");
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"typedef struct _%s_DeserializerFunctionLut_t_\n",interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"  uint16_t packetId;\n");
	fprintf(this->fhSource,"  %s_DeserializerFunction_t *deserializer;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"}%sD_DeserializerFunctionLut_t;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"public variables");
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local variables");
	fprintf(this->fhSource,"%sD_DeserializerFunctionLut_t %s_DeserializerFunctionLut[%sD_DESERIALIZER_FUNCTION_NO] =\n",interface->preffix.c_str(),interface->preffix.c_str(),interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhSource,"  {%s_%s_PACKETID, %sD_Deserialize%s},\n",interface->preffix.c_str(),stringToUpperString(thisPacket.name).c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
	}
	fprintf(this->fhSource,"};\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local prototypes");
	printf("\tstructures prototypes... \n");
	generateDeserializersStructuresFunctions(this->fhSource,interface,true);
	fprintf(this->fhSource,"\n");

	//packets
	printf("\tpackets... %ld\n",interface->packets.size());
	fprintfLabel(this->fhSource,"public functions");
	//special function
	fprintf(this->fhSource,"%s_DeserializerFunction_t *%sD_GetDeserializerFunction(uint16_t packetId)\n",interface->preffix.c_str(),interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"  %s_DeserializerFunction_t *deserializer = NULL;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintf(this->fhSource,"  for (uint16_t fIx = 0; fIx < %sD_DESERIALIZER_FUNCTION_NO; fIx++)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"  {\n");
	fprintf(this->fhSource,"    if (packetId == %s_DeserializerFunctionLut[fIx].packetId)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"    {\n");
	fprintf(this->fhSource,"      deserializer = %s_DeserializerFunctionLut[fIx].deserializer;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"      break;\n");
	fprintf(this->fhSource,"    }\n");
	fprintf(this->fhSource,"  }\n");
	fprintf(this->fhSource,"\n");
	fprintf(this->fhSource,"  return deserializer;\n");
	fprintf(this->fhSource,"}\n");
	generateDeserializersFunctions(this->fhSource,interface,false);

	//structures
	printf("\tstructures... \n");
	fprintfLabel(this->fhSource,"local functions");
	generateDeserializersStructuresFunctions(this->fhSource,interface,false);

}
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
void generateFieldDeserializer(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields)
{
	fprintf(fh,"    //%s\n",thisField->name.c_str());
	//multiplicity
	if (thisField->hasMultiplicity)
	{
				fprintf(fh,"  for (uint16_t %sIx = 0; %sIx < structuredData->%s; %sIx++)\n",
						thisField->name.c_str(),thisField->name.c_str(),thisField->multiplicityFromField.c_str(),thisField->name.c_str());
				fprintf(fh,"  {\n");
				CGDM_Field thisField2=*thisField;
				thisField2.hasMultiplicity=false;
		 *multiplicityIndex+="[";
		 *multiplicityIndex+=thisField->name;
		 *multiplicityIndex+="Ix]";
				generateFieldDeserializer(fh,&thisField2,interface,multiplicityIndex,brotherFields);
				fprintf(fh,"  }\n");
	}
	//variable
	else if (thisField->type=="variable")
	{
		CGDM_TypeEnum *thisEnum=NULL;
		CGDM_Field *fieldFrom=getFieldFromName(thisField->typeFromField,brotherFields);
		if (fieldFrom!=NULL) thisEnum=getEnumByName(fieldFrom->type,interface);
		if ((fieldFrom!=NULL)&&(thisEnum!=NULL))
		{
			for (auto & thisElement : thisEnum->elements)
			{
				if (thisElement.relatedType!="null")
				{
					fprintf(fh,"    if (structuredData->%s == %s_%s)\n",thisField->typeFromField.c_str(),interface->preffix.c_str(),thisElement.label.c_str());
					fprintf(fh,"    {\n");
					fprintf(fh,"      isValid = %sD_Deserialize%s((%s_%s_t*)&structuredData->%s, outputNb, walkingNb, packetRaw, packetRawNb);\n",interface->preffix.c_str(),thisElement.relatedType.c_str(),interface->preffix.c_str(),thisElement.relatedType.c_str(),thisField->name.c_str());
					fprintf(fh,"    }\n");
				}
			}
		}
	}
	//user code or structure
	else if ((thisField->isStructure)||(thisField->isUserCode))
	{
		fprintf(fh,"    isValid = %sDU_Deserialize%s(&structuredData->%s, outputNb, walkingNb, packetRaw, packetRawNb);\n",interface->preffix.c_str(),thisField->type.c_str(),thisField->name.c_str());
	}
	else if (((thisField->isNative)||(thisField->isEnum))&&(thisField->hasMultiplicity==false))
	{
		//native
		fprintf(fh,"    memcpy((uint8_t*)&structuredData->%s%s, &packetRaw[*walkingNb], sizeof(%s_t));\n",thisField->name.c_str(),multiplicityIndex->c_str(),thisField->enumBaseType.c_str());
		//fprintf(fh,"    structuredData->%s%s = (%s_t)packetRaw[*walkingNb];\n",thisField->name.c_str(),multiplicityIndex->c_str(),thisField->enumBaseType.c_str());


		if ((thisField->enumBaseType!="uint8")&&(thisField->enumBaseType!="int8"))
		{
			fprintf(fh,"    LEND_Network2Host((uint8_t*)&structuredData->%s%s, sizeof(%s_t));\n",thisField->name.c_str(),multiplicityIndex->c_str(),thisField->enumBaseType.c_str());
		}
		fprintf(fh,"    *walkingNb += sizeof(%s_t);\n",thisField->enumBaseType.c_str());
	}
	else
	{
		printf("\t\t error: unnacounted field\n");
	}


	//fprintf(fh,"\n");

}

void generateDeserializersStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	for (auto & thisStructure : interface->typeStructures)
	{

		if (isJustPrototype)
		{
			fprintf(fh,"%s_DeserializerFunction_t %sD_Deserialize%s",interface->preffix.c_str(),interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"bool_t %sD_Deserialize%s(void *output, uint16_t outputNb, uint16_t *walkingNb, uint8_t *packetRaw, uint16_t packetRawNb)\n",interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,"{\n");
			fprintf(fh,"  bool_t isValid = M_TRUE;\n");
			fprintf(fh,"  uint16_t myWalkingNb = 0;\n");
			fprintf(fh,"  if (walkingNb == NULL) walkingNb = &myWalkingNb;\n");
			fprintf(fh,"  %s_%s_t *structuredData = (%s_%s_t*)output;\n",interface->preffix.c_str(),thisStructure.name.c_str(),interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,"  \n");
			fprintf(fh,"  if ((outputNb - *walkingNb) < sizeof(%s_%s_t))\n",interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,"  {\n");
			fprintf(fh,"    isValid = M_FALSE;\n");
			fprintf(fh,"  }\n");
			fprintf(fh,"  else\n");
			fprintf(fh,"  {\n");
			for (auto & thisField : thisStructure.fields)
			{
				std::string multiplicityIndex="";
				generateFieldDeserializer(fh,&thisField,interface,&multiplicityIndex,&thisStructure.fields);
			}
			fprintf(fh,"  }\n");
			fprintf(fh,"\n");
			fprintf(fh,"  return isValid;\n");
			fprintf(fh,"}\n");
			fprintf(fh,"\n");
		}
	}
}

void generateDeserializersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{

	for (auto & thisPacket : interface->packets)
	{

		if (isJustPrototype)
		{
			fprintf(fh,"%s_DeserializerFunction_t %sD_Deserialize%s",interface->preffix.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"bool_t %sD_Deserialize%s(void *output, uint16_t outputNb, uint16_t *walkingNb, uint8_t *packetRaw, uint16_t packetRawNb)\n",interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,"{\n");
			fprintf(fh,"  bool_t isValid = M_TRUE;\n");
			fprintf(fh,"  uint16_t myWalkingNb = 0;\n");
			fprintf(fh,"  if (walkingNb == NULL) walkingNb = &myWalkingNb;\n");
			fprintf(fh,"  %s_%s_t *structuredData = (%s_%s_t*)output;\n",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,"  \n");
			fprintf(fh,"  if ((outputNb - *walkingNb) < sizeof(%s_%s_t))\n",interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,"  {\n");
			fprintf(fh,"    isValid = M_FALSE;\n");
			fprintf(fh,"  }\n");
			fprintf(fh,"  else\n");
			fprintf(fh,"  {\n");
			for (auto & thisField : thisPacket.fields)
			{
				std::string multiplicityIndex="";
				generateFieldDeserializer(fh,&thisField,interface,&multiplicityIndex,&thisPacket.fields);
			}
			fprintf(fh,"  }\n");
			fprintf(fh,"\n");
			fprintf(fh,"  return isValid;\n");
			fprintf(fh,"}\n");
			fprintf(fh,"\n");
		}
	}
}
