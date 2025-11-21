// Geometry3D.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Geometry3D.h"


// This is an example of an exported variable
GEOMETRY3D_API int nGeometry3D=0;

// This is an example of an exported function.
GEOMETRY3D_API int fnGeometry3D(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CGeometry3D::CGeometry3D()
{
    return;
}
