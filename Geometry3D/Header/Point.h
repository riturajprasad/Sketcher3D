#pragma once
#include "Export.h"

class GEOMETRY3D_API Point
{
private:
	double mX;
	double mY;
	double mZ;

public:
	Point();
	Point(double x, double y, double z);
	~Point();

	double distance(const Point& other) const;
	double getX() const;
	double getY() const;
	double getZ() const;

	void setX(const double& x);
	void setY(const double& y);
	void setZ(const double& z);

	bool operator==(const Point&) const;
};