/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _X_Node_
#define _X_Node_

/* System Includes ***********************************************************/
#include <string>
#include <vector>

/* Application Includes ******************************************************/
#include "X_Attribute.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class X_Node {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::vector <X_Node> nodes;
    std::vector <X_Attribute> attributes;
    std::string content;

    /* Methods ******************************************************/
    X_Node(std::string name_p);
    std::string getContentOfSubNode(std::string subNodeName);
    std::string getContentOfAttribute(std::string atttributeName);
    void print(int ident);

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
