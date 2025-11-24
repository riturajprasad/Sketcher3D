#include "pch.h"
#include "Point.h"
#include <tuple>

Point::Point() : mx(0.0), my(0.0), mz(0.0) {}
Point::Point(const double& x, const double& y, const double& z) : mx(x), my(y), mz(z) {}
Point::~Point() {}

double Point::X() const { return mx; }
double Point::Y() const { return my; }
double Point::Z() const { return mz; }

void Point::setX(const double& x) { mx = x; }
void Point::setY(const double& y) { my = y; }
void Point::setZ(const double& z) { mz = z; }

bool Point::operator==(const Point& p2) const
{
	return std::tie(mx, my, mz) == std::tie(p2.mx, p2.my, p2.mz);
}