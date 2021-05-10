#pragma once

class Vector3
{
public:
	float x;
	float y;
	float z;
	static const Vector3 zero;
	static const Vector3 one;


	Vector3(float x, float y, float z);
	~Vector3();


	inline Vector3 operator +(Vector3 target) const
	{
		return Vector3(this->x + target.x, this->y + target.y, this->z + target.z);
	}
	inline Vector3 operator -(Vector3 target) const
	{
		return Vector3(this->x - target.x, this->y - target.y, this->z - target.z);
	}
	inline Vector3 operator *(float target) const
	{
		return Vector3(this->x * target, this->y * target, this->z * target);
	}
	inline Vector3 operator /(float target) const
	{
		return Vector3(this->x / target, this->y / target, this->z / target);
	}
	inline Vector3 operator =(Vector3 target) const
	{
		return target;
	}
	inline bool operator ==(Vector3 target) const
	{
		return (this->x == target.x && this->y == target.y && this->z == target.z);
	}
	inline bool operator <(Vector3 target) const
	{
		return (this->x < target.x && this->y < target.y && this->z < target.z);
	}
	inline bool operator >(Vector3 target) const
	{
		return (this->x > target.x && this->y > target.y && this->z > target.z);
	}
	inline bool operator <=(Vector3 target) const
	{
		return (this->x <= target.x && this->y <= target.y && this->z <= target.z);
	}
	inline bool operator >=(Vector3 target) const
	{
		return (this->x >= target.x && this->y >= target.y && this->z >= target.z);
	}
	inline bool operator !=(Vector3 target) const
	{
		return (this->x != target.x && this->y != target.y && this->z != target.z);
	}

};