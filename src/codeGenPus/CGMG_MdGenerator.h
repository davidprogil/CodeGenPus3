/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGMG_MdGenerator_
#define _CGMG_MdGenerator_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
#include "CGDM_Interface.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGMG_MdGenerator {       // The class
  public:
    /* Attributes ******************************************************/
    FILE *fhMd;
    FILE *fhTemplate;
    std::string preffix;
    /* Methods ******************************************************/
    CGMG_MdGenerator(FILE *fhMd_p,FILE *fhTemplate_p,std::string preffix_p);
    void GenerateMd(CGDM_Interface *interface);



  private:
    /* Attributes ******************************************************/
    void GenerateTemplate(CGDM_Interface *interface);
    void GeneratePackets(CGDM_Interface *interface);
    void GenerateEnums(CGDM_Interface *interface);
    void GenerateStructures(CGDM_Interface *interface);
    void GenerateField(CGDM_Interface *interface,CGDM_Field *thisField);

    /* Methods ******************************************************/
    /* none */
};

#endif
