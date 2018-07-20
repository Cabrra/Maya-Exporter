#include <maya/MSimple.h>
#include <maya/MGlobal.h>
#include "FileTranslator.h"


MStatus initializePlugin( MObject obj )
{
	MStatus status;

	//creates a Maya 6.0 plug in designed by you
	MFnPlugin plugin(obj, "3DCC Student", "6.0");

	//initializes the plug in using your specific creator function from your file translator
	status = plugin.registerFileTranslator("3DCC Exporter", NULL, CFileTranslator::creator /*, "script name", "option paramters"*/ );

	if(status == MS::kSuccess)
		//this function displays a message in Maya's message window
		MGlobal::displayInfo( MString("Plugin Initialized") );
	else
		//this function displays a message in Maya's message window
		MGlobal::displayInfo( MString("Plugin Failed to Initialize") );

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus status;

	//creates a plugin from the obj passed in from Maya
	MFnPlugin plugin(obj);

	//uninitializes the plug in
	status = plugin.deregisterFileTranslator("3DCC Exporter");

	if(status == MS::kSuccess)
		//this function displays a message in Maya's message window
		MGlobal::displayInfo( MString("Plugin Uninitialized") );
	else
		//this function displays a message in Maya's message window
		MGlobal::displayInfo( MString("Plugin Failed to Uninitialize") );

	return status;
}