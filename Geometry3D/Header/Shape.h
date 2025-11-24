#pragma once
#include "Export.h"
#include <vector>
#include <iostream>
#include <string>
#include "Point.h"

class GEOMETRY3D_API Shape
{
private:
	std::string mName;
public:
	Shape(const std::string& name);
	virtual ~Shape();

	std::string getName() const;
	virtual std::vector<std::vector<Point>> getCoordinates() const = 0;
	virtual void save(std::ostream &fout) const = 0;
	virtual void saveForGnu(std::ostream &fout) const = 0;
protected:
	const double M_PI = 3.14159265358979323846;
};