/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>



/* Application Includes ******************************************************/
#include "CGPG_PrintersGenerator.h"
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
void generatePrintersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);
bool generateFieldPrinter(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields);
void generatePrintersStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);

/* Public Methods  ***********************************************************/
CGPG_PrintersGenerator::CGPG_PrintersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGPG_PrintersGenerator::GenerateHeader(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhHeader);
	fprintf(this->fhHeader,"\n");
	fprintf(this->fhHeader,"#ifndef %sP_Printers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#define %sP_Printers_H\n",this->preffix.c_str());
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"system includes");
	fprintf(this->fhHeader,"/* none */\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"application includes");
	fprintf(this->fhHeader,"#include <myTypes.h>\n");
	fprintf(this->fhHeader,"\n");

	fprintfLabel(this->fhHeader,"component includes");
	fprintf(this->fhHeader,"#include <%s_Fillers.h>\n",this->preffix.c_str());
	fprintf(this->fhHeader,"#include <%s_PrintersUser.h>\n",this->preffix.c_str());
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
	fprintf(this->fhHeader,"void ASWP_Print(uint8_t *target, uint16_t targetNb);\n");
	generatePrintersFunctions(this->fhHeader,interface,true);
	fprintf(this->fhHeader,"\n");
	//end if
	fprintf(this->fhHeader,"#endif\n");
}

