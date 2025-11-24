#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cuboid : public Shape
{
private:
	double mLength;
	double mBreadth;
	double mHeight;
public:
	Cuboid(const std::string& name, const double& l, const double& b, const double& h);
	~Cuboid();

	std::vector<std::vector<Point>> getCoordinates() const override;
	void save(std::ostream &fout) const override;
	void saveForGnu(std::ostream &fout) const override;

	double getlength() const;
	double getbreadth() const;
	double getheight() const;
};