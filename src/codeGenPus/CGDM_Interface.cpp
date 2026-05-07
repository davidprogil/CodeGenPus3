/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>
#include "CGDM_Interface.h"

/* Application Includes ******************************************************/

/* Private prototypes ********************************************************/
void importFieldsFromXmlDoc(std::vector <CGDM_Field>  *fields,X_Node *thisEnumX);

/* Public Methods  ***********************************************************/
CGDM_Interface::CGDM_Interface()
{ // Constructor
	//std::cout << "Hello CGDM_Interface x" << std::endl;
	//this->name=name;
	//this->content=description;
}

void CGDM_Interface::importDefinitionFromXmlDoc(X_Document *doc)
{
	//get master node employeeData
	if (doc->nodes.size()>0)
	{
		X_Node *interface=&doc->nodes.at(0);
		//get all sub nodes
		for (auto & thisNode : interface->nodes)
		{
			if (thisNode.name=="description")
			{
				//printf("debug importDefinitionFromXmlDoc found description\n");
				this->description=thisNode.content;
			}
			else if (thisNode.name=="types")
			{
				printf("debug importDefinitionFromXmlDoc found types\n");
				this->importTypesFromXmlDoc(&thisNode);
			}
			else if (thisNode.name=="packets")
			{
				printf("debug importDefinitionFromXmlDoc found packets\n");
				this->importPacketsFromXmlDoc(&thisNode);
			}
		}
	}
}

void CGDM_Interface::print()
{
	std::cout << "CGDM_Interface: " << std::endl;
	std::cout << "  description: "<< this->description << std::endl;

	for (auto& obj : this->typeEnums) obj.print();
	for (auto& obj : this->typeStructures) obj.print();
	for (auto& obj : this->packets) obj.print();

}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
void importEnumTypesElementsFromXmlDoc(CGDM_TypeEnum *thisEnum,X_Node *thisEnumX)
{
	if (thisEnumX->nodes.size()>0)
	{
		for (auto & thisNode : thisEnumX->nodes)
		{
			if (thisNode.name=="enumElement")
			{
				//printf("debug importDefinitionFromXmlDoc found enumElement %s .\n",thisNode.getContentOfAttribute("label").c_str());
				CGDM_TypeEnumElement thisElement;
				thisElement.label=thisNode.getContentOfAttribute("label");
				thisElement.value=std::stoi(thisNode.getContentOfAttribute("value"));
				thisElement.relatedType=thisNode.getContentOfAttribute("type");
				thisEnum->elements.push_back(thisElement);
			}
		}
	}
}


void CGDM_Interface::importPacketsFromXmlDoc(X_Node *packets)
{
	if (packets->nodes.size()>0)
	{
		for (auto & thisNode : packets->nodes)
		{
			if (thisNode.name=="packet")
			{
				CGDM_Packet thisPacket;
				thisPacket.name=thisNode.getContentOfAttribute("name");
				thisPacket.id=thisNode.getContentOfAttribute("id");
				//TODO structures
				importFieldsFromXmlDoc(&thisPacket.fields,&thisNode);
				this->packets.push_back(thisPacket);
			}
		}
	}
}
void CGDM_Interface::importTypesFromXmlDoc(X_Node *types)
{
	if (types->nodes.size()>0)
	{
		for (auto & thisNode : types->nodes)
		{
			if (thisNode.name=="enum")
			{
				CGDM_TypeEnum thisEnum;
				//printf("debug importDefinitionFromXmlDoc found enum %s .\n",thisNode.getContentOfAttribute("name").c_str());
				thisEnum.name=thisNode.getContentOfAttribute("name");
				thisEnum.baseType=thisNode.getContentOfAttribute("baseType");
				importEnumTypesElementsFromXmlDoc(&thisEnum,&thisNode);
				this->typeEnums.push_back(thisEnum);
			}
			else if (thisNode.name=="structureField")
			{
				CGDM_TypeStructure thisStructure;
				printf("debug importDefinitionFromXmlDoc found structureField %s\n",thisNode.getContentOfAttribute("name").c_str());
				thisStructure.name=thisNode.getContentOfAttribute("name");
				importFieldsFromXmlDoc(&thisStructure.fields,&thisNode);
				this->typeStructures.push_back(thisStructure);
			}
		}
	}
}

/* Private Functions ******************************************************/
void importFieldsFromXmlDoc(std::vector <CGDM_Field>  *fields,X_Node *thisEnumX)
{
	if (thisEnumX->nodes.size()>0)
	{
		for (auto & thisNode : thisEnumX->nodes)
		{
			if (thisNode.name=="field")
			{
				CGDM_Field thisField;
				thisField.name=thisNode.getContentOfAttribute("name");
				thisField.type=thisNode.getContentOfAttribute("type");
				thisField.isStructure=false;
				//TODO loads of things missing reading
				fields->push_back(thisField);
			}
			else if (thisNode.name=="structureField")
			{
				CGDM_Field thisField;
				printf("debug reading %s %s\n",thisNode.getContentOfAttribute("name").c_str(),thisNode.getContentOfAttribute("isUserCode").c_str());
				thisField.name=thisNode.getContentOfAttribute("name");
				thisField.type=thisNode.getContentOfAttribute("type");
				if (thisNode.getContentOfAttribute("isUserCode")=="true")
					thisField.isUserCode=true;
				else
					thisField.isUserCode=false;
				thisField.isStructure=true;

				fields->push_back(thisField);
			}
		}
	}
}

