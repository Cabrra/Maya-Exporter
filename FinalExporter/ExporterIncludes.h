

#pragma once
#include <string>
#include <vector>
using namespace std;

struct tVertex
{
	float fX, fY, fZ;		// Coordinates
	float fNX, fNY, fNZ;	// Normal
	float fU, fV;			// Texture Coordinates

	bool operator==(const tVertex& rhs)
	{
		if ((fX == rhs.fX) && (fY == rhs.fY) && (fZ == rhs.fZ) && (fNX == rhs.fNX) && (fNY == rhs.fNY) && (fNZ == rhs.fNZ) && (fU == rhs.fU) && (fV == rhs.fV))
			return true;
		else
			return false;
	}
};

struct tTriangle 
{
	unsigned int uIndices[3]; 						// these create a triangle from 3 vertices in the unique vertex list.
};

class CMesh
{
public:
	std::string 				m_strName; 			// This is the name of the mesh.
	std::vector<std::string> 	m_vTextureNames;	// These are the textures that are used in this mesh.
	std::vector<tVertex>  		m_vUniqueVerts;	 	// These are all the unique vertices in this mesh.
	std::vector<tTriangle> 		m_vTriangles;		// These are the triangles that make up the mesh.    

};

class ExporterIncludes
{
public:
	ExporterIncludes();
	~ExporterIncludes();
};

