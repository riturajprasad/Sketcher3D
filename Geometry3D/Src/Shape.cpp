#include "pch.h"
#include "Shape.h"

Shape::Shape(const std::string& n) : Object_3D(n) {}

Shape::~Shape() {}

std::string Shape::getName() const { return name; }