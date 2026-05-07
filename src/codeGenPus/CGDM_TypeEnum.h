/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_TypeEnum_
#define _CGDM_TypeEnum_

/* System Includes ***********************************************************/
#include <string>
#include <vector>

/* Application Includes ******************************************************/
#include "CGDM_TypeEnumElement.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_TypeEnum {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::string baseType;

    std::vector <CGDM_TypeEnumElement> elements;
    /* Methods ******************************************************/
    CGDM_TypeEnum();
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
