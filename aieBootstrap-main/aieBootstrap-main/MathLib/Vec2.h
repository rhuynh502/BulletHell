#pragma once
#include <iostream>


class Vec2
{
public:
	/*static const Vec2* Zero;
	static const Vec2* Half;
	static const Vec2* One;*/

	float x = 0;
	float y = 0;

	Vec2();
	Vec2(float _x, float _y);
	~Vec2();

	//void InitialiseDefaults();

	Vec2* Add(Vec2 _vec1, Vec2 _vec2);
	Vec2* operator+(Vec2 _vec1);

	Vec2* Sub(Vec2 _vec1, Vec2 _vec2);
	Vec2* operator-(Vec2 _vec1);

	Vec2* Scale(Vec2 _vec1, float _scale);
	Vec2* operator*(float _scale);

	float Magnitude();
	void Normalise();

	float Dot(Vec2 _rhs);
	float Distance(Vec2 _tail);

	static Vec2* CreateRotationVector(float _radians);
	float Rotation();

	void Rotate(float _amount);
	void RotateAround(Vec2 _pivot, float _amount);

	bool operator==(Vec2 _rhs);
	bool operator!=(Vec2 _rhs);

};

