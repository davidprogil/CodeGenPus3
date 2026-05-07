/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_Field.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_Field::CGDM_Field()
{ // Constructor
    //std::cout << "Hello CGDM_Field x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void CGDM_Field::print()
{
    std::cout << "  CGDM_Field: name: " << this->name << " type: " << this->type << std::endl;
    //TODO bool isNative;
    //TODO bool isEnum;
    //TODO bool isUserCode
    //TODO bool isStructure
    //TODO std::string enumBaseType;
    //TODO bool hasMultiplicity;
    //TODO std::string multiplicityFromField;
    //TODO bool hasRestriction;
    //TODO restrictions

}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
