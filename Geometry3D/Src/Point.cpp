#include "pch.h"
#include "Point.h"
#include <tuple>

Point::Point(const double& x, const double& y, const double& z) : x(x), y(y), z(z) {}
Point::~Point() {}

bool Point::operator==(const Point& p2) const
{
	return std::tie(x, y, z) == std::tie(p2.x, p2.y, p2.z);
}