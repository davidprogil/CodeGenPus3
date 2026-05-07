/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_Packet.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_Packet::CGDM_Packet()
{ // Constructor
    //std::cout << "Hello CGDM_Packet x" << std::endl;
    //this->name=name;
    //this->content=description;
}

void CGDM_Packet::print()
{
    std::cout << "CGDM_Packet: name: " << this->name << " ID: " << this->id << std::endl;
    //std::cout << " " << this->name << "=" << this->content;
	//TODO std::string description;
	//TODO bool isCommand;
	//TODO bool isToGenerate;

    //TODO order structures, fields
	//TODO std::vector <CGDM_TypeStructure> sructures;
	//TODO std::vector <CGDM_Field> fields;
    for (auto& obj : this->fields) obj.print();
	//TODO std::vector <char> elementTypeMap;


}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
