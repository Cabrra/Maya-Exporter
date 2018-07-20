#pragma once
#include <maya/MPxFileTranslator.h>
#include "ExporterIncludes.h"
#include "StaticMeshExporter.h"


//class must be derived from MPxFileTranslator to gain Maya's file translator functionality
class CFileTranslator : public MPxFileTranslator
{

	CStaticMeshExporter				m_MeshExporter; //our mesh exporter class

public:
	CFileTranslator(void){}
	~CFileTranslator(void){}


	//////////////////////////////////////////////////////////////////////////////////////
	// Functions that must be specifically written to override parent's virtual versions//
	//////////////////////////////////////////////////////////////////////////////////////

	//creator function is used to initialize plug in
	static void * creator(void);

	//the writer function gets called when you export, this is where the magic will happen
	MStatus writer(const MFileObject& file, const MString& optionString, FileAccessMode mode);

	//Maya checks to see if we have over written its base writer function, as long as we have 
	//a writer function, this will always return true 
	bool haveWriteMethod(void)const { return true; }

	//this sets the default extension that Maya appends to our file name when we export
	MString defaultExtension() const { return "scn";}
	//this is used to filter files when the save file dialog box opens
	MString filter() const { return "*.scn";}

};
