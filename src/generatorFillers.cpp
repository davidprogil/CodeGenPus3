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
#include "./codeGenPus/CGFG_FillersGenerator.h"

int main(int argc, char *argv[]) {
	cout << "!!!Generator Fillers!!!" << endl; // prints !!!Hello World!!!

	X_Document doc;
	X_DocumentReader reader;
	string fileName="./models/appSw.xml";
	string abbreviation="ASW";
	string outputFolder=".";
	bool isValid=true;

	if (argc!=3)
	{
		printf("Warning: usage: executableName inputFile.xml abbreviation outputFolder, using default file\n");
	}
	else
	{
		fileName=argv[1];
		abbreviation=argv[2];
		outputFolder=argv[3];
	}

	FILE *fh=fopen(fileName.c_str(),"r");
	if (fh!=NULL)
	{
		printf("reading... \n");
		reader.Read(fh,&doc);
		fclose(fh);
	}
	else
	{
		printf("ERROR: main: could not open input file %s\n",fileName.c_str());
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
		std::string headerFilename = outputFolder + "/" + abbreviation + "_Fillers.h";
		std::string sourceFilename = outputFolder + "/" + "Fillers.c";
		FILE *headerFh=fopen(headerFilename.c_str(),"w");
		FILE *sourceFh=fopen(sourceFilename.c_str(),"w");

		if (headerFh==NULL)
		{
			printf("ERROR: main: could not open input file %s\n",headerFilename.c_str());
			isValid=false;
		}

		if (sourceFh==NULL)
		{
			printf("ERROR: main: could not open input file %s\n",sourceFilename.c_str());
			isValid=false;
		}


		if (isValid)
		{
			CGFG_FillersGenerator fillersGenerator(headerFh,sourceFh,abbreviation);
			printf("generating header... \n");
			fillersGenerator.GenerateHeader(&interface);
			printf("generating source... \n");
			fillersGenerator.GenerateSource(&interface);
		}

		if (headerFh!=NULL) fclose(headerFh);
		if (sourceFh!=NULL) fclose(sourceFh);

	}

	printf("\nEND\n");
	return 0;
}

