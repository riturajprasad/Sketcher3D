#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Sphere : public Shape
{
private:
	Point center;
	Point surface;

public:
	Sphere(const Point&, const Point&);
	Sphere(const double&);
	~Sphere();

	std::vector<std::vector<Point>> getCoordinates() const override;
	double getradius() const;

private:
	const double PI = 3.14159265358979323846;
	const int N = 36;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream&, const Sphere&);