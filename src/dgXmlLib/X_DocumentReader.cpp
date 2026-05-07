/*****************************************************************************/
/* Copyright Tawazun 2023 */
/* Project: Interface Tool */
/* Author: David Gil */
/*****************************************************************************/

/* System Includes ***********************************************************/
#include <iostream>

/* Application Includes ******************************************************/
#include "X_DocumentReader.h"

/* Public Methods  ***********************************************************/
X_DocumentReader::X_DocumentReader()
{ // Constructor
	std::cout << "Hello X_DocumentReader x" << std::endl;

}

void X_DocumentReader::print()
{
	std::cout << "X_DocumentReader: " << std::endl;


}

//todo prototype
//todo right place
bool readToChar(char ender,FILE *fh,std::string *tag)
{
	char c=0;
	while ((c!=ender)&&(c!=EOF))
	{
		c=getc(fh);
		if (tag!=NULL)
		{
			//printf("%c",c);
			*tag+=c;
		}
	}
	return ((c==EOF)?true:false);
}
bool readTagToTag(FILE *fh,std::string *tag)
{
	bool isEof=false;
	//advance
	//isEof=readToChar('<',fh,NULL);
	//read tag
	if (isEof!=true)
	{
		*tag+='<';
		isEof=readToChar('>',fh,tag);
	}

	//printf("%s\n",tag->c_str());

	return isEof;
}

bool readContent(FILE *fh,std::string *content,char firstChar)
{
	bool isEof=false;
	//*content+=firstChar;

	char c=firstChar;
	while ((c!='<')&&(c!=EOF))
	{

		if (content!=NULL)
		{
			//printf("%c",c);
			*content+=c;
		}
		c=getc(fh);
	}
	return ((c==EOF)?true:false);

	return isEof;
}
//todo prototype
//todo right place
bool isTagValid(std::string *tag)
{
	bool isValid=true;


	//if too small then invalid
	if (tag->length()<3) isValid=false;
	else
	{
		//if second later is ? then invalid
		if (tag->substr(1,1)=="?") isValid=false;
	}


	return isValid;
}

//todo prototype
//todo right place
void getNodeName(std::string *tag,std::string *name)
{
	//std::string name;
	name->clear();
	int cIx=0;
	for(std::string::iterator it = tag->begin(); it != tag->end(); ++it) {
		if (cIx>0)
		{
			if ((*it!='>')&&(*it!=' '))
			{
				//clear namespace
				if (*it==':')
				{
					name->clear();
				}
				else
				{
					(*name)+=*it;
				}
			}
			else
			{
				break;
			}
		}
		cIx++;
	}
	//printf("%s\n",name->c_str());
}
//todo prototype
//todo right place
bool isEmptyNode(std::string *tag)
{
	return (tag->substr(tag->length()-2,1)=="/");
}


//todo prototype
//todo right place
bool readAdvanceToSomething(FILE *fh,char *lastChar)
{
	bool isEof=false;
	bool isSomething=false;

	char c=0;
	while (isSomething==false)
	{
		c=getc(fh);
		if (c==EOF)
		{
			isSomething=true;
			isEof=true;
		}
		if (c=='<')
		{
			isSomething=true;
		}
		if ((c>='a')&&(c<='z'))
		{
			isSomething=true;
		}
		if ((c>='A')&&(c<='Z'))
		{
			isSomething=true;
		}
		if ((c>='0')&&(c<='9'))
		{
			isSomething=true;
		}

	}
	*lastChar=c;
	//printf("lastchar:%c\n",);
	return isEof;
}

bool isLastTag(std::string *tag)
{
	//printf("l:%s:",tag->substr(1,1).c_str());
	return (tag->substr(1,1)=="/");
}

