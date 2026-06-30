/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_Field.h"

/* Application Includes ******************************************************/

/* Public Methods  ***********************************************************/
CGDM_Field::CGDM_Field()
{ // Constructor
	//std::cout << "Hello CGDM_Field x" << std::endl;
	//this->name=name;
	//this->content=description;
	this->hasRestriction=false;
	this->restrictionMaxInclusive="s";
}

void CGDM_Field::print()
{
	std::cout << "  CGDM_Field: name: " << this->name << " type: " << this->type;
	if (this->isNative) std::cout << " " << "(N)";
	if (this->isEnum) std::cout << " " << "(E)";
	if (this->isUserCode) std::cout << " " << "(U)";
	if (this->isStructure) std::cout << " " << "(S)";
	if (this->hasMultiplicity) std::cout << " " << "(M)";
	if (this->hasRestriction) std::cout << " " << "(R)";
	if (this->isEnum)
	{
		std::cout << " BaseType: " << this->enumBaseType;
	}
	if (this->hasMultiplicity)
	{
		std::cout << " MultiplicityFrom: " << this->multiplicityFromField;
	}
	std::cout << std::endl;
	//TODO std::string enumBaseType;
	//TODO bool hasMultiplicity;
	//TODO std::string multiplicityFromField;

	if (this->type=="variable")
	{
		std::cout << "   typeFromField: " << this->typeFromField << std::endl;
	}

	if (this->hasRestriction)
	{
		//std::string restrictionFixedValue;
		if (this->restrictionFixedValue!="") std::cout << "   Fixed Value: " << this->restrictionFixedValue << std::endl;
		//std::string restrictionMaxInclusive;
		if (this->restrictionMaxInclusive!="") std::cout << "   Max Inclusive: " << this->restrictionMaxInclusive << std::endl;
		//std::string restrictionMaxExclusive;
		if (this->restrictionMaxExclusive!="") std::cout << "   Max Exclusive: " << this->restrictionMaxExclusive << std::endl;
		//std::string restrictionMinExclusive;
		if (this->restrictionMinExclusive!="") std::cout << "   Min Exclusive: " << this->restrictionMinExclusive << std::endl;
		//std::string restrictionMinInclusive;
		if (this->restrictionMinInclusive!="") std::cout << "   Min Inclusive: " << this->restrictionMinInclusive << std::endl;
	}

}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
