#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cylinder : public Shape
{
private:
	Point center;
	Point surface;
	double height;

public:
	Cylinder(const Point&, const Point&, const double&);
	Cylinder(const double&, const double&);
	~Cylinder();

	std::vector<std::vector<Point>> getCoordinates() const override;
	double getradius() const;
	double getheight() const;

private:
	const double PI = 3.14159265358979323846;
	const int N = 72;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream&, const Cylinder&);