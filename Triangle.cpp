#include "Triangle.h"

Triangle::Triangle(std::array<Vector3, 3>&& vertices) : vertices(vertices){}
Triangle::~Triangle() {}