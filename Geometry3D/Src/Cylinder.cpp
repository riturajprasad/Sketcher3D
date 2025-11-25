#include "pch.h"
#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder(const std::string& name, double r, double h) : Shape("Cylinder", name),
mRadius(r), mHeight(h) { }
Cylinder::~Cylinder() {}

const std::vector<std::vector<Point>>& Cylinder::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point center, surface(mRadius, 0, 0);
	std::vector<Point> p72;
	std::vector<Point> bottom_pt;
	std::vector<Point> top_pt;
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + getradius() * std::cos(theta);
		double y = center.getY() + getradius() * std::sin(theta);
		double z = center.getZ();
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + getradius() * std::cos(theta);
		double y = center.getY() + getradius() * std::sin(theta);
		double z = center.getZ() + mHeight;
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + getradius() * std::cos(theta);
		double y = center.getY() + getradius() * std::sin(theta);
		double z = center.getZ();
		bottom_pt.emplace_back(x, y, z);
	}
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + getradius() * std::cos(theta);
		double y = center.getY() + getradius() * std::sin(theta);
		double z = center.getZ() + mHeight;
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
		for (auto& cord : it) fout << cord.getX() << " " << cord.getY() << " " << cord.getZ() << "\n";
		fout << "\n\n";
	}
}

double Cylinder::getradius() const { return mRadius; }
double Cylinder::getheight() const { return mHeight; }