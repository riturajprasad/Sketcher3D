#pragma once
#include "Export.h"
#include <vector>
#include <string>
#include "Point.h"

class GEOMETRY3D_API Shape
{
private:
	std::string name;
public:
	Shape(const std::string&);
	virtual ~Shape();

	std::string getName() const;
	virtual std::vector<std::vector<Point>> getCoordinates() const = 0;
};