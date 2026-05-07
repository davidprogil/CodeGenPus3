/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include "X_Document.h"

#include <iostream>

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
X_Document::X_Document()
{ // Constructor
    std::cout << "Hello X_Document x" << std::endl;
}

void X_Document::print()
{
    std::cout << "X_Document: " << std::endl;
    for (auto & element : this->nodes) {
        element.print(0);
    }
}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
