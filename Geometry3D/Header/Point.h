#pragma once
#include "Export.h"
#include <iostream>

class GEOMETRY3D_API Point
{
public:
	double x;
	double y;
	double z;

	Point(const double&, const double&, const double&);
	~Point();

	bool operator==(const Point&) const;
};