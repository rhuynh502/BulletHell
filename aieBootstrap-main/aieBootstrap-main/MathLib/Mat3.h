#pragma once
#include "Vec2.h"
#include <math.h>
#include "Vec3.h"

class Mat3
{
public:
	float m1, m2, m3, m4, m5, m6, m7, m8, m9;

	Mat3();

	Mat3(float _m1, float _m4, float _m7,
		float _m2, float _m5, float _m8,
		float _m3, float _m6, float _m9);
	
	~Mat3();

	static Mat3* CreateTranslation(float _tx, float _ty);

	static Mat3* CreateScale(float _sx, float _sy);
	
	Mat3* CreateXRotation(float _rot);
	Mat3* CreateYRotation(float _rot);
	Mat3* CreateZRotation(float _rot);

	void SetRotationX(float _xRot);
	void SetRotationY(float _yRot);
	void SetRotationZ(float _zRot);

	float GetRotationX();
	float GetRotationY();
	float GetRotationZ();

	void SetTranslation(float _tx, float _ty);
	void Translate(float _xAmount, float _yAmount);

	Vec2* GetTranslation();

	void SetScale(float _xs, float _ys, float _zs = 1);

	Vec2* GetScale();

	Mat3* Multiply(Mat3* _rhs);
	Vec3* operator*(Vec3 _rhs);

	Vec2* TransformPoint(Vec2 _point);
	Vec2* TransformVector(Vec2 _vector);

};

