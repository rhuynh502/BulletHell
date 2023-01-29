#include "Vec3.h"

Vec3::Vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vec3* Vec3::Add(Vec3 _lhs, Vec3 _rhs)
{
	return new Vec3(_lhs.x + _rhs.x, _lhs.y + _rhs.y, _lhs.z + _rhs.z);
}

Vec3* Vec3::Subtract(Vec3 _lhs, Vec3 _rhs)
{
	return new Vec3(_lhs.x - _rhs.x, _lhs.y - _rhs.y, _lhs.z - _rhs.z);
}

Vec3* Vec3::operator+(Vec3 _rhs)
{
	return new Vec3(x + _rhs.x, y + _rhs.y, z + _rhs.z);
}

Vec3* Vec3::operator-(Vec3 _rhs)
{
	return new Vec3(x - _rhs.x, y - _rhs.y, z - _rhs.z);
}

Vec3* Vec3::PostScale(Vec3 _lhs, float _amount)
{
	return new Vec3(_lhs.x * _amount, _lhs.y * _amount, _lhs.z * _amount);
}

Vec3* Vec3::PreScale(float _amount, Vec3 _rhs)
{
	return new Vec3(_rhs.x * _amount, _rhs.y * _amount, _rhs.z * _amount);
}

void Vec3::Scale(float _amount)
{
	x *= _amount;
	y *= _amount;
	z *= _amount;
}

Vec3* Vec3::operator*(float _amount)
{
	return new Vec3(x * _amount, y * _amount, z * _amount);
}

void Vec3::operator*=(float _amount)
{
	x* _amount;
	y* _amount;
	z* _amount;
}

float Vec3::Magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

Vec3* Vec3::Normalise(Vec3 _vec)
{
	float length = _vec.Magnitude();

	if (length != 0)
	{
		return new Vec3(_vec.x / length, _vec.y / length, _vec.z / length);
	}

	return new Vec3(0, 0, 0);
}

void Vec3::Normalise()
{
	float length = Magnitude();

	if (length != 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
	}

}

float Vec3::Dot(Vec3 _lhs, Vec3 _rhs)
{
	return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
}

float Vec3::Dot(Vec3 _rhs)
{
	return x * _rhs.x + y * _rhs.y + z * _rhs.z;
}

Vec3* Vec3::Cross(Vec3 _lhs, Vec3 _rhs)
{
	return new Vec3(_lhs.y * _rhs.z - _rhs.y * _lhs.z, _lhs.z * _rhs.x - _rhs.z * _lhs.x, _lhs.x * _rhs.y - _rhs.x * _lhs.y);
}

Vec3* Vec3::Cross(Vec3 _rhs)
{
	return new Vec3(y * _rhs.z - _rhs.y * z, z * _rhs.x - _rhs.z * x, x * _rhs.y - _rhs.x * y);
}
