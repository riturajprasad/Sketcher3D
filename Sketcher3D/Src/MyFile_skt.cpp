#include "MyFile_skt.h"
#include <fstream>

void MyFile_skt::write(vector<unique_ptr<Shape>>& myShape)
{ 
	ofstream out("My3D_Obj2.skt");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& it : myShape)
	{
		if (auto b = dynamic_cast<Cuboid*>(it.get())) b->save(out);
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
			if (p->getName() == "Pyramid")
			{
				out << p->getName() << "\n"
					<< p->getlength() << " "
					<< p->getbreadth() << " "
					<< p->getheight() << "\n";
			}
			else if (p->getName() == "Regular_Pyramid")
			{
				out << p->getName() << "\n"
					<< p->getlength() << "\n";
			}
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

void MyFile_skt::read(const string& filename, vector<unique_ptr<Shape>>& myShape)
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
			myShape.push_back(make_unique<Point>(x, y, z));
		}
		else if (type == "Cuboid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(make_unique<Cuboid>(l, b, h));
		}
		else if (type == "Cube")
		{
			double s;
			fin >> s;
			myShape.push_back(make_unique<Cuboid>(s));
		}
		else if (type == "Sphere")
		{
			double r;
			fin >> r;
			myShape.push_back(make_unique<Sphere>(r));
		}
		else if (type == "Cylinder")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(make_unique<Cylinder>(r, h));
		}
		else if (type == "Pyramid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(make_unique<Pyramid>(l, b, h));
		}
		else if (type == "Regular_Pyramid")
		{
			double s;
			fin >> s;
			myShape.push_back(make_unique<Pyramid>(s));
		}
		else if (type == "Cone")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(make_unique<Cone>(r, h));
		}
		else
		{
			cerr << "Unknown shape type in file: " << type << "\n";
		}
	}
}

void MyFile_skt::write_map(unordered_map<string, vector<unique_ptr<Shape>>>& AllShapes)
{
	ofstream out("My3D_Objmap.skt");
	if (!out) {
		cerr << "Cannot open file!\n";
		return;
	}
	for (auto& pair : AllShapes)
	{
		out << pair.first << "\n";
		for (auto& it : pair.second)
		{
			if (auto p = dynamic_cast<Point*>(it.get()))
			{
				out << p->x << " " << p->y << " " << p->z << "\n";
			}
			else if (auto b = dynamic_cast<Cuboid*>(it.get()))
			{
				if (b->getName() == "Cuboid")
				{
					out << b->getlength() << " "
						<< b->getbreadth() << " "
						<< b->getheight() << "\n";
				}
				else if (b->getName() == "Cube") out << b->getlength() << "\n";
			}
			else if (auto s = dynamic_cast<Sphere*>(it.get())) out << s->getradius() << "\n";
			else if (auto c = dynamic_cast<Cylinder*>(it.get()))
			{
				out << c->getradius() << " "
					<< c->getheight() << "\n";
			}
			else if (auto p = dynamic_cast<Pyramid*>(it.get()))
			{
				if (p->getName() == "Pyramid")
				{
					out << p->getlength() << " "
						<< p->getbreadth() << " "
						<< p->getheight() << "\n";
				}
				else if (p->getName() == "Regular_Pyramid") out << p->getlength() << "\n";
			}
			else if (auto c = dynamic_cast<Cone*>(it.get()))
			{
				out << c->getradius() << " "
					<< c->getheight() << "\n";
			}
		}
	}
	out.close();
	std::cout << "myFile_skt saved successfully!\n";
}

void MyFile_skt::read_map(const std::string& filename, unordered_map<string, vector<unique_ptr<Shape>>>& AllShapes)
{
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "Cannot open file!\n";
		return;
	}
	AllShapes.clear();
	std::string type;

	while (fin >> type)
	{
		while (true)
		{
			int c = fin.peek();
			while (std::isspace(c)) {
				fin.get();       // consume whitespace
				c = fin.peek();  // check next char
			}

			if (c == EOF) break;

			// Now checking correct first non-space character
			if (std::isalpha(c)) break;

			if (type == "Point")
			{
				double x, y, z;
				fin >> x >> y >> z;
				AllShapes["Point"].push_back(make_unique<Point>(x, y, z));
			}
			else if (type == "Cuboid")
			{
				double l, b, h;
				fin >> l >> b >> h;
				AllShapes["Cuboid"].push_back(make_unique<Cuboid>(l, b, h));
			}
			else if (type == "Cube")
			{
				double s;
				fin >> s;
				AllShapes["Cube"].push_back(make_unique<Cuboid>(s));
			}
			else if (type == "Sphere")
			{
				double r;
				fin >> r;
				AllShapes["Sphere"].push_back(make_unique<Sphere>(r));
			}
			else if (type == "Cylinder")
			{
				double r, h;
				fin >> r >> h;
				AllShapes["Cylinder"].push_back(make_unique<Cylinder>(r, h));
			}
			else if (type == "Pyramid")
			{
				double l, b, h;
				fin >> l >> b >> h;
				AllShapes["Pyramid"].push_back(make_unique<Pyramid>(l, b, h));
			}
			else if (type == "Regular_Pyramid")
			{
				double s;
				fin >> s;
				AllShapes["Regular_Pyramid"].push_back(make_unique<Pyramid>(s));
			}
			else if (type == "Cone")
			{
				double r, h;
				fin >> r >> h;
				AllShapes["Cone"].push_back(make_unique<Cone>(r, h));
			}
			else
			{
				cerr << "Unknown shape type in file: " << type << "\n";
			}
		}
	}
}