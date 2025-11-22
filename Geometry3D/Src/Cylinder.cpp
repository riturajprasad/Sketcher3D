#include "pch.h"
#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder(const Point& cen, const Point& sur, const double& height) : Shape("Cylinder"), center(cen),
surface((std::sqrt(pow((sur.x - cen.x), 2) + pow((sur.y - cen.y), 2) + pow((sur.z - cen.z), 2))), cen.y, cen.z),
height(height)
{ }
Cylinder::Cylinder(const double& radius, const double& height) : Shape("Sphere"), center(0, 0, 0),
surface(radius, 0, 0), height(height) {}
Cylinder::~Cylinder() {}

std::vector<std::vector<Point>> Cylinder::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	std::vector<Point> p72;
	std::vector<Point> bottom_pt;
	std::vector<Point> top_pt;
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y + getradius() * std::sin(theta);
		double z = center.z;
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y + getradius() * std::sin(theta);
		double z = center.z + height;
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y + getradius() * std::sin(theta);
		double z = center.z;
		bottom_pt.emplace_back(x, y, z);
	}
	for (int i = 0; i < N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y + getradius() * std::sin(theta);
		double z = center.z + height;
		top_pt.emplace_back(x, y, z);
	}
	for (int i = 0; i < N; ++i) cord.push_back({ bottom_pt[i], top_pt[i] });
	bottom_pt.clear();
	top_pt.clear();
	return cord;
}

double Cylinder::getradius() const { return std::fabs(surface.x - center.x); }
double Cylinder::getheight() const { return height; }

std::ostream& operator<<(std::ostream& out, const Cylinder& c)
{
	out << c.getName() << "\n";
	for (auto& it : c.getCoordinates())
	{
		for (auto& cord : it) out << cord.x << " " << cord.y << " " << cord.z << "\n";
		out << "\n\n";
	}
	return out;
}