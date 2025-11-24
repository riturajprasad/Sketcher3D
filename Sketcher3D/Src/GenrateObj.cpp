#include "GenrateObj.h"
#include <unordered_map>
using namespace std;

void GenrateObj::genrate3D()
{
	unordered_map<string, vector<unique_ptr<Shape>>> AllShapes;
	//vector<unique_ptr<Shape>> myShape;
	MyFile_skt skt;
	//skt.read("My3D_Obj.skt", myShape);
	//skt.write(myShape);
	skt.read_map("My3D_Obj.skt", AllShapes);
	skt.write_map(AllShapes);

	File file;
	//file.write(myShape);
	file.write_map(AllShapes);
}