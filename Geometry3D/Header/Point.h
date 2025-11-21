#pragma once
#include "Export.h"
#include <iostream>
#include "Object_3D.h"

class GEOMETRY3D_API Point : public Object_3D
{
public:
	double x;
	double y;
	double z;

	Point(const double&, const double&, const double&);
	~Point();

	std::string getName() const override;
	bool operator==(const Point&) const;
};
GEOMETRY3D_API std::ostream& operator<<(std::ostream& out, const Point& p);