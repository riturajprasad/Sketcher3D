#include "GenrateObj.h"
using namespace std;

void GenrateObj::genrate3D()
{
	vector<unique_ptr<Object_3D>> myShape;
	MyFile_skt skt;
	skt.read("My3D_Obj.skt", myShape);
	skt.write(myShape);

	File file;
	file.write(myShape);
}