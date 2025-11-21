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

	std::vector<std::pair<Point, Point>> getCoordinates() const override;
	double getradius() const;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream&, const Sphere&);