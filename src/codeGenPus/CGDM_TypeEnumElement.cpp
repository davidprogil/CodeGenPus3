/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_TypeEnumElement.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_TypeEnumElement::CGDM_TypeEnumElement()
{ // Constructor
    //std::cout << "Hello CGDM_TypeEnumElement x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void CGDM_TypeEnumElement::print()
{
    //std::cout << "  CGDM_TypeEnumElement: " << std::endl;
    std::cout << "   label: " << this->label << " value: " << this->value <<" relatedType: " << this->relatedType  << std::endl;
}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
