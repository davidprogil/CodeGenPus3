/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>



/* Application Includes ******************************************************/
#include "CGFG_FillersGenerator.h"

void GenerateFieldDeclaration(FILE *fh,CGDM_Field *field,std::vector <CGDM_Field>  *fields,CGDM_Interface *interface);
void WriteFunctionSignature(FILE *fh,CGDM_Packet *packet,CGDM_Interface *interface);
void WriteSizersSignature(FILE *fh,CGDM_Interface *interface,bool isPrototype);

/* Public Methods  ***********************************************************/
CGFG_FillersGenerator::CGFG_FillersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGFG_FillersGenerator::GenerateHeader(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhHeader);
	fprintf(this->fhHeader,"\n");
	fprintf(this->fhHeader,"#ifndef %sF_Fillers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#define %sF_Fillers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"system includes");
	fprintf(this->fhHeader,"/* none */");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"application includes");
	fprintf(this->fhHeader,"#include <myTypes.h>");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"component includes");
	fprintf(this->fhHeader,"#include <%s_FillersUser.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"macros");

	// packet IDS /////////////////////////////////////////////////////////////////////////
	printf("\tpacket IDs...\n");
	fprintf(this->fhHeader,"//packet IDs\n");

	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhHeader,"#define %s_%s_PACKETID (%s)\n",this->preffix.c_str(),stringToUpperString(thisPacket.name).c_str(),thisPacket.id.c_str());
		fprintf(this->fhHeader,"#define %s_%s_SERVICE ((%s_%s_PACKETID & (0xFF00)) >> 8)\n",this->preffix.c_str(),stringToUpperString(thisPacket.name).c_str(),this->preffix.c_str(),stringToUpperString(thisPacket.name).c_str());
		fprintf(this->fhHeader,"#define %s_%s_SUBSERVICE (%s_%s_PACKETID & (0x00FF))\n",this->preffix.c_str(),stringToUpperString(thisPacket.name).c_str(),this->preffix.c_str(),stringToUpperString(thisPacket.name).c_str());


	}
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"types");
	// enums /////////////////////////////////////////////////////////////////////////
	printf("\tEnumerations...\n");
	fprintf(this->fhHeader,"//enumerations\n");
	for (auto & thisEnum : interface->typeEnums)
	{
		//typedef enum _ASW_EnumPktType_t
		fprintf(this->fhHeader,"typedef enum _%s_%s_t\n",this->preffix.c_str(),thisEnum.name.c_str());
		fprintf(this->fhHeader,"{\n");
		int elementsNo=0;

		for (auto & thisEnumElement : thisEnum.elements)
		{
			fprintf(this->fhHeader,"  %s_%s=%d,\n",this->preffix.c_str(),thisEnumElement.label.c_str(),thisEnumElement.value);
			elementsNo++;
		}
		std::string label=thisEnum.elements.at(0).label;
		std::string abbrev2=label.substr(0,label.find('_'));
		fprintf(this->fhHeader,"  %s_%s_NB=%d\n",preffix.c_str(),abbrev2.c_str(),elementsNo);

		fprintf(this->fhHeader,"} %s_%s_t;\n",this->preffix.c_str(),thisEnum.name.c_str());
		fprintf(this->fhHeader,"\n");
	}
	fprintf(this->fhHeader,"\n");
	// structures /////////////////////////////////////////////////////////////////////////
	printf("\tStructures...\n");
	fprintf(this->fhHeader,"//structures\n");
	for (auto & thisStruct : interface->typeStructures)
	{
		//typedef struct __attribute__((packed)) _ASW_UnexpectedValueUint16_t_ //TODO
		fprintf(this->fhHeader,"typedef struct __attribute__((packed)) _%s_%s_t_\n",this->preffix.c_str(),thisStruct.name.c_str());
		fprintf(this->fhHeader,"{\n");
		for (auto & thisField : thisStruct.fields)
		{
			GenerateFieldDeclaration(this->fhHeader,&thisField,&thisStruct.fields,interface);
		}
		fprintf(this->fhHeader,"} %s_%s_t;\n",this->preffix.c_str(),thisStruct.name.c_str());
		fprintf(this->fhHeader,"\n");
	}
	fprintf(this->fhHeader,"\n");
	// packets /////////////////////////////////////////////////////////////////////////
	printf("\tPackets...\n");
	fprintf(this->fhHeader,"//packets\n");
	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhHeader,"typedef struct __attribute__((packed)) _%s_%s_t_\n",this->preffix.c_str(),thisPacket.name.c_str());
		fprintf(this->fhHeader,"{\n");
		for (auto & thisField : thisPacket.fields)
		{
			GenerateFieldDeclaration(this->fhHeader,&thisField,&thisPacket.fields,interface);
		}
		fprintf(this->fhHeader,"} %s_%s_t;\n",this->preffix.c_str(),thisPacket.name.c_str());
		fprintf(this->fhHeader,"\n");
	}
	fprintf(this->fhHeader,"\n");
	// prototypes /////////////////////////////////////////////////////////////////////////
	printf("\tPrototypes...\n");
	//packets
	for (auto & thisPacket : interface->packets)
	{
		WriteFunctionSignature(this->fhHeader,&thisPacket,interface);
		fprintf(this->fhHeader,";\n");
	}
	fprintf(this->fhHeader,"\n");
	//sizers
	WriteSizersSignature(this->fhHeader,interface,true);
	fprintf(this->fhHeader,"\n");
	//end if
	fprintf(this->fhHeader,"#endif\n");
}

