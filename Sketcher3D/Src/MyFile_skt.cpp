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
		if (auto c = dynamic_cast<Cuboid*>(it.get())) c->save(out);
		else if (auto c = dynamic_cast<Cube*>(it.get())) c->save(out);
		else if (auto s = dynamic_cast<Sphere*>(it.get())) s->save(out);
		else if (auto c = dynamic_cast<Cylinder*>(it.get())) c->save(out);
		else if (auto p = dynamic_cast<Pyramid*>(it.get())) p->save(out);
		else if (auto c = dynamic_cast<Cone*>(it.get())) c->save(out);
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
		if (type == "Cuboid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(make_unique<Cuboid>("c1", l, b, h));
		}
		else if (type == "Cube")
		{
			double s;
			fin >> s;
			myShape.push_back(make_unique<Cube>("c1", s));
		}
		else if (type == "Sphere")
		{
			double r;
			fin >> r;
			myShape.push_back(make_unique<Sphere>("s1", r));
		}
		else if (type == "Cylinder")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(make_unique<Cylinder>("c1", r, h));
		}
		else if (type == "Pyramid")
		{
			double l, b, h;
			fin >> l >> b >> h;
			myShape.push_back(make_unique<Pyramid>("p1", l, b, h));
		}
		else if (type == "Cone")
		{
			double r, h;
			fin >> r >> h;
			myShape.push_back(make_unique<Cone>("c1", r, h));
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
			if (auto c = dynamic_cast<Cuboid*>(it.get())) c->save(out);
			else if (auto c = dynamic_cast<Cube*>(it.get())) c->save(out);
			else if (auto s = dynamic_cast<Sphere*>(it.get())) s->save(out);
			else if (auto c = dynamic_cast<Cylinder*>(it.get())) c->save(out);
			else if (auto p = dynamic_cast<Pyramid*>(it.get())) p->save(out);
			else if (auto c = dynamic_cast<Cone*>(it.get())) c->save(out);
		}
	}
	out.close();
	std::cout << "myFile_skt saved successfully!\n";
}

void MyFile_skt::read_map(const std::string& filename, unordered_map<string, vector<unique_ptr<Shape>>>& AllShapes)
{
	//std::ifstream fin(filename);
	//if (!fin.is_open()) {
	//	cerr << "Cannot open file!\n";
	//	return;
	//}
	//AllShapes.clear();
	//std::string type;

	//while (fin >> type)
	//{
	//	while (true)
	//	{
	//		int c = fin.peek();
	//		while (std::isspace(c)) {
	//			fin.get();       // consume whitespace
	//			c = fin.peek();  // check next char
	//		}

	//		if (c == EOF) break;

	//		// Now checking correct first non-space character
	//		if (std::isalpha(c)) break;

	//		if (type == "Cuboid")
	//		{
	//			double l, b, h;
	//			fin >> l >> b >> h;
	//			AllShapes["Cuboid"].push_back(make_unique<Cuboid>(l, b, h));
	//		}
	//		else if (type == "Cube")
	//		{
	//			double s;
	//			fin >> s;
	//			AllShapes["Cube"].push_back(make_unique<Cube>(s));
	//		}
	//		else if (type == "Sphere")
	//		{
	//			double r;
	//			fin >> r;
	//			AllShapes["Sphere"].push_back(make_unique<Sphere>(r));
	//		}
	//		else if (type == "Cylinder")
	//		{
	//			double r, h;
	//			fin >> r >> h;
	//			AllShapes["Cylinder"].push_back(make_unique<Cylinder>(r, h));
	//		}
	//		else if (type == "Pyramid")
	//		{
	//			double l, b, h;
	//			fin >> l >> b >> h;
	//			AllShapes["Pyramid"].push_back(make_unique<Pyramid>(l, b, h));
	//		}
	//		else if (type == "Cone")
	//		{
	//			double r, h;
	//			fin >> r >> h;
	//			AllShapes["Cone"].push_back(make_unique<Cone>(r, h));
	//		}
	//		else
	//		{
	//			cerr << "Unknown shape type in file: " << type << "\n";
	//		}
	//	}
	//}
}