//todo prototype
//todo right place
void getNodeAttributesFromTag(std::string *tag,X_Node *node)
{
	long unsigned int cIx=0;
	bool endOfTag=false;
	std::string c;
	X_Attribute attribute;
	//printf("debug getNodeAttributesFromTag 1 %s \n",node->name.c_str());
	while (endOfTag==false)
	{
		//advance to space or > or /
		c=tag->substr(cIx++, 1);
		if ((c==">")||(c=="/")||(cIx==tag->length()-1))
		{
			//printf("debug getNodeAttributesFromTag 2 \n");
			endOfTag=true;
		}
		else if (c==" ")
		{
			//printf("debug getNodeAttributesFromTag 3 \n");
			//read attribute name
			attribute.name.clear();
			//printf("debug getNodeAttributesFromTag 4 \n");
			c="x";
			while ((c!="=")&&(cIx!=tag->length()-1))
			{
				//printf("debug getNodeAttributesFromTag 5 %s\n",tag->c_str());
				c=tag->substr(cIx++, 1);
				//printf("debug getNodeAttributesFromTag 6 %s\n",attribute.name.c_str());
				if (c!="=") attribute.name+=c;
				if (c=="/") endOfTag=true;
				//printf("debug getNodeAttributesFromTag 7 %s\n",attribute.name.c_str());
			}
			if (endOfTag!=true)
			{
				//printf("debug getNodeAttributesFromTag 8 \n");
				//printf("debug att: %s \n",attribute.name.c_str());
				//printf("debug getNodeAttributesFromTag 9 \n");
				//by pass one "
				c=tag->substr(cIx++, 1);
				//printf("debug getNodeAttributesFromTag 10 \n");
				//read content
				attribute.content.clear();
				//printf("debug getNodeAttributesFromTag 11 \n");
				c="x";
				while ((c!="\"")&&(cIx!=tag->length()-1))
				{
					//printf("debug getNodeAttributesFromTag 12 \n");
					c=tag->substr(cIx++, 1);
					if (c!="\"") attribute.content+=c;
					//printf("debug getNodeAttributesFromTag 13 \n");
				}
				//printf("debug cnt: %s\n",attribute.content.c_str());
				node->attributes.push_back(attribute);
			}
		}
	}
}

bool X_DocumentReader::ReadNode(FILE *fh,X_Document *doc,std::string *readTag,X_Node *parent)
{
	std::string name;
	std::string tag;
	bool isEof=false;
	char lastChar=0;
	bool isEndOfNode=false;
	//read name and create node
	//printf("debug readNode 1\n");
	getNodeName(readTag,&name);
	//printf("debug readNode 2 %s\n",name.c_str());
	if (name!="!--") //if not a comment
	{
		X_Node node(name);


		//read attributes
		//printf("debug readNode 3\n");
		getNodeAttributesFromTag(readTag,&node);
		//printf("debug readNode 4\n");

		//if not empty node
		if (isEmptyNode(readTag))
		{
			//printf("is empty");
		}
		else
		{
			//read contents while detecting subnodes
			while ((isEndOfNode==false)&&(isEof==false))
			{
				if (lastChar!='<') isEof=readAdvanceToSomething(fh,&lastChar);
				if (lastChar=='<')
				{
					tag.clear();
					isEof=readTagToTag(fh,&tag);
					//printf("tag: %s\n",tag.c_str());
					if (isTagValid(&tag))
					{
						if (isLastTag(&tag))
						{
							isEndOfNode=true;
							//printf("end of node\n");
						}
						else
						{
							//printf("%s\n",tag.c_str());
							isEof=this->ReadNode(fh, doc, &tag,&node);
						}
					}
					else
					{
						isEndOfNode=true;
					}
					lastChar=0;
				}
				else //read content
				{
					isEof=readContent(fh,&node.content,lastChar);
					lastChar='<';
				}
			}

		}

		//add node
		if (parent==NULL)
		{
			doc->nodes.push_back(node);
		}
		else
		{
			parent->nodes.push_back(node);
		}
	}
	return isEof;
}

void X_DocumentReader::Read(FILE *fh,X_Document *doc)
{
	bool isEof=false;
	std::string tag;
	char lastChar;
	if (fh!=NULL)
	{
		while (isEof==false)
		{
			tag.clear();
			//printf("debug read 1\n");
			isEof=readAdvanceToSomething(fh,&lastChar);
			//printf("debug read 2\n");
			if ((isEof==false)&&(lastChar=='<'))
			{
				//printf("debug read 3\n");
				isEof=readTagToTag(fh,&tag);
				//printf("debug read 4\n");
				if (isTagValid(&tag))
				{
					//printf("debug read 5\n");
					//printf("debug read %s\n",tag.c_str());
					isEof=this->ReadNode(fh, doc, &tag,NULL);
					//printf("debug read 6\n");
				}
			}

		}
	}
	else
	{
		printf("ERROR: X_DocumentReader received null pointer\n");
	}
}

/* Public Functions ******************************************************/
/* none */

/* Private Methods  ***********************************************************/
/* none */

/* Private Functions ******************************************************/
/* none */
