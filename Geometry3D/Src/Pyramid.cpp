#include "pch.h"
#include "Pyramid.h"
#include <cmath>

Pyramid::Pyramid(const std::string& name, double l, double b, double h) :
Shape("Pyramid", name), mBaseLength(l), mBaseBreadth(b), mHeight(h) { }
Pyramid::~Pyramid() {}

const std::vector<std::vector<Point>>& Pyramid::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point p1(0, 0, 0);
	Point p2(0, mBaseBreadth, 0);
	Point p3(mBaseLength, mBaseBreadth, 0);
	Point p4(mBaseLength, 0, 0);
	Point h_pt(0, 0, mHeight);
	cord.push_back({ p1, p2, p3, p4, p1 });
	cord.push_back({ h_pt, p1 });
	cord.push_back({ h_pt, p2 });
	cord.push_back({ h_pt, p3 });
	cord.push_back({ h_pt, p4 });
	return cord;
}
void Pyramid::save(std::ostream& fout) const
{
	fout << getName() << "\n"
		 << "l = " << getlength() << "| "
		 << "b = " << getbreadth() << "| "
		 << "h = " << getheight() << "\n";
}
void Pyramid::saveForGnu(std::ostream& fout) const
{
	fout << getName() << "\n";
	for (auto& it : getCoordinates())
	{
		for (auto& cord : it) fout << cord.getX() << " " << cord.getY() << " " << cord.getZ() << "\n";
		fout << "\n\n";
	}
}

double Pyramid::getlength() const { return mBaseLength; }
double Pyramid::getbreadth() const { return mBaseBreadth; }
double Pyramid::getheight() const { return mHeight; }
double Pyramid::getslant_height() const
{
	Point p1, h_pt(0, 0, mHeight);
	return p1.distance(h_pt);
}