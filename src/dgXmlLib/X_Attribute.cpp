/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include "X_Attribute.h"

#include <iostream>

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
X_Attribute::X_Attribute()
{ // Constructor
    //std::cout << "Hello X_Attribute x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void X_Attribute::print()
{
    //std::cout << "X_Attribute: " << std::endl;
    std::cout << " " << this->name << "=" << this->content;


}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
