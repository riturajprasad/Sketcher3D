#include "pch.h"
#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder(const double& r, const double& h, const std::string& name) : Shape(name),
mRadius(r), mHeight(h) { }
Cylinder::~Cylinder() {}

std::vector<std::vector<Point>> Cylinder::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point center, surface(mRadius, 0, 0);
	std::vector<Point> p72;
	std::vector<Point> bottom_pt;
	std::vector<Point> top_pt;
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + getradius() * std::cos(theta);
		double y = center.Y() + getradius() * std::sin(theta);
		double z = center.Z();
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + getradius() * std::cos(theta);
		double y = center.Y() + getradius() * std::sin(theta);
		double z = center.Z() + mHeight;
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + getradius() * std::cos(theta);
		double y = center.Y() + getradius() * std::sin(theta);
		double z = center.Z();
		bottom_pt.emplace_back(x, y, z);
	}
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + getradius() * std::cos(theta);
		double y = center.Y() + getradius() * std::sin(theta);
		double z = center.Z() + mHeight;
		top_pt.emplace_back(x, y, z);
	}
	for (int i = 0; i < N; ++i) cord.push_back({ bottom_pt[i], top_pt[i] });
	bottom_pt.clear();
	top_pt.clear();
	return cord;
}
void Cylinder::save(std::ostream& fout) const
{
	fout << getName() << "\n"
		 << "r = " << getradius() << "| "
		 << "h = " << getheight() << "\n";
}
void Cylinder::saveForGnu(std::ostream& fout) const
{
	fout << getName() << "\n";
	for (auto& it : getCoordinates())
	{
		for (auto& cord : it) fout << cord.X() << " " << cord.Y() << " " << cord.Z() << "\n";
		fout << "\n\n";
	}
}

double Cylinder::getradius() const { return mRadius; }
double Cylinder::getheight() const { return mHeight; }