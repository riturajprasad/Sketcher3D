#pragma once
#include "Export.h"
#include <vector>
#include <iostream>
#include <string>
#include "Point.h"

class GEOMETRY3D_API Shape
{
private:
	std::string mType;
	std::string mName;
public:
	Shape(const std::string& type, const std::string& name);
	virtual ~Shape();

	const std::string& getName() const;
	const std::string& getType() const;
	virtual const std::vector<std::vector<Point>>& getCoordinates() const = 0;
	virtual void save(std::ostream &fout) const = 0;
	virtual void saveForGnu(std::ostream &fout) const = 0;
protected:
	const double M_PI = 3.14159265358979323846;
};