#include "pch.h"
#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const double& r, const std::string& name) : Shape(name), mRadius(r) {}
Sphere::~Sphere() {}

std::vector<std::vector<Point>> Sphere::getCoordinates() const
{
	std::vector<std::vector<Point>> cord;
	Point center, surface(mRadius, 0, 0);
	std::vector<Point> p72;
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
		double y = center.Y();
		double z = center.Z() + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X();
		double y = center.Y() + getradius() * std::cos(theta);
		double z = center.Z() + getradius() * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.Y() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.Z() + (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.Y() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		double z = center.Z() - (getradius() / 2.0);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.Y() + (getradius() / 2.0);
		double z = center.Z() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double y = center.Y() - (getradius() / 2.0);
		double z = center.Z() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() + (getradius() / 2.0);
		double y = center.Y() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.Z() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
		p72.emplace_back(x, y, z);
	}
	cord.push_back(p72);
	p72.clear();
	for (int i = 0; i <= N; ++i) {
		double theta = 2.0 * M_PI * i / N;
		double x = center.X() - (getradius() / 2.0);
		double y = center.Y() + (std::sqrt(3.0) * getradius() / 2.0) * std::cos(theta);
		double z = center.Z() + (std::sqrt(3.0) * getradius() / 2.0) * std::sin(theta);
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
		for (auto& cord : it) fout << cord.X() << " " << cord.Y() << " " << cord.Z() << "\n";
		fout << "\n\n";
	}
}

double Sphere::getradius() const { return mRadius; }