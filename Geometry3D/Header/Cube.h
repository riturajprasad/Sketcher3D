#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Cube : public Shape
{
private:
	double mSide;
public:
	Cube(const double& s, const std::string& name = "Cube");
	~Cube();

	std::vector<std::vector<Point>> getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getside() const;
};