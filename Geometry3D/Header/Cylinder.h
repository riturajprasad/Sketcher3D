#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cylinder : public Shape
{
private:
	double mRadius;
	double mHeight;

public:
	Cylinder(const std::string& name, double r, double h);
	~Cylinder();

	const std::vector<std::vector<Point>>& getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getradius() const;
	double getheight() const;

private:
	const int N = 72;
};