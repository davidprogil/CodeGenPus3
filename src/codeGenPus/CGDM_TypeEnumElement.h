/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_TypeEnumElement_
#define _CGDM_TypeEnumElement_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
/* none */

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_TypeEnumElement {       // The class
  public:
    /* Attributes ******************************************************/
    std::string label;
    int value;
    std::string relatedType;

    /* Methods ******************************************************/
    CGDM_TypeEnumElement();
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
