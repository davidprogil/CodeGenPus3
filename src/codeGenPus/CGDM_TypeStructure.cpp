/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_TypeStructure.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_TypeStructure::CGDM_TypeStructure()
{ // Constructor
    //std::cout << "Hello CGDM_TypeStructure x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void CGDM_TypeStructure::print()
{
    std::cout << " CGDM_TypeStructure: name: " << this->name << std::endl;
	//TODO std::string name;
	//TODO std::vector <CGDM_Field> fields;
    for (auto& obj : this->fields) obj.print();
}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
