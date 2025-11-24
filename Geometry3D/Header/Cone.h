#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cone : public Shape
{
private:
	double mRadius;
	double mHeight;

public:
	Cone(const std::string& name, const double& r, const double& h);
	~Cone();

	std::vector<std::vector<Point>> getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getradius() const;
	double getheight() const;
	double getslant_height() const;

private:
	const int N = 72;
};