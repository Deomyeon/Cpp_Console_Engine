#pragma once

#include <array>
#include "Vector3.h"


class Triangle
{
public:
	std::array<Vector3, 3> vertices;

	Triangle(std::array<Vector3, 3>&& vertices);
	~Triangle();
};