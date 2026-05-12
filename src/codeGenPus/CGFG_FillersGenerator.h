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
void fprintfCopyright(FILE *fh);
void fprintfLabel(FILE *fh,std::string label);
void fprintfSystemIncldudes(FILE *fh);
std::string stringToUpperString(std::string in);
/* Public Types ******************************************************/
class CGFG_FillersGenerator {       // The class
  public:
    /* Attributes ******************************************************/
    FILE *fhHeader;
    FILE *fhSource;
    std::string preffix;
    /* Methods ******************************************************/
    CGFG_FillersGenerator(FILE *fhHeader_p,FILE *fhSource_p,std::string preffix_p);
    void GenerateHeader(CGDM_Interface *interface);
    void GenerateSource(CGDM_Interface *interface);


  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
