/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_Packet_
#define _CGDM_Packet_

/* System Includes ***********************************************************/
#include <string>
#include <vector>

/* Application Includes ******************************************************/
#include "CGDM_TypeStructure.h"
#include "CGDM_Field.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_Packet {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::string description;
    std::string id;
    bool isCommand;
    bool isToGenerate;

    std::vector <CGDM_TypeStructure> sructures;
    std::vector <CGDM_Field> fields;
    std::vector <char> elementTypeMap;

    /* Methods ******************************************************/
    CGDM_Packet();
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
