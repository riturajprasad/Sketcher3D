#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Sphere : public Shape
{
private:
	double mRadius;

public:
	Sphere(const double& r, const std::string& name = "Sphere");
	~Sphere();

	std::vector<std::vector<Point>> getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getradius() const;

private:
	const int N = 72;
};