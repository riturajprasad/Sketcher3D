#include "MyFile_skt.h"
#include <fstream>
using namespace std;

void MyFile_skt::write(vector<unique_ptr<Object_3D>>& myShape)
{
	//ofstream out("E:/Sketcher3D/Sketcher3D/Rcr/Box.skt");
	ofstream out("My3D_Obj2.skt");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& it : myShape)
	{
		if (auto p = dynamic_cast<Point*>(it.get())) out << *p;
		else if (auto b = dynamic_cast<Cuboid*>(it.get()))
		{
			out << b->getName() << "\n"
				<< b->getlength() << " "
				<< b->getbreadth() << " "
				<< b->getheight() << "\n";
		}
		else if (auto s = dynamic_cast<Sphere*>(it.get()))
		{
			out << s->getName() << "\n"
				<< s->getradius() << "\n";
		}
		else if (auto c = dynamic_cast<Cylinder*>(it.get()))
		{
			out << c->getName() << "\n"
				<< c->getradius() << " "
				<< c->getheight() << "\n";
		}
		else if (auto p = dynamic_cast<Pyramid*>(it.get()))
		{
			out << p->getName() << "\n"
				<< p->getlength() << " "
				<< p->getbreadth() << " "
				<< p->getheight() << "\n";
		}
		else if (auto c = dynamic_cast<Cone*>(it.get()))
		{
			out << c->getName() << "\n"
				<< c->getradius() << " "
				<< c->getheight() << "\n";
		}
	}
	out.close();
	std::cout << "myFile_skt saved successfully!\n";
}

void MyFile_skt::read(const std::string& filename, vector<unique_ptr<Object_3D>>& myShape)
{
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "Cannot open file!\n";
		return;
	}
	myShape.clear();
	std::string type;

	while (fin >> type)
	{
		if (type == "Point")
		{
			double x, y, z;
			fin >> x >> y >> z;
			myShape.push_back(std::make_unique<Point>(x, y, z));
		}
		else if (type == "Cuboid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(std::make_unique<Cuboid>(l, b, h));
		}
		else if (type == "Sphere")
		{
			double r;
			fin >> r;
			myShape.push_back(std::make_unique<Sphere>(r));
		}
		else if (type == "Cylinder")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(std::make_unique<Cylinder>(r, h));
		}
		else if (type == "Pyramid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(std::make_unique<Pyramid>(l, b, h));
		}
		else if (type == "Cone")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(std::make_unique<Cone>(r, h));
		}
		else
		{
			cerr << "Unknown shape type in file: " << type << "\n";
			// optionally skip the line:
			// fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}