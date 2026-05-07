/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _CGDM_Field_
#define _CGDM_Field_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
/* none */

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class CGDM_Field {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::string type;
	bool isNative;
	bool isEnum;
	bool isUserCode;
	bool isStructure;
	std::string enumBaseType;
	bool hasMultiplicity;
	std::string multiplicityFromField;
    bool hasRestriction;
    //TODO restrictions

    /* Methods ******************************************************/
    CGDM_Field();
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
