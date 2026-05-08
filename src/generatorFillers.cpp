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


void copyReadDataToDataModel(X_Document *doc);


int main(int argc, char *argv[]) {
	cout << "!!!Generator Fillers!!!" << endl; // prints !!!Hello World!!!

	X_Document doc;
	X_DocumentReader reader;
	string fileName="./models/appSw.xml";
	string outputFolder=".";
	bool isValid=true;

	if (argc!=3)
	{
		printf("Warning: usage: executableName inputFile.xml outputFolder, using default file\n");
	}
	else
	{
		fileName=argv[1];
		fileName=argv[2];
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
		isValid=false;
	}

	//doc.print();

	//now actually read
	CGDM_Interface interface;
	interface.importDefinitionFromXmlDoc(&doc);
	interface.print();

	//generate
	//TODO

	printf("\nEND\n");
	return 0;
}
//TODO remove
void copyReadDataToDataModel(X_Document *doc)
{
	//get master node employeeData
	if (doc->nodes.size()>0)
	{
		X_Node *employeeData=&doc->nodes.at(0);
		//get all sub nodes
		for (auto & thisNode : employeeData->nodes)
		{
			//verify that node name is expected
			if (thisNode.name=="employee")
			{
				std::string employeeName=thisNode.getContentOfSubNode("name");
				std::string employeeAddress=thisNode.getContentOfSubNode("address");
				std::string employeeType=thisNode.getContentOfAttribute("type");
				std::string employeeHiring=thisNode.getContentOfAttribute("hiring");
				//do something with the data:
				//note, in this example, the data is just print out
				printf("employee data:\n");
				printf("\tname: %s\n",employeeName.c_str());
				printf("\taddress: %s\n",employeeAddress.c_str());
				printf("\ttype: %s\n",employeeType.c_str());
				printf("\thiring: %s\n",employeeHiring.c_str());
			}
		}
	}
	else
	{
		printf("ERROR: printReadData: read document contains no master node\n");
	}
	printf("note: last node is expected empty\n");
}