void CGFG_FillersGenerator::GenerateSource(CGDM_Interface *interface)
{
	//TODO

}
/* Public Functions ******************************************************/
std::string stringToUpperString(std::string input_text)
{

	std::string out=input_text;
	std::transform(out.begin(), out.end(), out.begin(), ::toupper);

	return out;
}
void fprintfLabel(FILE *fh,std::string label)
{
	fprintf(fh,"/* %s-------------------------------------------------------------*/\n",label.c_str());
}
void fprintfCopyright(FILE *fh)
{
	fprintf(fh,"/*******************************************************************************/\n");
	fprintf(fh,"/* Copyright XXXXXXXXX 1998-YYYY                                               */\n");
	fprintf(fh,"/*                                                                             */\n");
	fprintf(fh,"/* xxxxxxxx@xxxxx.xxx                                                          */\n");
	fprintf(fh,"/*******************************************************************************/\n");
}
//t.thiam@dasholding.ae

/* Private Methods  ***********************************************************/
void WriteSizersSignature(FILE *fh,CGDM_Interface *interface,bool isPrototype)
{


	for (auto & thisEnum : interface->typeEnums)
	{
		//uint16_t ASWF_GetSizeForEnumFid(ASW_EnumFid_t valueEnumFid);
		fprintf(fh,"uint16_t %sF_GetSizeFor%s(%s_%s_t value%s)",interface->preffix.c_str(),thisEnum.name.c_str(),interface->preffix.c_str(),thisEnum.name.c_str(),thisEnum.name.c_str());

		if (isPrototype)
		{
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"\n");
		}
	}
}
void WriteFunctionSignature(FILE *fh,CGDM_Packet *packet,CGDM_Interface *interface)
{
	fprintf(fh,"void %sF_Fill%s(ASW_%s_t *target",interface->preffix.c_str(),packet->name.c_str(),packet->name.c_str());
	for (auto & thisField : packet->fields)
	{
		//native or enum
		if (((thisField.isNative)||(thisField.isEnum))&&(thisField.hasMultiplicity==false))
		{
			fprintf(fh,", %s_t %s",thisField.type.c_str(),thisField.name.c_str());
		}
		//structure or multiplicity
		else if ((thisField.isStructure)||(thisField.hasMultiplicity))
		{
			fprintf(fh,", %s_t *%s",thisField.type.c_str(),thisField.name.c_str());
		}
		else if (thisField.type=="variable")
		{
		//variable type
		fprintf(fh,", void *%s,uint16_t %sNb",thisField.name.c_str(),thisField.name.c_str());
		//void *failureInfo, uint16_t failureInfoNb);
		}
	}


	fprintf(fh,")");
}
void GenerateFieldDeclaration(FILE *fh,CGDM_Field *thisField,std::vector <CGDM_Field>  *fields,CGDM_Interface *interface)
{
	if (thisField->type!="variable")
	{
		if (thisField->isEnum==false)
		{
		fprintf(fh,"  %s_t ",thisField->type.c_str());
		}
		else
		{
			fprintf(fh,"  %s_t ",thisField->enumBaseType.c_str());
		}
	}
	else
	{
		fprintf(fh,"  union\n");
		fprintf(fh,"  {\n");
		//search field in types
		std::string relatedType="";
		for (auto & thisField2 : *fields)
		{
			if (thisField2.name==thisField->typeFromField)
			{
				relatedType=thisField2.type;
			}
		}
		//search enums in interface
		for (auto & thisEnum : interface->typeEnums)
		{
			if (thisEnum.name==relatedType)
			{
				//go into all enumElements
				std::vector <std::string> types;
				for (auto & thisEnumElement : thisEnum.elements)
				{
					if (thisEnumElement.relatedType!="null")
					{
						bool isFound=false;

						for (auto & thisString : types)
						{
							if (thisString==thisEnumElement.relatedType) isFound=true;
						}
						//if not repeated
						if (isFound==false)
						{
							types.push_back(thisEnumElement.relatedType);
							fprintf(fh,"   %s_%s_t %s;\n",interface->preffix.c_str(),thisEnumElement.relatedType.c_str(),thisEnumElement.relatedType.c_str());
						}
					}
				}
			}
		}
		fprintf(fh,"  }");
	}

	fprintf(fh,"%s",thisField->name.c_str());

	if (thisField->hasMultiplicity==true) //need to find max value
	{
		uint32_t maxValue=0;

		//find field with name
		for (auto & thisField2 : *fields)
		{
			if (thisField2.name==thisField->multiplicityFromField)
			{
				maxValue=std::stoi(thisField2.restrictionMaxInclusive);
			}
		}

		fprintf(fh,"[%d]",maxValue);
	}
	fprintf(fh,";\n");
}

/* Private Functions ******************************************************/
/* none */
