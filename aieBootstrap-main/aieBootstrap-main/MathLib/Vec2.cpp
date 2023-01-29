#include "Vec2.h"

Vec2::Vec2()
{
	//InitialiseDefaults();
}

Vec2::Vec2(float _x, float _y)
{
	x = _x;
	y = _y;

	//InitialiseDefaults();
}


Vec2::~Vec2()
{
	/*delete Zero;
	delete Half;
	delete One;*/
}

Vec2* Vec2::Add(Vec2 _vec1, Vec2 _vec2)
{
	return new Vec2(
		_vec1.x + _vec2.x,
		_vec1.y + _vec2.y
	);
}

Vec2* Vec2::operator+(Vec2 _vec1)
{
	return new Vec2(
		_vec1.x + x,
		_vec1.y + y
	);
}

Vec2* Vec2::Sub(Vec2 _vec1, Vec2 _vec2)
{
	return new Vec2(
		_vec1.x - _vec2.x,
		_vec1.y - _vec2.y
	);
}

Vec2* Vec2::operator-(Vec2 _vec1)
{
	return new Vec2(
		x - _vec1.x,
		y - _vec1.y
	);
}

Vec2* Vec2::Scale(Vec2 _vec1, float _scale)
{
	return new Vec2(
		_vec1.x * _scale,
		_vec1.y * _scale
	);
}

float Vec2::Magnitude()
{
	return std::sqrt(x * x + y * y);
}

void Vec2::Normalise()
{
	float length = Magnitude();
	if (length == 0)
	{
		x = 0;
		y = 0;
	}
	else
	{
		x /= length;
		y /= length;
	}
}

float Vec2::Dot(Vec2 _rhs)
{
	return (x * _rhs.x) + (y * _rhs.y);
}

float Vec2::Distance(Vec2 _tail)
{
	return ((new Vec2(x - _tail.x, y - _tail.y))->Magnitude());
}

Vec2* Vec2::CreateRotationVector(float _radians)
{
	return new Vec2(std::cos(_radians), std::sin(_radians));
}

float Vec2::Rotation()
{
	return std::atan2(y, x);
}

void Vec2::Rotate(float _amount)
{
	auto xRotated = x * std::cos(_amount) - y * std::sin(_amount);
	auto yRotated = x * std::sin(_amount) + y * std::cos(_amount);

	x = xRotated;
	y = yRotated;
}

void Vec2::RotateAround(Vec2 _pivot, float _amount)
{
	x -= _pivot.x;
	y -= _pivot.y;

	Rotate(_amount);

	x += _pivot.x;
	y += _pivot.y;
}

bool Vec2::operator==(Vec2 _rhs)
{
	return x == _rhs.x && y == _rhs.y;
}

bool Vec2::operator!=(Vec2 _rhs)
{
	return !(x == _rhs.x && y == _rhs.y);
}

Vec2* Vec2::operator*(float _scale)
{
	return new Vec2(
		x * _scale,
		y * _scale
	);
}

//void Vec2::InitialiseDefaults()
//{
//	Zero = new Vec2(0, 0);
//	Half = new Vec2(0.5, 0.5);
//	One = new Vec2(1, 1);
//
//}
