#include "Vector2.h"


const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::one = Vector2(1, 1);


Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::~Vector2() {}


std::vector<Vector2> Vector2::GetMeshTriangle(std::vector<Vector2>&& triangle)
{
	std::vector<Vector2> result;
	for (int i = 0; i < triangle.size(); i++)
	{
		std::vector<Vector2> v = triangle[i].GetLine(triangle[(i + 1) % triangle.size()]);
		for (int j = 0; j < v.size(); j++)
		{
			std::vector<Vector2> v2 = v[j].GetLine(triangle[(i + 2) % triangle.size()]);
			for (int a = 0; a < v2.size(); a++)
			{
				result.push_back(v2[a]);
			}
		}
	}
	std::unique(result.begin(), result.end());
	return result;
}

std::vector<Vector2> Vector2::GetWireFrameTriangle(std::vector<Vector2>&& triangle)
{
	std::vector<Vector2> result;
	for (int i = 0; i < triangle.size(); i++)
	{
		std::vector<Vector2> v = triangle[i].GetLine(triangle[(i + 1) % triangle.size()]);
		for (int j = 0; j < v.size(); j++)
		{
			result.push_back(v[j]);
		}
	}
	std::unique(result.begin(), result.end());
	return result;
}


std::vector<Vector2> Vector2::GetLine(Vector2 target)
{
	std::vector<Vector2> result;

	Vector2 current = target - *this;
	for (Vector2 v = *this; !(Vector2((int)abs((target - v).x), (int)abs((target - v).y)) == Vector2::zero);)
	{
		result.push_back(v);
		if (abs(current.x) < abs(current.y))
		{
			float ay = current.y / current.x;
			(target.x > v.x) ? v.x += 1 / abs(ay) : v.x -= 1 / abs(ay);
			(target.y > v.y) ? v.y++ : v.y--;
		}
		else
		{
			float ax = current.x / current.y;
			(target.x > v.x) ? v.x++ : v.x--;
			(target.y > v.y) ? v.y += 1 / abs(ax) : v.y -= 1 / abs(ax);
		}
	}

	return result;
}

float Vector2::GetDistance(Vector2 target)
{
	return sqrtf(powf(target.x - this->x, 2) + powf(target.y - this->y, 2));
}