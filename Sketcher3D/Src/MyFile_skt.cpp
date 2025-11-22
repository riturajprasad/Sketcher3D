#include "MyFile_skt.h"
#include <fstream>
using namespace std;

void MyFile_skt::write(vector<unique_ptr<Object_3D>>& myShape)
{
	//ofstream out("E:/Sketcher3D/Sketcher3D/Rcr/Box.skt");
	ofstream out("My3D_Obj.skt");
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
				<< p->getheight() << " "
				<< p->getslant_height() << "\n";
		}
		else if (auto c = dynamic_cast<Cone*>(it.get()))
		{
			out << c->getName() << "\n"
				<< c->getradius() << " "
				<< c->getheight() << " "
				<< c->getslant_height() << "\n";
		}
	}
	out.close();
	std::cout << "myFile_skt saved successfully!\n";
}