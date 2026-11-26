/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>
#include <string.h>


/* Application Includes ******************************************************/
#include "CGMG_MdGenerator.h"
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
void generateEnumeraionFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
void generateMdFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
bool generateFieldPrinter(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields);
void generateMdStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);

/* Public Methods  ***********************************************************/
CGMG_MdGenerator::CGMG_MdGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGMG_MdGenerator::GenerateHeader(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhHeader);
	fprintf(this->fhHeader,"\n");
	fprintf(this->fhHeader,"#ifndef %sP_Md_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#define %sP_Md_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"system includes");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"application includes");
	fprintf(this->fhHeader,"#include <myTypes.h>\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"component includes");
	fprintf(this->fhHeader,"#include <%s_Fillers.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#include <%s_MdUser.h>\n",this->preffix.c_str());
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
	//enumerations
	generateEnumeraionFunctions(this->fhHeader,interface,true);
	//functions
	fprintf(this->fhHeader,"//packets\n");
	fprintf(this->fhHeader,"void %sP_Print(uint8_t *target, uint16_t targetNb);\n",this->preffix.c_str());
	generateMdFunctions(this->fhHeader,interface,true);
	fprintf(this->fhHeader,"\n");
	//end if
	fprintf(this->fhHeader,"#endif\n");
}

void CGMG_MdGenerator::GenerateSource(CGDM_Interface *interface)
{
	printf("\tcopyright....\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfSystemIncldudes(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"application includes includes");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"component includes");
	fprintf(this->fhSource,"#include <%s_Md.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"#include <%s_MdUser.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local macros");
	fprintf(this->fhSource,"#define %sP_LABELSIZE_NB (%d)\n",interface->preffix.c_str(),255);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local types");
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"public variables");
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local variables");
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local prototypes");
	generateMdStructuresFunctions(this->fhSource,interface,true);
	fprintf(this->fhSource,"\n");

	fprintfLabel(this->fhSource,"public functions");
	//enumerations
	generateEnumeraionFunctions(this->fhSource,interface,false);

	//print function
	fprintf(this->fhSource,"void %sP_Print(uint8_t *target, uint16_t targetNb)\n",this->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"	uint16_t packetId = PUS_GetServiceSubServiceCompound(target, targetNb);\n");
	fprintf(this->fhSource,"	switch (packetId)\n");
	fprintf(this->fhSource,"	{\n");
	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhSource,"	case %s_%s_PACKETID:\n",interface->preffix.c_str(),stringToUpperString(thisPacket.name.c_str()).c_str());
		fprintf(this->fhSource,"		%sP_Print%s((%s_%s_t*)target);\n",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
		fprintf(this->fhSource,"		break;\n");
	}
	fprintf(this->fhSource,"	default:\n");
	fprintf(this->fhSource,"		printf(\"warning %sP_Print unknown packet, can not print\\n\");\n",this->preffix.c_str());
	fprintf(this->fhSource,"		break;\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"}\n");

	//packets
	generateMdFunctions(this->fhSource,interface,false);

	fprintfLabel(this->fhSource,"local functions");
	//structures
	generateMdStructuresFunctions(this->fhSource,interface,false);

}
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */

void generateEnumeraionFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	fprintf(fh,"//enumeration\n");
	for (auto & thisEnumeration : interface->typeEnums)
	{
		fprintf(fh,"void %sP_Print%s(uint8_t *target, %s_%s_t value)",interface->preffix.c_str(),thisEnumeration.name.c_str(),interface->preffix.c_str(),thisEnumeration.name.c_str());
		if (isJustPrototype)
		{
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"{\n");
			fprintf(fh,"	strcpy((char*)target, \"Unk.\");\n");
			fprintf(fh,"	switch (value)\n");
			fprintf(fh,"	{\n");
			for (auto & thisElement : thisEnumeration.elements)
			{
				fprintf(fh,"	case %s_%s:\n",interface->preffix.c_str(),thisElement.label.c_str());
				fprintf(fh,"		strcpy((char*)target, \"%s\");\n",thisElement.label.c_str());
				fprintf(fh,"		break;\n");
			}
			fprintf(fh,"	default:\n");
			fprintf(fh,"		strcpy((char*)target, \"Unk.\");\n");
			fprintf(fh,"		break;\n");
			fprintf(fh,"	}\n");
			fprintf(fh,"}\n");
		}
	}

}

