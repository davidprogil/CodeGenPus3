/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGFG_PrintersGenerator_
#define _CGFG_PrintersGenerator_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
#include "CGDM_Interface.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGPG_PrintersGenerator {       // The class
  public:
    /* Attributes ******************************************************/
    FILE *fhHeader;
    FILE *fhSource;
    std::string preffix;
    /* Methods ******************************************************/
    CGPG_PrintersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p);
    void GenerateHeader(CGDM_Interface *interface);
    void GenerateSource(CGDM_Interface *interface);


  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
