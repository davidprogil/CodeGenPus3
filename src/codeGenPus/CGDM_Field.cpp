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
    std::cout << "  CGDM_Field: name: " << this->name << " type: " << this->type;
    if (this->isNative) std::cout << " " << "(N)";
    if (this->isEnum) std::cout << " " << "(E)";
    if (this->isUserCode) std::cout << " " << "(U)";
    if (this->isStructure) std::cout << " " << "(S)";
    if (this->hasMultiplicity) std::cout << " " << "(M)";
    if (this->isEnum)
    {
    	std::cout << " BaseType: " << this->enumBaseType;
    }
    if (this->hasMultiplicity)
    {
    	std::cout << " MultiplicityFrom: " << this->multiplicityFromField;
    }
    std::cout << std::endl;
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
