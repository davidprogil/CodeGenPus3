/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>



/* Application Includes ******************************************************/
#include "CGFG_SerializersGenerator.h"
#include "CGFG_FillersGenerator.h"

//from CGFG_FillersGenerator
void fprintfCopyright(FILE *fh);
void fprintfLabel(FILE *fh,std::string label);
void fprintfSystemIncldudes(FILE *fh);
std::string stringToUpperString(std::string in);
//eof from CGFG_FillersGenerator


//privates
void generateSerializersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype);

/* Public Methods  ***********************************************************/
CGFG_SerializersGenerator::CGFG_SerializersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGFG_SerializersGenerator::GenerateHeader(CGDM_Interface *interface)
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
	fprintf(this->fhHeader,"#include <%s_SerializersUser.h>\n",this->preffix.c_str());
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
	generateSerializersFunctions(this->fhHeader,interface,true);
	fprintf(this->fhHeader,"\n");
	//end if
	fprintf(this->fhHeader,"#endif\n");
}

void CGFG_SerializersGenerator::GenerateSource(CGDM_Interface *interface)
{
	printf("\tcopyright...\n");
	interface->preffix=this->preffix;
	fprintfCopyright(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfSystemIncldudes(this->fhSource);
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"component includes");
	fprintf(this->fhSource,"#include <%s_FillersUser.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"#include <%s_Fillers.h>\n",interface->preffix.c_str());
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"local macros");
	fprintf(this->fhSource,"/* none */\n");
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
	fprintf(this->fhSource,"/* none */\n");
	fprintf(this->fhSource,"\n");
	fprintfLabel(this->fhSource,"public functions");
	//fillers
	printf("\tfillers packets... %ld\n",interface->packets.size());
	//WriteFunctionSignature(FILE *fh,CGDM_Packet *packet,CGDM_Interface *interface)
	for (auto & thisPacket : interface->packets)
	{
		//TODO

	}
	//sizers

}
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
void generateSerializersFunctions(FILE *fh,CGDM_Interface *interface,bool isJustPrototype)
{

	for (auto & thisPacket : interface->packets)
	{
		fprintf(fh,"bool_t %sS_Serialize%s(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, %s_%s_t *structuredData)",interface->preffix.c_str(),thisPacket.name.c_str(),interface->preffix.c_str(),thisPacket.name.c_str());
		if (isJustPrototype)
		{
			fprintf(fh,";\n");
		}
		else
		{
			//TODO
			fprintf(fh,"\n");
		}
	}
}
