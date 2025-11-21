#include "GenrateObj.h"

void GenrateObj::genrate3D()
{
	vector<unique_ptr<Object_3D>> myShape;
	/*myShape.push_back(make_unique<Point>(0, 0, 0));*/
	myShape.push_back(make_unique<Cuboid>(1, 2, 3));
	//myShape.push_back(make_unique<Box>(p1, p3, 2));
	//myShape.push_back(make_unique<Box>(p1, p3, 3));

	File file;
	file.write(myShape);
}