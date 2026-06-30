/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include <algorithm>



/* Application Includes ******************************************************/
#include "CGVG_ValidatorsGenerator.h"
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
CGVG_ValidatorsGenerator::CGVG_ValidatorsGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p)
{ // Constructor
	this->fhHeader=fhHeader_p;
	this->fhSource=fhSource_p;
	this->preffix=preffix_p;
}

void CGVG_ValidatorsGenerator::GenerateHeader(CGDM_Interface *interface)
{

}

void CGVG_ValidatorsGenerator::GenerateSource(CGDM_Interface *interface)
{

}
/* Public Functions ******************************************************/
/* none */


/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
