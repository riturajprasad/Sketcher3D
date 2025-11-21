#include "pch.h"
#include "Sphere.h"

Sphere::Shape(const Point& cen, const Point& sur) : Shape("Sphere"), center(cen), surface(sur) {}
Sphere::Shape(const double& radius) : Shape("Sphere"), center(0, 0, 0), Surface(radius, 0, 0) {}
Sphere::~Sphere() {}

std::vector<std::pair<Point, Point>> Sphere::getCoordinates() const
{
	std::vector<std::pair<Point, Point>> cord;
	cord.push_back({ center, surface });
	return cord;
}

double getradius() const { return (surface.x - center.x) }

std::ostream& operator<<(std::ostream& out, const Sphere& s)
{
	//out << s.getName() << "\n";
	for (auto cord : s.getCoordinates())
	{
		out << cord.first.x << " " << cord.first.y << " " << cord.first.z << "\n";
		out << cord.second.x << " " << cord.second.y << " " << cord.second.z << "\n\n\n";
	}
	return out;
}