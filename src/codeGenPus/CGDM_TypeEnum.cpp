/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_TypeEnum.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_TypeEnum::CGDM_TypeEnum()
{ // Constructor
    //std::cout << "Hello CGDM_TypeEnum x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void CGDM_TypeEnum::print()
{
    std::cout << " CGDM_TypeEnum: " ;
    std::cout << "  name: " << this->name;
	std::cout << "  baseType: " << this->baseType << std::endl;
	for (auto& obj : this->elements) obj.print();

}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
