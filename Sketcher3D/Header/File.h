#pragma once
#include "Object_3D.h"
#include "Cuboid.h"
#include "Sphere.h"


class File
{
public:
	void write(std::vector<std::unique_ptr<Object_3D>>& myShape);
};