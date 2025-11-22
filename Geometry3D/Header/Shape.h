#pragma once
#include "Export.h"
#include <vector>
#include "Point.h"

class GEOMETRY3D_API Shape : public Object_3D
{
public:
	Shape(const std::string&);
	virtual ~Shape();

	std::string getName() const override;
	virtual std::vector<std::vector<Point>> getCoordinates() const = 0;
};