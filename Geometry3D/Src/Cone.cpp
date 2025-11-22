#include "pch.h"
#include "Cone.h"
#include <cmath>

Cone::Cone(const Point& cen, const Point& sur, const double& h) : Shape("Cone"), center(cen),
surface((std::sqrt(pow((sur.x - cen.x), 2) + pow((sur.y - cen.y), 2) + pow((sur.z - cen.z), 2))), cen.y, cen.z),
height(h), h_pt(cen.x, cen.y, h) { }
Cone::Cone(const double& r, const double& h) : Shape("Cone"), center(0, 0, 0),
surface(r, 0, 0), height(h), h_pt(0, 0, h) { }
Cone::~Cone() {}

std::vector<std::vector<Point>> Cone::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	std::vector<Point> p72;
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y + getradius() * std::sin(theta);
		double z = center.z;
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	for (int i = 0; i < N; i+=2) cord.push_back({ p72[i], h_pt });
	p72.clear();
	return cord;
}

double Cone::getradius() const { return std::fabs(surface.x - center.x); }
double Cone::getheight() const { return height; }
double Cone::getslant_height() const
{
	return std::fabs(std::sqrt(pow((h_pt.x - surface.x), 2) + pow((h_pt.y - surface.y), 2) + pow((h_pt.z - surface.z), 2)));
}

std::ostream& operator<<(std::ostream& out, const Cone& c)
{
	out << c.getName() << "\n";
	for (auto& it : c.getCoordinates())
	{
		for (auto& cord : it) out << cord.x << " " << cord.y << " " << cord.z << "\n";
		out << "\n\n";
	}
	return out;
}