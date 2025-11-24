#include "pch.h"
#include "Shape.h"

Shape::Shape(const std::string& name) : mName(name) {}

Shape::~Shape() {}

std::string Shape::getName() const { return mName; }