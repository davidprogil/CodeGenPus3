/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_Interface_
#define _CGDM_Interface_

/* System Includes ***********************************************************/
#include <string>
#include <vector>

/* Application Includes ******************************************************/
#include "../dgXmlLib/X_Document.h"

#include "CGDM_TypeEnum.h"
#include "CGDM_TypeStructure.h"
#include "CGDM_Packet.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_Interface {       // The class
  public:
    /* Attributes ******************************************************/
    std::string description;

    std::vector <CGDM_TypeEnum> typeEnums;
    std::vector <CGDM_TypeStructure> typeStructures;
    std::vector <CGDM_Packet> packets;

    /* Methods ******************************************************/
    CGDM_Interface();
    void importDefinitionFromXmlDoc(X_Document *doc);
    void print();
    void findBaseTypeOfEnum(CGDM_Field *target,std::string EnumType);

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    void importTypesFromXmlDoc(X_Node *types);
    void importPacketsFromXmlDoc(X_Node *packets);
    void importFieldsFromXmlDoc(std::vector <CGDM_Field>  *fields,X_Node *thisEnumX);

};

#endif
