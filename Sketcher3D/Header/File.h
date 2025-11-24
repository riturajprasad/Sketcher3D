#pragma once
#include "Shape.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Pyramid.h"
#include "Cone.h"
#include <unordered_map>
using namespace std;

class File
{
public:
	void write(vector<unique_ptr<Shape>>& myShape);
	void write_map(unordered_map<string, vector<unique_ptr<Shape>>>& AllShapes);
};