# Template to use VTK in QT
`
using QVTKWidget
`

In this project, a [QVTK] widget is used into an application in [QT] (in a QMainWindow). Some  aspects to be considered:

* Initially, the project was created using QT Creator. However, I am not fan of that IDE/environment (*actually I hate it*). That is the reason that project contains a `.pro` file
* Next the **QT Designer** was used it just to stick the QVTKWidget
* Project was thinking to work using **Visual Studio**. Then a [CMake] file is created manually (don't worry, it works)
* Files `mainview.*` are related to the graphical interface

File `mainview.cpp` contains the code to render the VTK object (also the rendered/window association), but is not recommended. A best approach is to use a *manager* class to glue all components (layer-based, business logic, etc.)

### Setup

`VTKinQT` requires [CMake] to create the environment (I used the version 3.10).
Particularly, I used Visual Studio 2017 as IDE. Moreover, I used QT version 5.10 and VTK version 8.0.1 (December, 2017). 

###### If you want to contribute? Great!

[QT]: <https://www.qt.io/>
[QVTK]: <https://www.vtk.org/doc/nightly/html/classQVTKWidget.html>
[CMake]: <https://cmake.org/>