bool generateFieldPrinter(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields)
{
	//multiplicity
	if (thisField->hasMultiplicity)
	{
		//TODO
		//fprintf(fh, "  %s hasMultiplicity\n\n",thisField->name.c_str());
		fprintf(fh, "  printf(\"\\t %s: \");\n", thisField->name.c_str());
		fprintf(fh, "  for (uint16_t %sIx = 0; %sIx < structureData->%s; %sIx++)\n", thisField->name.c_str(), thisField->name.c_str(), thisField->multiplicityFromField.c_str(), thisField->name.c_str());
		fprintf(fh, "  {\n");
		fprintf(fh, "      printf(\"%%d \", structureData->%s[%sIx]);\n", thisField->name.c_str(), thisField->name.c_str());
		fprintf(fh, "  }\n");
		fprintf(fh, "  printf(\"\\n\");\n");
	}
	//variable
	else if (thisField->type=="variable")
	{
		//fprintf(fh, "  %s variable\n\n",thisField->name.c_str());
		CGDM_TypeEnum *thisEnum=NULL;
		CGDM_Field *fieldFrom=getFieldFromName(thisField->typeFromField,brotherFields);
		if (fieldFrom!=NULL) thisEnum=getEnumByName(fieldFrom->type,interface);
		if ((fieldFrom!=NULL)&&(thisEnum!=NULL))
		{
			for (auto & thisElement : thisEnum->elements)
			{
				if (thisElement.relatedType!="null")
				{
					fprintf(fh,"  if (structureData->%s == %s_%s)\n",thisField->typeFromField.c_str(),interface->preffix.c_str(),thisElement.label.c_str());
					fprintf(fh,"  {\n");
					fprintf(fh,"    %sP_Print%s((%s_%s_t*)&structureData->%s);\n",interface->preffix.c_str(),thisElement.relatedType.c_str(),interface->preffix.c_str(),thisElement.relatedType.c_str(),thisField->name.c_str());
					fprintf(fh,"  }\n");
				}
			}
		}
	}
	//user-code
	else if (thisField->isUserCode)
	{
		fprintf(fh,"  %sPU_Print%s(&structureData->%s);\n",interface->preffix.c_str(),thisField->type.c_str(),thisField->name.c_str());
	}
	else if (thisField->isStructure)
	{
		fprintf(fh,"  %sP_Print%s(&structureData->%s);\n",interface->preffix.c_str(),thisField->type.c_str(),thisField->name.c_str());
	}
	else if (((thisField->isNative)||(thisField->isEnum))&&(thisField->hasMultiplicity==false))
	{
		if (thisField->isEnum)
		{
			fprintf(fh, "  uint8_t %sLabel[%sP_LABELSIZE_NB];\n", thisField->name.c_str(), interface->preffix.c_str());
			fprintf(fh, "  %sP_Print%s(%sLabel, structureData->%s);\n", interface->preffix.c_str(), thisField->type.c_str(), thisField->name.c_str(), thisField->name.c_str());
			fprintf(fh, "  printf(\"\\t %s: %%d - %%s\\n\", structureData->%s, %sLabel);\n", thisField->name.c_str(), thisField->name.c_str(), thisField->name.c_str());
			fprintf(fh, "\n");
		}
		else //native
		{
			//fprintf(fh, "  %s native\n\n",thisField->name.c_str());
			const char *format = "%d"; // Default for int32, uint32
			if (strcmp((char *)thisField->type.c_str(), "uint64") == 0 || strcmp((char *)thisField->type.c_str(), "int64") == 0)
			{
				format = "%ld"; // Long format for 64-bit integers
			}
			else if (strcmp((char *)thisField->type.c_str(), "float32") == 0 || strcmp((char *)thisField->type.c_str(), "float64") == 0)
			{
				format = "%f"; // Float format for floating-point types
			}
			else if (strcmp((char *)thisField->type.c_str(), "uint8") == 0)
			{
				format = "%u"; // Unsigned format for uint8
			}
			fprintf(fh, "  printf(\"\\t %s: %s\\n\", structureData->%s);\n\n", thisField->name.c_str(), format, thisField->name.c_str());
		}
	}
	return true;
}

void generateMdFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	for (auto & thisPacket : interface->packets)
	{
		fprintf(fh,"void %sP_Print%s(%s_%s_t *structureData)",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
		if (isJustPrototype)
		{

			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"{\n");
			fprintf(fh,"  printf(\"\\t %s \\n\");\n",thisPacket.name.c_str());
			for (auto & thisField : thisPacket.fields)
			{
				std::string multiplicityIndex="";
				generateFieldPrinter(fh,&thisField,interface,&multiplicityIndex,&thisPacket.fields);
			}
			fprintf(fh,"}\n");

		}
	}
}

void generateMdStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	for (auto & thisStructure : interface->typeStructures)
	{
		//void ASWP_PrintUnexpectedValueUint16(ASW_UnexpectedValueUint16_t *structureData);
		fprintf(fh,"void %sP_Print%s(%s_%s_t *structureData)",interface->preffix.c_str(),thisStructure.name.c_str(),interface->preffix.c_str(),thisStructure.name.c_str());
		if (isJustPrototype)
		{
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"{\n");
			fprintf(fh,"  printf(\"\\t %s \\n\");\n",thisStructure.name.c_str());
			for (auto & thisField : thisStructure.fields)
			{
				std::string multiplicityIndex="";
				generateFieldPrinter(fh,&thisField,interface,&multiplicityIndex,&thisStructure.fields);
			}
			fprintf(fh,"}\n");
		}
	}
}
