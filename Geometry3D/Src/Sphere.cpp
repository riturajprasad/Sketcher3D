#include "pch.h"
#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Point& cen, const Point& sur) : Shape("Sphere"), center(cen),
surface((std::sqrt(pow((sur.x - cen.x), 2) + pow((sur.y - cen.y), 2) + pow((sur.z - cen.z), 2))), cen.y, cen.z)
{ }
Sphere::Sphere(const double& radius) : Shape("Sphere"), center(0, 0, 0), surface(radius, 0, 0) {}
Sphere::~Sphere() {}

std::vector<std::vector<Point>> Sphere::getCoordinates() const
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
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + getradius() * std::cos(theta);
		double y = center.y;
		double z = center.z + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x;
		double y = center.y + getradius() * std::cos(theta);
		double z = center.z + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.y + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.z + (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.y + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.z - (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.y + (getradius() / 2.0);
		double z = center.z + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.y - (getradius() / 2.0);
		double z = center.z + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x + (getradius() / 2.0);
		double y = center.y + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.z + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * PI * i / N;
		double x = center.x - (getradius() / 2.0);
		double y = center.y + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.z + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	return cord;
}

double Sphere::getradius() const { return std::fabs(surface.x - center.x); }

std::ostream& operator<<(std::ostream& out, const Sphere& s)
{
	out << s.getName() << "\n";
	for (auto& it : s.getCoordinates())
	{
		for (auto& cord : it) out << cord.x << " " << cord.y << " " << cord.z << "\n";
		out << "\n\n";
	}
	return out;
}