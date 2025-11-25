#include "pch.h"
#include "Point.h"
#include <tuple>
#include <cmath>

Point::Point() : mX(0.0), mY(0.0), mZ(0.0) {}
Point::Point(double x, double y, double z) : mX(x), mY(y), mZ(z) {}
Point::~Point() {}

double Point::distance(const Point& other) const
{
	return std::sqrt((mX - other.mX) * (mX - other.mX) +
					(mY - other.mY) * (mY - other.mY) +
					(mZ - other.mZ) * (mZ - other.mZ));
}
double Point::getX() const { return mX; }
double Point::getY() const { return mY; }
double Point::getZ() const { return mZ; }

void Point::setX(const double& x) { mZ = x; }
void Point::setY(const double& y) { mY = y; }
void Point::setZ(const double& z) { mZ = z; }

bool Point::operator==(const Point& p2) const
{
	return std::tie(mX, mY, mZ) == std::tie(p2.mX, p2.mY, p2.mZ);
}