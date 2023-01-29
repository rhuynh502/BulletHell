#pragma once
#include <iostream>
#include <math.h>

class Vec3
{
public:
	float x, y, z;

	Vec3();
	Vec3(float _x, float _y, float _z);

	static Vec3* Add(Vec3 _lhs, Vec3 _rhs);
	static Vec3* Subtract(Vec3 _lhs, Vec3 _rhs);

	Vec3* operator+(Vec3 _rhs);
	Vec3* operator-(Vec3 _rhs);

	static Vec3* PostScale(Vec3 _lhs, float _amount);
	static Vec3* PreScale(float _amount, Vec3 _rhs);
	void Scale(float _amount);
	Vec3* operator*(float _amount);
	void operator*=(float _amount);

	float Magnitude();
	static Vec3* Normalise(Vec3 _vec);
	void Normalise();

	static float Dot(Vec3 _lhs, Vec3 _rhs);
	float Dot(Vec3 _rhs);
	static Vec3* Cross(Vec3 _lhs, Vec3 _rhs);
	Vec3* Cross(Vec3 _rhs);

};

