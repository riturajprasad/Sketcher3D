#include "pch.h"
#include "Pyramid.h"
#include <cmath>

Pyramid::Pyramid(const Point& p1, const Point& p3, const double& h) : Shape("Pyramid"), p1(p1), p3(p3),
p2(p1.x, p3.y, p1.z), p4(p3.x, p1.y, p1.z), height(h),
h_pt(((p3.x - p1.x) / 2.0), ((p3.y - p1.y) / 2.0), h) { }
Pyramid::Pyramid(const double& l, const double& b, const double& h) : Shape("Pyramid"),
p1(0, 0, 0), p3(l, b, 0), p2(0, b, 0), p4(l, 0, 0), height(h), h_pt((l/2), (b/2), h) { }
Pyramid::~Pyramid() {}

std::vector<std::vector<Point>> Pyramid::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	cord.push_back({ p1, p2, p3, p4, p1 });
	cord.push_back({ h_pt, p1 });
	cord.push_back({ h_pt, p2 });
	cord.push_back({ h_pt, p3 });
	cord.push_back({ h_pt, p4 });
	return cord;
}

double Pyramid::getlength() const { return std::fabs(p4.x - p1.x); }
double Pyramid::getbreadth() const { return std::fabs(p2.y - p1.y); }
double Pyramid::getheight() const { return height; }
double Pyramid::getslant_height() const
{
	return std::fabs(std::sqrt(pow((h_pt.x - p1.x), 2) + pow((h_pt.y - p1.y), 2) + pow((h_pt.z - p1.z), 2))); 
}

std::ostream& operator<<(std::ostream& out, const Pyramid& p)
{
	out << p.getName() << "\n";
	for (auto& it : p.getCoordinates())
	{
		for (auto& cord : it) out << cord.x << " " << cord.y << " " << cord.z << "\n";
		out << "\n\n";
	}
	return out;
}