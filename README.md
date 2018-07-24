Maya Exporter Plugin
====================

This small Maya experiment using the C++ API is to write a vertex structure, triangle structure, and mesh class. 
The way it works is as follows: 
	- The attached vertex structure, triangle structure, and mesh class are used by the exporter.
	- The exporter will fill out the created structures. 
	- Finally, it saves the binary data using an fstream. 

### Output:
 The length of the name of the mesh, including the null terminator (unsigned int).
 The mesh name, including the null terminator. (length of the string + null terminator).
 The number of textures (unsigned int).
 - For each texture
 	The length of the texture name, including the null terminator (unsigned int).
 	The texture name, including the null terminator(length of the string + null terminator).
	The number of unique vertices (unsigned int).
 - For Each vertex
	Position (3 floats)
	Normal (3 floats)
	Texture coordinates (2 floats)
	The number of triangles (unsigned int)
 - For each triangle
	The three vertex indices (3 unsigned int)

## Deployment

1- Loading the plugin
  - Open Maya
  - Click Window > Settings/Preferences
  - Click Plugin Manager…
  - Click Browse and load the plugin.

2- Using the plugin
  - Click File
  - Click the box next to Export All
  - In the drop down menu Choose your Mesh and Scene Exporter.
  - Type the file name you want for the scene file, and export(The names of the mesh files exported will come from the exMesh class).

## Frequently Asked Questions

•How do I debug my plugin?
	- Load the plugin in Maya.
	- In Visual Studio:
	  - Click Debug
	  - Attach To Process…
	  - Make sure the Attach To: field is set to Native.
	  - Choose Maya.exe in the Available Processes box.
	  - Click Attach.
	  - Export in Maya and you should be able to hit your breakpoints.

•I did the above steps but I can’t hit my breakpoints!
	Your source code is different from the .mll file that is loaded in Maya.  To resolve this:
	- Unload the plugin from Maya.
	- In Visual Studio:
	- Click Clean Solution -> Build -> Rebuild.
	- Load the newly generated plugin in Maya.
	- In Visual Studio:
	  - Attach to process Maya.exe.
	  - Try exporting again.

•Do I need to call WriteMesh_Binary()?
	No you do not.  It is called for you automatically.

•How do I know if my exporter is working or not?
	You can open up the .XML files in any web browser, most text editors, Visual Studio, etc.
	Open the .mesh file in the 3DCC Model Viewer.exe.  These are located in the folders called 3DCC_Model_Viewer_Lab4_201X, where X is 2 or 3 for Visual Studio 2012 or 2013.  Use the right one for the version of Visual Studio you have installed.
	If the application does not crash, and your models are displaying correctly, then your exporter was successful.

•It won’t copy over my .mll anymore / build the project, why?
	If it won’t copy over your .mll file, you probably still have the plugin loaded in Maya. In order to rebuild the project and copy the new .mll you must first unload the plugin from Maya.
	
## Built With

* [Visual Studio](https://visualstudio.microsoft.com/) 					- For C++ development
* [Maya 2015](https://knowledge.autodesk.com/support/maya/downloads) 	- This project was developed using Maya 2015

## Contributing

Please read [CONTRIBUTING.md](https://github.com/Cabrra/Contributing-template/blob/master/Contributing-template.md) for details on our code of conduct, and the process for submitting pull requests to me.
	
## Authors

* **Jagoba "Jake" Marcos** - [Cabrra](https://github.com/Cabrra)

## License

This project is licensed under the MIT license - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Full Sail University - Game Development Department
