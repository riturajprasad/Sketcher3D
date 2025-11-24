#include "pch.h"
#include "Cube.h"

Cube::Cube(const std::string& name = "Cube", const double& s) : Shape(name), mSide(s) {}
Cube::~Cube() {}

std::vector<std::vector<Point>> Cube::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point bottom_p1(0, 0, 0);
	Point bottom_p2(0, mSide, 0);
	Point bottom_p3(mSide, mSide, 0);
	Point bottom_p4(mSide, 0, 0);
	Point top_p1(0, 0, mSide);
	Point top_p2(0, mSide, mSide);
	Point top_p3(mSide, mSide, mSide);
	Point top_p4(mSide, 0, mSide);
	cord.push_back({ bottom_p1, bottom_p2, bottom_p3, bottom_p4, bottom_p1 });
	cord.push_back({ top_p1, top_p2, top_p3, top_p4, top_p1 });
	cord.push_back({ bottom_p1, top_p1 });
	cord.push_back({ bottom_p4, top_p4 });
	cord.push_back({ bottom_p3, top_p3 });
	cord.push_back({ bottom_p2, top_p2 });
	return cord;
}
void Cube::save(std::ostream& fout) const
{
	fout << getName() << "\n"
		<< "s = " << getside() << "\n";
}
void Cube::saveForGnu(std::ostream& fout) const
{
	fout << getName() << "\n";
	for (auto& it : getCoordinates())
	{
		for (auto& cord : it) fout << cord.X() << " " << cord.Y() << " " << cord.Z() << "\n";
		fout << "\n\n";
	}
}

double Cube::getside() const { return mSide; }