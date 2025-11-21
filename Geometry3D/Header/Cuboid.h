#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cuboid : public Shape
{
private:
	Point bottom_p1;
	Point bottom_p3;
	Point bottom_p2;
	Point bottom_p4;
	Point top_p1;
	Point top_p2;
	Point top_p3;
	Point top_p4;
public:
	Cuboid(const Point&, const Point&, const double&);
	Cuboid(const double&, const double&, const double&);
	Cuboid(const double&);
	~Cuboid();

	std::vector<std::pair<Point, Point>> getCoordinates() const override;
	double getlength() const;
	double getbreadth() const;
	double getheight() const;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream&, const Cuboid&);