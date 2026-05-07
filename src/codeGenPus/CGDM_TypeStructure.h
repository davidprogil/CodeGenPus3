/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_TypeStructure_
#define _CGDM_TypeStructure_

/* System Includes ***********************************************************/
#include <string>
#include <vector>

/* Application Includes ******************************************************/
#include "CGDM_Field.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_TypeStructure {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::vector <CGDM_Field> fields;

    /* Methods ******************************************************/
    CGDM_TypeStructure();
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
