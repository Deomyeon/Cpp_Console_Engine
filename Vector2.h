#pragma once

#include <vector>
#include <algorithm>

class Vector2
{
public:
	float x;
	float y;
	static const Vector2 zero;
	static const Vector2 one;


	Vector2(float x, float y);
	~Vector2();

	std::vector<Vector2> GetLine(Vector2 target);
	float GetDistance(Vector2 target);

	static std::vector<Vector2> GetMeshTriangle(std::vector<Vector2>&& triangle);
	static std::vector<Vector2> GetWireFrameTriangle(std::vector<Vector2>&& triangle);


	inline Vector2 operator +(Vector2 target) const
	{
		return Vector2(this->x + target.x, this->y + target.y);
	}
	inline Vector2 operator -(Vector2 target) const
	{
		return Vector2(this->x - target.x, this->y - target.y);
	}
	inline Vector2 operator *(float target) const
	{
		return Vector2(this->x * target, this->y * target);
	}
	inline Vector2 operator /(float target) const
	{
		return Vector2(this->x / target, this->y / target);
	}
	inline Vector2 operator =(Vector2 target) const
	{
		return target;
	}
	inline bool operator ==(Vector2 target) const
	{
		return (this->x == target.x && this->y == target.y);
	}
	inline bool operator <(Vector2 target) const
	{
		return (this->x < target.x && this->y < target.y);
	}
	inline bool operator >(Vector2 target) const
	{
		return (this->x > target.x&& this->y > target.y);
	}
	inline bool operator <=(Vector2 target) const
	{
		return (this->x <= target.x&& this->y <= target.y);
	}
	inline bool operator >=(Vector2 target) const
	{
		return (this->x >= target.x && this->y >= target.y);
	}
	inline bool operator !=(Vector2 target) const
	{
		return (this->x != target.x && this->y != target.y);
	}

};