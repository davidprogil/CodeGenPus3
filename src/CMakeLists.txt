cmake_minimum_required(VERSION 3.10)

# set the project name
project(CodeGenPus3)


# add the executable
add_executable(
	reader
	"reader.cpp"
	"dgXmlLib/X_Attribute.cpp"
	"dgXmlLib/X_Document.cpp"
	"dgXmlLib/X_DocumentReader.cpp"
	"dgXmlLib/X_Node.cpp"
	"codeGenPus/CGDM_Field.cpp"
	"codeGenPus/CGDM_Interface.cpp"
	"codeGenPus/CGDM_Packet.cpp"
	"codeGenPus/CGDM_TypeEnum.cpp"
	"codeGenPus/CGDM_TypeEnumElement.cpp"
	"codeGenPus/CGDM_TypeStructure.cpp"
	)

add_executable(
	generatorFillers
	"generatorFillers.cpp"
	"dgXmlLib/X_Attribute.cpp"
	"dgXmlLib/X_Document.cpp"
	"dgXmlLib/X_DocumentReader.cpp"
	"dgXmlLib/X_Node.cpp"
	"codeGenPus/CGDM_Field.cpp"
	"codeGenPus/CGDM_Interface.cpp"
	"codeGenPus/CGDM_Packet.cpp"
	"codeGenPus/CGDM_TypeEnum.cpp"
	"codeGenPus/CGDM_TypeEnumElement.cpp"
	"codeGenPus/CGDM_TypeStructure.cpp"
	"codeGenPus/CGFG_FillersGenerator.cpp"
	)

add_executable(
	generatorSerializerss
	"generatorSerializers.cpp"
	"dgXmlLib/X_Attribute.cpp"
	"dgXmlLib/X_Document.cpp"
	"dgXmlLib/X_DocumentReader.cpp"
	"dgXmlLib/X_Node.cpp"
	"codeGenPus/CGDM_Field.cpp"
	"codeGenPus/CGDM_Interface.cpp"
	"codeGenPus/CGDM_Packet.cpp"
	"codeGenPus/CGDM_TypeEnum.cpp"
	"codeGenPus/CGDM_TypeEnumElement.cpp"
	"codeGenPus/CGDM_TypeStructure.cpp"
	"codeGenPus/CGFG_FillersGenerator.cpp"
	"codeGenPus/CGFG_SerializersGenerator.cpp"
	)
