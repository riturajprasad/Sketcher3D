#include "pch.h"
#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const std::string& name, double r) : Shape("Sphere", name), mRadius(r) {}
Sphere::~Sphere() {}

const std::vector<std::vector<Point>>& Sphere::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point center, surface(mRadius, 0, 0);
	std::vector<Point> p72;
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
		double y = center.getY();
		double z = center.getZ() + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX();
		double y = center.getY() + getradius() * std::cos(theta);
		double z = center.getZ() + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.getY() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.getZ() + (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.getY() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.getZ() - (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.getY() + (getradius() / 2.0);
		double z = center.getZ() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.getY() - (getradius() / 2.0);
		double z = center.getZ() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() + (getradius() / 2.0);
		double y = center.getY() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.getZ() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.getX() - (getradius() / 2.0);
		double y = center.getY() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.getZ() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	return cord;
}
void Sphere::save(std::ostream& fout) const
{
	fout << getName() << "\n"
		<< "r = " << getradius() << "\n";
}
void Sphere::saveForGnu(std::ostream& fout) const
{
	fout << getName() << "\n";
	for (auto& it : getCoordinates())
	{
		for (auto& cord : it) fout << cord.getX() << " " << cord.getY() << " " << cord.getZ() << "\n";
		fout << "\n\n";
	}
}

double Sphere::getradius() const { return mRadius; }