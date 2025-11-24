#include "pch.h"
#include "Cuboid.h"

Cuboid::Cuboid(const double& l, const double& b, const double& h, const std::string& name) :
Shape(name), mLength(l), mBreadth(b), mHeight(h) { }

Cuboid::~Cuboid() { }

std::vector<std::vector<Point>> Cuboid::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point bottom_p1(0, 0, 0);
	Point bottom_p2(0, mBreadth, 0);
	Point bottom_p3(mLength, mBreadth, 0);
	Point bottom_p4(mLength, 0, 0);
	Point top_p1(0, 0, mHeight);
	Point top_p2(0, mBreadth, mHeight);
	Point top_p3(mLength, mBreadth, mHeight);
	Point top_p4(mLength, 0, mHeight);
	cord.push_back({ bottom_p1, bottom_p2, bottom_p3, bottom_p4, bottom_p1 });
	cord.push_back({ top_p1, top_p2, top_p3, top_p4, top_p1 });
	cord.push_back({ bottom_p1, top_p1 });
	cord.push_back({ bottom_p4, top_p4 });
	cord.push_back({ bottom_p3, top_p3 });
	cord.push_back({ bottom_p2, top_p2 });
	return cord;
}
void Cuboid::save(std::ostream &fout) const
{
	fout << getName() << "\n"
		 << "l = " << getlength() << "| "
		 << "b = " << getbreadth() << "| "
		 << "h = " << getheight() << "\n";
}
void Cuboid::saveForGnu(std::ostream &fout) const
{
	fout << getName() << "\n";
	for (auto& it : getCoordinates())
	{
		for (auto& cord : it) fout << cord.X() << " " << cord.Y() << " " << cord.Z() << "\n";
		fout << "\n\n";
	}
}

double Cuboid::getlength() const { return mLength; }
double Cuboid::getbreadth() const { return mBreadth; }
double Cuboid::getheight() const { return mHeight; }