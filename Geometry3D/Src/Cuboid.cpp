#include "pch.h"
#include "Cuboid.h"

Cuboid::Cuboid(const Point& p1, const Point& p3, const double& height) : Shape("Cuboid"), bottom_p1(p1), bottom_p3(p3),
bottom_p2(p1.x, p3.y, p1.z), bottom_p4(p3.x, p1.y, p1.z),
top_p1(p1.x, p1.y, height), top_p2(p1.x, p3.y, height),
top_p3(p3.x, p3.y, height), top_p4(p3.x, p1.y, height) { }

Cuboid::Cuboid(const double& l, const double& b, const double& h) : Shape("Cuboid"), bottom_p1(0, 0, 0), bottom_p3(l, b, 0),
bottom_p2(0, b, 0), bottom_p4(l, 0, 0),
top_p1(0, 0, h), top_p2(0, b, h),
top_p3(l, b, h), top_p4(l, 0, h) { }

Cuboid::Cuboid(const double& s) : Shape("Cube"), bottom_p1(0, 0, 0), bottom_p3(s, s, 0),
bottom_p2(0, s, 0), bottom_p4(s, 0, 0),
top_p1(0, 0, s), top_p2(0, s, s),
top_p3(s, s, s), top_p4(s, 0, s) { }

Cuboid::~Cuboid() {}

std::vector<std::vector<Point>> Cuboid::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	cord.push_back({ bottom_p1, bottom_p4 });
	cord.push_back({ bottom_p4, bottom_p3 });
	cord.push_back({ bottom_p3, bottom_p2 });
	cord.push_back({ bottom_p2, bottom_p1 });
	cord.push_back({ top_p1, top_p4 });
	cord.push_back({ top_p4, top_p3 });
	cord.push_back({ top_p3, top_p2 });
	cord.push_back({ top_p2, top_p1 });
	cord.push_back({ bottom_p1, top_p1 });
	cord.push_back({ bottom_p4, top_p4 });
	cord.push_back({ bottom_p3, top_p3 });
	cord.push_back({ bottom_p2, top_p2 });
	return cord;
}

double Cuboid::getlength() const { return (bottom_p4.x - bottom_p1.x); }
double Cuboid::getbreadth() const { return (bottom_p2.y - bottom_p1.y); }
double Cuboid::getheight() const { return (top_p1.z - bottom_p1.z); }

std::ostream& operator<<(std::ostream& out, const Cuboid& b)
{
	out << b.getName() << "\n";
	for (auto &it : b.getCoordinates())
	{
		for (auto& cord : it) out << cord.x << " " << cord.y << " " << cord.z << "\n";
		out << "\n\n";
	}
	return out;
}