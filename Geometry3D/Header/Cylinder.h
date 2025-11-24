#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cylinder : public Shape
{
private:
	double mRadius;
	double mHeight;

public:
	Cylinder(const double& r, const double& h, const std::string& name = "Cylinder");
	~Cylinder();

	std::vector<std::vector<Point>> getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getradius() const;
	double getheight() const;

private:
	const int N = 72;
};