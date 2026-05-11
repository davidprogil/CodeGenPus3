//============================================================================
// Name        : dgXmlLib.cpp
// Author      : David Gil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Structure:
 * - Document
 * - Node
 * - Attributes
 *
 */

#include <iostream>
using namespace std;
#include "./dgXmlLib/X_DocumentReader.h"
#include "./codeGenPus/CGDM_Interface.h"


int main(int argc, char *argv[]) {
	cout << "!!!Reader!!!" << endl; // prints !!!Hello World!!!

	X_Document doc;
	X_DocumentReader reader;
	string fileName="./models/appSw.xml";

	if (argc!=2)
	{
		printf("Warning: usage: executableName inputFile.xml, using default file\n");
	}
	else
	{
		fileName=argv[1];
	}


	FILE *fh=fopen(fileName.c_str(),"r");
	if (fh!=NULL)
	{
		reader.Read(fh,&doc);
		fclose(fh);
	}
	else
	{
		printf("ERROR: main: could not open input file\n");
	}

	//doc.print();

	//now actually read
	CGDM_Interface interface;
	interface.importDefinitionFromXmlDoc(&doc);
	interface.print();

	printf("\nEND\n");
	return 0;
}

