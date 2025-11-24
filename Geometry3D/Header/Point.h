#pragma once
#include "Export.h"

class GEOMETRY3D_API Point
{
private:
	double mx;
	double my;
	double mz;

public:
	Point();
	Point(const double& x, const double& y, const double& z);
	~Point();

	double X() const;
	double Y() const;
	double Z() const;

	void setX(const double& x);
	void setY(const double& x);
	void setZ(const double& x);

	bool operator==(const Point&) const;
};