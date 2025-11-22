#include "pch.h"
#include "Point.h"
#include <tuple>

Point::Point(const double& x, const double& y, const double& z) : Object_3D("Point"), x(x), y(y), z(z) {}
Point::~Point() {}

std::string Point::getName() const { return name; }

bool Point::operator==(const Point& p2) const
{
	return std::tie(x, y, z) == std::tie(p2.x, p2.y, p2.z);
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << p.getName() << "\n";
	out << p.x << " " << p.y << " " << p.z << "\n\n";
	return out;
}