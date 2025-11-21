#pragma once
#include "Export.h"
#include <string>

class GEOMETRY3D_API Object_3D
{
protected:
	std::string name;

public:
	Object_3D(const std::string&);
	virtual ~Object_3D();

	virtual std::string getName() const = 0;
};