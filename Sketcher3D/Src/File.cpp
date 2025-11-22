#include "File.h"
#include <fstream>
using namespace std;

void File::write(vector<unique_ptr<Object_3D>>& myShape)
{
	//ofstream out("E:/Sketcher3D/Sketcher3D/Rcr/Box.dat");
	ofstream out("3D_Obj.dat");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& it : myShape)
	{
		if (auto p = dynamic_cast<Point*>(it.get())) out << *p << "\n";
		else if (auto b = dynamic_cast<Cuboid*>(it.get())) out << *b;
		else if (auto s = dynamic_cast<Sphere*>(it.get())) out << *s;
		else if (auto c = dynamic_cast<Cylinder*>(it.get())) out << *c;
		else if (auto p = dynamic_cast<Pyramid*>(it.get())) out << *p;
		else if (auto c = dynamic_cast<Cone*>(it.get())) out << *c;
	}
	out.close();
	std::cout << "File saved successfully!\n";
}