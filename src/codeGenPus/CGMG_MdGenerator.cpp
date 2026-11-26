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

std::string convertToMd(const std::string& str);

//from CGFG_FillersGenerator
CGDM_Field *getFieldFromName(std::string name,std::vector <CGDM_Field>  *brotherFields);
CGDM_TypeEnum *getEnumByName(std::string name,CGDM_Interface *interface);
//eof from CGFG_FillersGenerator


//privates
void generateEnumeraionFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
void generateMdFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
bool generateFieldPrinter(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields);
void generateMdStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);

/* Public Methods  ***********************************************************/
CGMG_MdGenerator::CGMG_MdGenerator(FILE *fhMd_p,FILE *fhTemplate_p,std::string preffix_p)
{ // Constructor
	this->fhMd=fhMd_p;
	this->fhTemplate=fhTemplate_p;
	this->preffix=preffix_p;
}

void CGMG_MdGenerator::GenerateMd(CGDM_Interface *interface)
{
	//generate template
	this->GenerateTemplate(interface);
	//generate packets
	this->GeneratePackets(interface);
	//generate structures
	this->GenerateStructures(interface);
	//custom structures:
	//TODO PUS_TmSecondaryHeader / PUS_TcSecondaryHeader
	//generate Enums
	this->GenerateEnums(interface);
}

/*void CGMG_MdGenerator::GenerateHeader(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhHeader);
	fprintf(this->fhHeader,"\n");
	fprintf(this->fhHeader,"#ifndef %sP_Md_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#define %sP_Md_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"system includes");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"application includes");
	fprintf(this->fhHeader,"#include <myTypes.h>\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"component includes");
	fprintf(this->fhHeader,"#include <%s_Fillers.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#include <%s_MdUser.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"macros");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"macros");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"types");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"public variables");
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
	/*printf("\tcopyright....\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfSystemIncldudes(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"application includes includes");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"component includes");
	fprintf(this->fhSource,"#include <%s_Md.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"#include <%s_MdUser.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local macros");
	fprintf(this->fhSource,"#define %sP_LABELSIZE_NB (%d)\n",interface->preffix.c_str(),255);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local types");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"public variables");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local variables");
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

}*/
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
void CGMG_MdGenerator::GenerateStructures(CGDM_Interface *interface)
{
	fprintf(this->fhMd,"\n");
	fprintf(this->fhMd,"### Structure Types\n");

	for (auto & thisStructure : interface->typeStructures)
	{
		fprintf(this->fhMd,"#### %s\n",thisStructure.name.c_str());
		fprintf(this->fhMd,"Data Fields:<br>\n");
		for (auto & thisField : thisStructure.fields)
		{
			this->GenerateField(interface, &thisField);
		}
	}

}
void CGMG_MdGenerator::GenerateTemplate(CGDM_Interface *interface)
{
	//read and write template at the same time
	int c;

	while ((c = fgetc(this->fhTemplate)) != EOF)
	{
		fputc(c, this->fhMd);
	}
}

void CGMG_MdGenerator::GenerateField(CGDM_Interface *interface,CGDM_Field *thisField)
{
	//native
	if (thisField->isNative)
	{
		fprintf(this->fhMd,"- Name: %s Type: %s<br>\n",thisField->name.c_str(),thisField->type.c_str());
	}
	//structure
	if (thisField->isStructure)
	{
		std::string typeMd=convertToMd(thisField->type);
		fprintf(this->fhMd,"- Name: %s Type: [%s](#%s)<br>\n",thisField->name.c_str(),thisField->type.c_str(),typeMd.c_str());
	}
	//enums
	if (thisField->isEnum)
	{
		std::string typeMd=convertToMd(thisField->type);
		fprintf(this->fhMd,"- Name: %s Type: %s<br>\n",thisField->name.c_str(),thisField->enumBaseType.c_str());
	}
	//restrictions
	if ((thisField->hasRestriction)||(thisField->isEnum))
	{
		fprintf(this->fhMd,"The value in this field has restrictions:<br>\n");
		if (thisField->isEnum)
		{
			std::string typeMd=convertToMd(thisField->type);
			fprintf(this->fhMd,"Value restricted by enumeration: [%s](#%s)<br>\n",thisField->type.c_str(),typeMd.c_str());
		}
		else
		{
			if (thisField->restrictionFixedValue!="")
			{
				fprintf(this->fhMd,"Fixed Value: %s<br>\n",thisField->restrictionFixedValue.c_str());
			}
			//std::string restrictionMaxInclusive;
			if (thisField->restrictionMaxInclusive!="")
			{
				fprintf(this->fhMd,"Smaller or Equal to: %s<br>\n",thisField->restrictionMaxInclusive.c_str());
			}
			//std::string restrictionMaxExclusive;
			if (thisField->restrictionMaxExclusive!="")
			{
				fprintf(this->fhMd,"Smaller than: %s<br>\n",thisField->restrictionMaxExclusive.c_str());
			}
			//std::string restrictionMinExclusive;
			if (thisField->restrictionMinExclusive!="")
			{
				fprintf(this->fhMd,"Bigger than: %s<br>\n",thisField->restrictionMinExclusive.c_str());
			}
			//std::string restrictionMinInclusive;
			if (thisField->restrictionMinInclusive!="")
			{
				fprintf(this->fhMd,"Bigger or Equal to: %s<br>\n",thisField->restrictionMinInclusive.c_str());
			}


		}
	}
	//variable
	if (thisField->type=="variable")
	{
		fprintf(this->fhMd,"this field content depends on the type indicated by %s<br>\n,",thisField->typeFromField.c_str());

	}
	//multiplicity
	if (thisField->hasMultiplicity)
	{
		fprintf(this->fhMd,"the number of times this field appears in the data is dictated by %s<br>\n,",thisField->multiplicityFromField.c_str());
	}

}
void CGMG_MdGenerator::GeneratePackets(CGDM_Interface *interface)
{
	fprintf(this->fhMd,"\n");
	fprintf(this->fhMd,"## Data Definition\n");
	fprintf(this->fhMd,"### Packets Definition\n");
	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhMd,"#### %s\n",thisPacket.name.c_str());
		fprintf(this->fhMd,"Packet ID: %s<br>\n",thisPacket.id.c_str());
		fprintf(this->fhMd,"Description: %s<br>\n",thisPacket.description.c_str());
		fprintf(this->fhMd,"Data Fields:<br>\n");
		for (auto & thisField : thisPacket.fields)
		{
			this->GenerateField(interface, &thisField);

		}
	}
	fprintf(this->fhMd,"<br>\n");
}
void CGMG_MdGenerator::GenerateEnums(CGDM_Interface *interface)
{
	fprintf(this->fhMd,"\n");
	fprintf(this->fhMd,"### Enumerations\n");
	for (auto & thisEnumeration : interface->typeEnums)
	{
		fprintf(this->fhMd,"#### %s\n",thisEnumeration.name.c_str());
		fprintf(this->fhMd," Base type: %s\n",thisEnumeration.baseType.c_str());
		fprintf(this->fhMd," | Label | Value | associated type |\n");
		fprintf(this->fhMd," |-------|-------|-----------------|\n");
		for (auto & thisElement : thisEnumeration.elements)
		{
			fprintf(this->fhMd," |%s|%d|%s|\n",thisElement.label.c_str(),thisElement.value,thisElement.relatedType.c_str());
		}
	}
}

/* Private Functions ******************************************************/
std::string convertToMd(const std::string& str)
{
	std::string result = str;

	std::transform(result.begin(), result.end(), result.begin(),
			[](unsigned char c) { return std::tolower(c); });

	return result;
}


