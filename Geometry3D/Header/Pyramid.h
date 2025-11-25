#pragma once
#include "Export.h"
#include "Shape.h"

class GEOMETRY3D_API Pyramid : public Shape
{
private:
	double mBaseLength;
	double mBaseBreadth;
	double mHeight;

public:
	Pyramid(const std::string& name, double l, double b, double h);
	~Pyramid();

	const std::vector<std::vector<Point>>& getCoordinates() const override;
	void save(std::ostream& fout) const override;
	void saveForGnu(std::ostream& fout) const override;

	double getlength() const;
	double getbreadth() const;
	double getheight() const;
	double getslant_height() const;
};