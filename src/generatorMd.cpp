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
#include "codeGenPus/CGMG_MdGenerator.h"

int main(int argc, char *argv[]) {
	cout << "!!!Generator MD!!!" << endl; // prints !!!Hello World!!!

	X_Document doc;
	X_DocumentReader reader;
	string fileName="./models/appSw.xml";
	string abbreviation="ASW";
	string templateFileName="";
	string outputFileName=".";
	string userTypesFileName=".";
	bool isValid=true;

	if (argc!=6)
	{
		printf("Error: usage: executableName inputFile.xml template.md user-types.md abbreviation outputFolder\n");
		return -1;
	}
	else
	{
		fileName=argv[1];
		templateFileName=argv[2];
		userTypesFileName=argv[3];
		abbreviation=argv[4];
		outputFileName=argv[5];
	}

	//load model
	FILE *fh=fopen(fileName.c_str(),"r");
	if (fh!=NULL)
	{
		printf("reading model... \n");
		reader.Read(fh,&doc);
		fclose(fh);
	}
	else
	{
		printf("ERROR: main: could not open input file %s\n",fileName.c_str());
		isValid=false;
	}

	//load template
	FILE *fhTemplate=fopen(templateFileName.c_str(),"r");
	if (fhTemplate!=NULL)
	{
		printf("reading template... \n");
	}
	else
	{
		printf("ERROR: main: could not open input file %s\n",templateFileName.c_str());
		isValid=false;
	}

	//load userTypesFileName
	FILE *fhUserTpes=fopen(userTypesFileName.c_str(),"r");
	if (fhUserTpes!=NULL)
	{
		printf("reading user types... \n");
	}
	else
	{
		printf("ERROR: main: could not open input file %s\n",userTypesFileName.c_str());
		isValid=false;
	}

	if (isValid)
	{
		//now actually read
		printf("processing... \n");
		CGDM_Interface interface;
		interface.importDefinitionFromXmlDoc(&doc);
		//interface.print();

		//generate
		FILE *outputFh=fopen(outputFileName.c_str(),"w");

		if (outputFh==NULL)
		{
			printf("ERROR: main: could not open input file %s\n",outputFileName.c_str());
			isValid=false;
		}


		if (isValid)
		{
			CGMG_MdGenerator mdGenerator(outputFh,fhTemplate,fhUserTpes,abbreviation);
			printf("generating header... \n");
			mdGenerator.GenerateMd(&interface);
		}

		if (outputFh!=NULL) fclose(outputFh);
		if (fhTemplate!=NULL) fclose(fhTemplate);
		if (fhUserTpes!=NULL) fclose(fhUserTpes);


	}

	printf("\nEND\n");
	return 0;
}

