/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/
#ifndef _X_DocumentReader_
#define _X_DocumentReader_

/* System Includes ***********************************************************/
#include <string>

/* Application Includes ******************************************************/
#include "X_Document.h"

/* Public Functions ******************************************************/
/* none */

/* Public Types ******************************************************/
class X_DocumentReader {       // The class
  public:
    /* Attributes ******************************************************/
    std::string name;
    std::string description;

    /* Methods ******************************************************/
    X_DocumentReader();
    void Read(FILE *fh,X_Document *doc);
    bool ReadNode(FILE *fh,X_Document *doc,std::string *tag,X_Node *parent);
    void print();

  private:
    /* Attributes ******************************************************/
    /* none */

    /* Methods ******************************************************/
    /* none */
};

#endif
