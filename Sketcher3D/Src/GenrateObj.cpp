#include "GenrateObj.h"
using namespace std;

void GenrateObj::genrate3D()
{
	vector<unique_ptr<Object_3D>> myShape;
	myShape.push_back(make_unique<Point>(0, 0, 0));
	myShape.push_back(make_unique<Cuboid>(1, 2, 3));
	myShape.push_back(make_unique<Sphere>(2));
	myShape.push_back(make_unique<Cylinder>(3, 5));
	myShape.push_back(make_unique<Pyramid>(3, 4, 6));
	myShape.push_back(make_unique<Cone>(3, 5));

	File file;
	file.write(myShape);
}