#include "File.h"
#include <fstream>

void File::write(vector<unique_ptr<Shape>>& myShape)
{
	ofstream out("3D_Obj.dat");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& it : myShape)
	{
		if (auto c = dynamic_cast<Cuboid*>(it.get())) c->saveForGnu(out);
		else if (auto c = dynamic_cast<Cube*>(it.get())) c->saveForGnu(out);
		else if (auto s = dynamic_cast<Sphere*>(it.get())) s->saveForGnu(out);
		else if (auto c = dynamic_cast<Cylinder*>(it.get())) c->saveForGnu(out);
		else if (auto p = dynamic_cast<Pyramid*>(it.get())) p->saveForGnu(out);
		else if (auto c = dynamic_cast<Cone*>(it.get())) c->saveForGnu(out);
	}
	out.close();
	std::cout << "File saved successfully!\n";
}

void File::write_map(unordered_map<string, vector<unique_ptr<Shape>>>& AllShapes)
{
	ofstream out("3D_Objmap.dat");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& pair : AllShapes)
	{
		for (auto& it : pair.second)
		{
			if (auto c = dynamic_cast<Cuboid*>(it.get())) c->saveForGnu(out);
			else if (auto c = dynamic_cast<Cube*>(it.get())) c->saveForGnu(out);
			else if (auto s = dynamic_cast<Sphere*>(it.get())) s->saveForGnu(out);
			else if (auto c = dynamic_cast<Cylinder*>(it.get())) c->saveForGnu(out);
			else if (auto p = dynamic_cast<Pyramid*>(it.get())) p->saveForGnu(out);
			else if (auto c = dynamic_cast<Cone*>(it.get())) c->saveForGnu(out);
		}
	}
	out.close();
	std::cout << "File saved successfully!\n";
}