void CGPG_PrintersGenerator::GenerateSource(CGDM_Interface *interface)
{
	printf("\tcopyright....\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfSystemIncldudes(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"application includes includes");
	fprintf(this->fhSource,"#include <LIB_Endian.h>\n");
	fprintf(this->fhSource,"#include <LIB_Crc.h>\n");
	fprintf(this->fhSource,"\n");

	fprintfLabel(this->fhSource,"component includes");
	fprintf(this->fhSource,"#include <%s_Printers.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"#include <%s_Deserializers.h>\n",this->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local macros");
	fprintf(this->fhSource,"#define %s_Printer_FUNCTION_NO (%ld)\n",interface->preffix.c_str(),interface->packets.size());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local types");
	fprintf(this->fhSource,"typedef struct _%sP_PrinterFunctionLut_t_\n",interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"	uint16_t packetId;\n");
	fprintf(this->fhSource,"	%sP_PrinterFunction_t *Printer;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"} %sP_PrinterFunctionLut_t;\n\n",interface->preffix.c_str());
	//enumerations
	for (auto & thisEnum : interface->typeEnums)
	{
		std::string firstElemName=thisEnum.elements.at(0).label;
		std::string enumAbbreviation=firstElemName.substr(0,firstElemName.find('_'));
		fprintf(this->fhSource,"uint32_t %s_%s_AllowedValues[%s_%s_NB] = {",
				interface->preffix.c_str(),
				thisEnum.name.c_str(),
				interface->preffix.c_str(),
				enumAbbreviation.c_str());
		for (auto & thisElement : thisEnum.elements)
		{
			fprintf(this->fhSource,"%s_%s",interface->preffix.c_str(),thisElement.label.c_str());
			if (thisElement.label!=thisEnum.elements.at(thisEnum.elements.size()-1).label)
			{
				fprintf(this->fhSource,",");
			}
		}
		fprintf(this->fhSource,"};\n");
	}
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local types");
	fprintf(this->fhSource,"/*none*/\n\n");
	fprintfLabel(this->fhSource,"local variables");
	fprintf(this->fhSource,"ASWV_PrinterFunctionLut_t ASW_PrinterFunctionLut[ASW_Printer_FUNCTION_NO] =\n");
	fprintf(this->fhSource,"{\n");
	for (auto & thisPacket : interface->packets)
	{
		fprintf(this->fhSource,"	{%s_%s_PACKETID, %sPU_Validate%s}",interface->preffix.c_str(),stringToUpperString(thisPacket.name).c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
		if (thisPacket.name!=interface->packets.at(interface->packets.size()-1).name)
		{
			fprintf(this->fhSource,",\n");
		}
		else
		{
			fprintf(this->fhSource,"\n");
		}
	}
	fprintf(this->fhSource,"};\n");
	fprintfLabel(this->fhSource,"local prototypes");
	fprintf(this->fhSource,"%sP_PrinterFunction_t *%s_GetPrinterFunction(uint16_t packetId);\n",interface->preffix.c_str(),interface->preffix.c_str());
	fprintf(this->fhSource,"bool_t %sP_IsEnumerationValueValid(uint32_t *allowedValues, uint16_t allowedValuesNb, uint32_t value);\n",interface->preffix.c_str());
	generatePrintersStructuresFunctions(this->fhSource,interface,true);
	fprintf(this->fhSource,"\n");

	fprintfLabel(this->fhSource,"public functions");
	//validate function
	fprintf(this->fhSource,"bool_t %sP_ValidatePacket(uint8_t *packetRaw, uint16_t totalLength, void *structuredData, uint16_t outputNb, uint16_t *packetId, uint16_t *failureId, uint8_t *failureInfo)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"	bool_t isValid = M_TRUE;\n");
	fprintf(this->fhSource,"	CCSDS_Packet_t *packetStructured = (CCSDS_Packet_t *)packetRaw;\n");
	fprintf(this->fhSource,"	%s_DeserializerFunction_t *deserializer = NULL;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"	*failureId = %s_FID_OK;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"	uint16_t parameterCounter;\n");
	fprintf(this->fhSource,"	PUS_Crc_t expectedCrc = 0;\n");
	fprintf(this->fhSource,"	CCSDS_Packet_t packet;\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	//calculate CRC\n");
	fprintf(this->fhSource,"	if (totalLength > sizeof(uint16_t))\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		expectedCrc = CRC_CcsdsCrc16Get(PUS_DEFAULT_CRC_SEED, PUS_DEFAULT_CRC_OFFSET, packetRaw, totalLength - sizeof(PUS_Crc_t));\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	//if it is big enough to have primary header\n");
	fprintf(this->fhSource,"	//if data length is correct\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		%sDU_DeserializeCCSDS_PrimaryHeader(&packet,sizeof(packet),NULL,packetRaw,totalLength);\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintf(this->fhSource,"		isValid = CCSDS_IsPacketSizeValid(&packet, totalLength);\n");
	fprintf(this->fhSource,"		if (isValid == M_FALSE)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_INVALID_PLENGTH;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			printf(\"Warning %sP_ValidatePacket bad length\\n\");\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	//if it has secondary header\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		packetStructured=&packet;\n");
	fprintf(this->fhSource,"		isValid = (packetStructured->primaryHeader.secondaryHeader == M_TRUE);\n");
	fprintf(this->fhSource,"		if (isValid == M_FALSE)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_ILLEGAL_PUS_VERSION;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			printf(\"Warning %sP_ValidatePacket not a PUS packet \\n\");\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	//if CRC is correct\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		PUS_Crc_t foundCrc = 0;\n");
	fprintf(this->fhSource,"		isValid = PUS_IsCrcValid(packetRaw, totalLength, &expectedCrc, &foundCrc);\n");
	fprintf(this->fhSource,"		if (isValid == M_FALSE)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_CS_DISCREP;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			ASW_UnexpectedValueUint16_t unexpectedValue;\n");
	fprintf(this->fhSource,"			unexpectedValue.expectedValue = expectedCrc;\n");
	fprintf(this->fhSource,"			unexpectedValue.foundValue = foundCrc;\n");
	fprintf(this->fhSource,"			memcpy((uint8_t*)failureInfo, &unexpectedValue, sizeof(unexpectedValue));\n");
	fprintf(this->fhSource,"			printf(\"Warning %sP_ValidatePacket CRC incorrect\\n\");\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	//if service and sub-service are recognized\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		//get packet ID\n");
	fprintf(this->fhSource,"		*packetId = PUS_GetServiceSubServiceCompound(packetRaw, totalLength);\n");
	fprintf(this->fhSource,"		//get Printer function\n");
	fprintf(this->fhSource,"		deserializer = %sD_GetDeserializerFunction(*packetId);\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		if (deserializer == NULL)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			isValid = M_FALSE;\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_ILLEGAL_P_TYPE;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			printf(\"Warning %sP_ValidatePacket service and/or subservice unknown \\n\");\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	//if specific packet type size is correct and parameters validated 1\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		//deserialize\n");
	fprintf(this->fhSource,"		isValid = deserializer(structuredData, outputNb, NULL, packetRaw, totalLength);\n");
	fprintf(this->fhSource,"		if (isValid)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			%s_UnexpectedValueUint16_t unexpectedValue;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			uint16_t packetDataLength=((CCSDS_Packet_t*)packetRaw)->primaryHeader.dataLength;\n");
	fprintf(this->fhSource,"			//swap size if needed because it is needed for next step\n");
	fprintf(this->fhSource,"			LEND_Network2Host((uint8_t*)&packetDataLength,sizeof(uint16_t));\n");
	fprintf(this->fhSource,"			uint16_t packetStatedTotalLength=CCSDS_PACKET_DATA_LENGTH_TO_TOTAL_LENGHT(packetDataLength);\n");
	fprintf(this->fhSource,"			unexpectedValue.foundValue = totalLength;\n");
	fprintf(this->fhSource,"			unexpectedValue.expectedValue = packetStatedTotalLength;\n");
	fprintf(this->fhSource,"			\n");
	fprintf(this->fhSource,"			if (unexpectedValue.foundValue != unexpectedValue.expectedValue)\n");
	fprintf(this->fhSource,"			{\n");
	fprintf(this->fhSource,"				isValid = M_FALSE;\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_LENGTH_DISCREP;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"				%s_UnexpectedValueUint16_t unexpectedValue;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"				memcpy((uint8_t*)failureInfo, &unexpectedValue, sizeof(unexpectedValue));\n");
	fprintf(this->fhSource,"				printf(\"Warning %sP_ValidatePacket inconsistent size found: %%d expected: %%d \\n\", unexpectedValue.foundValue, unexpectedValue.expectedValue);\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			}\n");
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"		else\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			printf(\"Deserialization error\\n\");\n");
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	//if specific packet type size is correct and parameters validated 2\n");
	fprintf(this->fhSource,"	if (isValid)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		//get Printer and validate\n");
	fprintf(this->fhSource,"		%sP_PrinterFunction_t *PrinterFunction = %s_GetPrinterFunction(*packetId);\n",interface->preffix.c_str(),interface->preffix.c_str());
	fprintf(this->fhSource,"		if (PrinterFunction != NULL)\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			isValid = PrinterFunction(structuredData, failureId, failureInfo, &parameterCounter);\n");
	fprintf(this->fhSource,"			if (isValid==M_FALSE)\n");
	fprintf(this->fhSource,"			{\n");
	fprintf(this->fhSource,"				printf(\"Validation error\\n\");\n");
	fprintf(this->fhSource,"			}\n");
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"		else\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			*failureId = %s_FID_ILLEGAL_P_TYPE;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			isValid = M_FALSE;\n");
	fprintf(this->fhSource,"			printf(\"Warning %sP_ValidatePacket Illegal Packet Type \\n\");\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	return isValid;\n");
	fprintf(this->fhSource,"}\n");


	//packets
	generatePrintersFunctions(this->fhSource,interface,false);

	fprintfLabel(this->fhSource,"local functions");

	//ASWV_PrinterFunction_t *ASW_GetPrinterFunction(uint16_t packetId)
	fprintf(this->fhSource,"%sP_PrinterFunction_t *ASW_GetPrinterFunction(uint16_t packetId)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"	%sP_PrinterFunction_t *Printer = NULL;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	for (uint16_t fIx = 0; fIx < %s_Printer_FUNCTION_NO; fIx++)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		if (packetId == %s_PrinterFunctionLut[fIx].packetId)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			Printer = %s_PrinterFunctionLut[fIx].Printer;\n",interface->preffix.c_str());
	fprintf(this->fhSource,"			break;\n");
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	return Printer;\n");
	fprintf(this->fhSource,"}\n\n");

	//bool_t ASWV_IsEnumerationValueValid(uint32_t *allowedValues, uint16_t allowedValuesNb, uint32_t value)
	fprintf(this->fhSource,"bool_t %sP_IsEnumerationValueValid(uint32_t *allowedValues, uint16_t allowedValuesNb, uint32_t value)\n",interface->preffix.c_str());
	fprintf(this->fhSource,"{\n");
	fprintf(this->fhSource,"	bool_t isFound = M_FALSE;\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	for (uint16_t aIx = 0; aIx < allowedValuesNb; aIx++)\n");
	fprintf(this->fhSource,"	{\n");
	fprintf(this->fhSource,"		if (value == allowedValues[aIx])\n");
	fprintf(this->fhSource,"		{\n");
	fprintf(this->fhSource,"			isFound = M_TRUE;\n");
	fprintf(this->fhSource,"		}\n");
	fprintf(this->fhSource,"	}\n");
	fprintf(this->fhSource,"	\n");
	fprintf(this->fhSource,"	return (isFound == M_TRUE);\n");
	fprintf(this->fhSource,"}\n\n");
	//structures
	generatePrintersStructuresFunctions(this->fhSource,interface,false);

}
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */

bool generateFieldPrinter(FILE *fh,CGDM_Field *thisField,CGDM_Interface *interface,std::string *multiplicityIndex,std::vector <CGDM_Field>  *brotherFields)
{
	bool toValidate=false;

	fprintf(fh,"	//%s\n",thisField->name.c_str());
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
		generateFieldPrinter(fh,&thisField2,interface,multiplicityIndex,brotherFields);
		fprintf(fh,"  }\n");
	}
	//variable
	else if (thisField->type=="variable")
	{
		fprintf(fh,"	if (isValid == M_TRUE)\n");
		fprintf(fh,"	{\n");
		CGDM_TypeEnum *thisEnum=NULL;
		CGDM_Field *fieldFrom=getFieldFromName(thisField->typeFromField,brotherFields);
		if (fieldFrom!=NULL) thisEnum=getEnumByName(fieldFrom->type,interface);
		if ((fieldFrom!=NULL)&&(thisEnum!=NULL))
		{
			for (auto & thisElement : thisEnum->elements)
			{
				if (thisElement.relatedType!="null")
				{
					fprintf(fh,"    	if (structuredData->%s == %s_%s)\n",thisField->typeFromField.c_str(),interface->preffix.c_str(),thisElement.label.c_str());
					fprintf(fh,"    	{\n");
					fprintf(fh,"      		isValid=%sP_%s((%s_%s_t*)&structuredData->%s, failureId, failureInfo, parameterCounter);\n",
							interface->preffix.c_str(),thisElement.relatedType.c_str(),interface->preffix.c_str(),thisElement.relatedType.c_str(),thisField->name.c_str());
					fprintf(fh,"    	}\n");
				}
			}
		}
		fprintf(fh,"	}\n");
		toValidate=true;
	}
	//user-code
	else if ((thisField->isStructure)||(thisField->isUserCode))
	{
		fprintf(fh,"	if (isValid == M_TRUE)\n");
		fprintf(fh,"	{\n");
		fprintf(fh,"		isValid = %sPU_Validate%s(&structuredData->%s, failureId, failureInfo, parameterCounter);\n",interface->preffix.c_str(),thisField->type.c_str(), thisField->name.c_str());
		fprintf(fh,"	}\n");
		toValidate=true;
	}
	//native
	else if (((thisField->isNative)||(thisField->isEnum))&&(thisField->hasMultiplicity==false))
	{
		if (thisField->isEnum)
		{
			fprintf(fh,"	if (isValid == M_TRUE)\n");
			fprintf(fh,"	{\n");
			fprintf(fh,"		isValid = %sP_IsEnumerationValueValid(%s_%s_AllowedValues, ASW_PAID_NB, structuredData->%s);\n",interface->preffix.c_str(),interface->preffix.c_str(),thisField->type.c_str(),thisField->name.c_str());
			fprintf(fh,"		*parameterCounter += 1;\n");
			fprintf(fh,"	}\n");
			toValidate=true;
		}
		else //native
		{
			if (thisField->hasRestriction)
			{
				fprintf(fh,"	if (isValid == M_TRUE)\n");
				fprintf(fh,"	{\n");
				if (thisField->restrictionFixedValue!="") fprintf(fh,"		if (structuredData->%s != %s)\n",thisField->name.c_str(),thisField->restrictionFixedValue.c_str());
				if (thisField->restrictionMaxExclusive!="") fprintf(fh,"		if (structuredData->%s > %s)\n",thisField->name.c_str(),thisField->restrictionMaxExclusive.c_str());
				if (thisField->restrictionMinExclusive!="") fprintf(fh,"		if (structuredData->%s < %s)\n",thisField->name.c_str(),thisField->restrictionMinExclusive.c_str());
				if (thisField->restrictionMaxInclusive!="") fprintf(fh,"		if (structuredData->%s >= %s)\n",thisField->name.c_str(),thisField->restrictionMaxInclusive.c_str());
				if (thisField->restrictionMinInclusive!="") fprintf(fh,"		if (structuredData->%s <= %s)\n",thisField->name.c_str(),thisField->restrictionMinInclusive.c_str());
				fprintf(fh,"		{\n");
				fprintf(fh,"			isValid = M_FALSE;\n");
				fprintf(fh,"			*failureId = ASW_FID_INVALID_PARAMETER_VALUE;\n");
				fprintf(fh,"		}\n");
				fprintf(fh,"		*parameterCounter += 1;\n");
				fprintf(fh,"	}\n");
				toValidate=true;
			}

		}
	}
	else
	{
		printf("\t\t error: unnacounted field\n");
	}
	if (toValidate==false)
	{
		fprintf(fh,"	//n/a\n");
	}
	fprintf(fh,"\n");

	return toValidate;
}

void generateEnumeraionFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	fprintf(fh,"//enumeration\n");
	for (auto & thisEnumeration : interface->typeEnums)
	{
		if (isJustPrototype)
		{
			fprintf(fh,"void %sP_Print%s(uint8_t *target, %s_%s_t enumeration)",interface->preffix.c_str(),thisEnumeration.name.c_str(),interface->preffix.c_str(),thisEnumeration.name.c_str());
			fprintf(fh,";\n");
		}
		else
		{
			//TODO
		}
	}

}

void generatePrintersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{

	for (auto & thisPacket : interface->packets)
	{


		if (isJustPrototype)
		{
			fprintf(fh,"void %sP_Print%s(%s_%s_t *structureData)",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"bool_t %sPU_Validate%s(void *input, uint16_t *failureId, uint8_t *failureInfo, uint16_t *parameterCounter)\n",interface->preffix.c_str(),thisPacket.name.c_str());
			fprintf(fh,"{\n");
			fprintf(fh,"	bool_t isValid = M_TRUE;\n");
			fprintf(fh,"	*failureId = ASW_FID_OK;\n");
			fprintf(fh,"\n");
			fprintf(fh,"	%s_%s_t *structuredData = (%s_%s_t *)input;\n\n",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
			bool toValidate=false;
			for (auto & thisField : thisPacket.fields)
			{
				std::string multiplicityIndex="";
				toValidate|=generateFieldPrinter(fh,&thisField,interface,&multiplicityIndex,&thisPacket.fields);
			}
			if (toValidate==false)
			{
				fprintf(fh,"	//no fields to validate\n\n");
			}
			fprintf(fh,"	return isValid;\n");
			fprintf(fh,"}\n");
		}
	}
}

void generatePrintersStructuresFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{
	for (auto & thisStructure : interface->typeStructures)
	{

		if (isJustPrototype)
		{
			fprintf(fh,"%sP_PrinterFunction_t %sP_%s",interface->preffix.c_str(),interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,";\n");
		}
		else
		{
			fprintf(fh,"bool_t %sP_%s(void *input, uint16_t *failureId, uint8_t *failureInfo, uint16_t *parameterCounter)\n",interface->preffix.c_str(),thisStructure.name.c_str());
			fprintf(fh,"\n{\n");
			fprintf(fh,"	bool_t isValid = M_TRUE;\n");
			fprintf(fh,"	*failureId = ASW_FID_OK;\n");
			fprintf(fh,"\n");
			fprintf(fh,"	%s_%s_t *structuredData = (%s_%s_t *)input;\n\n",interface->preffix.c_str(),thisStructure.name.c_str(),interface->preffix.c_str(),thisStructure.name.c_str());
			bool toValidate=false;
			for (auto & thisField : thisStructure.fields)
			{
				std::string multiplicityIndex="";
				toValidate|=generateFieldPrinter(fh,&thisField,interface,&multiplicityIndex,&thisStructure.fields);
			}
			if (toValidate==false)
			{
				fprintf(fh,"	//no fields to validate\n\n");
			}
			fprintf(fh,"	return isValid;\n");
			fprintf(fh,"}\n");
		}
	}
}
