#pragma once
#include "Object_3D.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Pyramid.h"
#include "Cone.h"

class MyFile_skt
{
public:
	void write(std::vector<std::unique_ptr<Object_3D>>& myShape);
};