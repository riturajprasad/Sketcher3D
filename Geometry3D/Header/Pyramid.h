#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Pyramid : public Shape
{
private:
	Point p1;
	Point p3;
	Point p2;
	Point p4;
	double height;

public:
	Pyramid(const Point&, const Point&, const double&);
	Pyramid(const double&, const double&, const double&);
	~Pyramid();

	std::vector<std::vector<Point>> getCoordinates() const override;
	double getradius() const;
	double getheight() const;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream&, const Pyramid&);