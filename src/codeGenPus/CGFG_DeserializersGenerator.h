/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGFG_FillersGenerator_
#define _CGFG_FillersGenerator_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
#include "CGDM_Interface.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGFG_DeserializersGenerator {       // The class
  public:
    /* Attributes ******************************************************/
    FILE *fhHeader;
    FILE *fhSource;
    std::string preffix;
    /* Methods ******************************************************/
    CGFG_DeserializersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p);
    void GenerateHeader(CGDM_Interface *interface);
    void GenerateSource(CGDM_Interface *interface);


  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
