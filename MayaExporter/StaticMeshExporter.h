#pragma once
#include "ExporterIncludes.h"
#include <maya/MFnMesh.h>
#include <string>
#include <vector>

#include <fstream>

class CStaticMeshExporter
{
	//This will be your collection of meshes that you export, whether it be 1 or 100
	std::vector< CMesh > m_exportedMeshes;
	
	// The folder selected by the user for exporting.  File paths must be appended to this.
	std::string m_exportDirectory;

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: ExportMesh
	//	Purpose: to export a particular mesh
	//	Parameters: MFnMesh & currMesh, CMesh<VertType> & outMesh
	//	Return: void
	//	Notes: Exports all the appropriate mesh data (ex. unique verts, tris, mesh name, texture names)
	//			for the MFnMesh passed in and stores it in the mesh structure passed in
	//////////////////////////////////////////////////////////////////////////
	void ExportMesh(MFnMesh & currMesh, CMesh & outMesh);

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: WriteMesh_XML
	//	Purpose: write out the mesh in an xml format
	//	Parameters: const CMesh<VertType> &
	//	Return: void
	//	Notes: Writes out a mesh to xml creating a file "the mesh's name".xml
	//////////////////////////////////////////////////////////////////////////
	void WriteMesh_XML( const CMesh& writeOutMesh );

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: WriteMesh_Binary
	//	Purpose: write out the mesh in a binary format
	//	Parameters: const CMesh<VertType> &
	//	Return: void
	//	Notes: Writes out a mesh to a binary file "the mesh's name".mesh
	//////////////////////////////////////////////////////////////////////////
	void WriteMesh_Binary( const CMesh& writeOutMesh );

public:
	CStaticMeshExporter(void){}
	~CStaticMeshExporter(void){}

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: getTextureNamesFromMesh
	//	Purpose: Gets a list of textures associated with a mesh
	//	Parameters: MFnMesh & mesh, MString Array & names, unsigned int & count
	//	Return: void
	//	Notes: This function has two output parameters:
	//			names -- this stores the texture names
	//			count -- this will contain the number of (elements) in the names variable.
	//////////////////////////////////////////////////////////////////////////
	void getTextureNamesFromMesh( MFnMesh &mesh, MStringArray &names, unsigned &count );

	//////////////////////////////////////////////////////////////////////////
	// Function	: ClearAndReset
	// Takes In	: Nothing
	// Returns	: MStatus
	// Comments	: Clears the exported mesh vector
	//////////////////////////////////////////////////////////////////////////
	MStatus ClearAndReset(void);

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: ExportMeshes
	//	Purpose: Exports the mesh(es) from the Maya scene
	//	Parameters: bool bExportAll
	//	Return: void
	//	Notes: bExportAll will be true to export all meshes, false to export only selected
	//////////////////////////////////////////////////////////////////////////
	void ExportMeshes(bool bExportAll = true);

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: WriteOutMeshes
	//	Purpose: Calls the appropriate write functions for exporting meshes to a file
	//	Parameters: bool bWriteBinary
	//	Return: void
	//	Notes: bWriteBinary will be true if we want to write out the binary files along with the xml
	//////////////////////////////////////////////////////////////////////////
	void WriteOutMeshes( bool bWriteBinary = true );

	//////////////////////////////////////////////////////////////////////////
	//	Function Name: SetExportDirectory
	//	Purpose: Sets the m_exportDirectory variable to the given string
	//	Parameters: string path
	//	Return: void
	//////////////////////////////////////////////////////////////////////////	
	void SetExportDirectory( const char * path );

};

