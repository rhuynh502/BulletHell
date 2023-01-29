#include "Mat3.h"

Mat3::Mat3()
{
	m1 = 1; m2 = 0; m3 = 0;
	m4 = 0; m5 = 1; m6 = 0;
	m7 = 0; m8 = 0; m9 = 1;
}

Mat3::Mat3(float _m1, float _m4, float _m7,
		float _m2, float _m5, float _m8,
		float _m3, float _m6, float _m9)
{
	m1 = _m1; m2 = _m2; m3 = _m3;
	m4 = _m4; m5 = _m5; m6 = _m6;
	m7 = _m7; m8 = _m8; m9 = _m9;
}

Mat3::~Mat3()
{
}

Mat3* Mat3::CreateTranslation(float _tx, float _ty)
{
	return new Mat3(
		1, 0, _tx,
		0, 1, _ty,
		0, 0, 1
	);
}

Mat3* Mat3::CreateScale(float _sx, float _sy)
{
	return new Mat3(
		_sx, 0, 0,
		0, _sy, 0,
		0, 0, 1
	);
}

Mat3* Mat3::CreateXRotation(float _rot)
{
	float cos = std::cos(_rot);
	float sin = std::sin(_rot);

	return new Mat3(
		// xa  ya  za
		1, 0, 0,        // x
		0, cos, -sin,   // y
		0, sin, cos     // z
	);
}

Mat3* Mat3::CreateYRotation(float _rot)
{
	float cos = std::cos(_rot);
	float sin = std::sin(_rot);

	return new Mat3(
		//   xa   ya   za
		cos, 0, sin,   // x
		0, 1, 0,       // y
		-sin, 0, cos    // z
	);
}

Mat3* Mat3::CreateZRotation(float _rot)
{
	float cos = std::cos(_rot);
	float sin = std::sin(_rot);

	return new Mat3(
		cos, -sin, 0,
		sin, cos, 0,
		0, 0, 1
	);
}


void Mat3::SetRotationX(float _xRot)
{
	Vec3* yVec = new Vec3(m4, m5, m6);
	Vec3* zVec = new Vec3(m7, m8, m9);

	float yLen = yVec->Magnitude();
	float zLen = zVec->Magnitude();

	delete yVec;
	delete zVec;

	auto cos = std::cos(_xRot);
	auto sin = std::sin(_xRot);

	m5 = cos * yLen;    m8 = -sin * zLen;
	m6 = sin * yLen;    m9 = cos * zLen;
}

void Mat3::SetRotationY(float _yRot)
{
	Vec3* xVec = new Vec3(m1, m2, m3);
	Vec3* zVec = new Vec3(m7, m8, m9);

	auto xLen = xVec->Magnitude();
	auto zLen = zVec->Magnitude();

	delete xVec;
	delete zVec;

	auto cos = std::cos(_yRot);
	auto sin = std::sin(_yRot);

	m1 = cos * xLen;    m7 = sin * zLen;
	m3 = -sin * xLen;   m9 = cos * zLen;
}

void Mat3::SetRotationZ(float _zRot)
{
	Vec3* yVec = new Vec3(m4, m5, m6);
	Vec3* xVec = new Vec3(m1, m2, m3);

	auto yLen = yVec->Magnitude();
	auto xLen = xVec->Magnitude();

	auto cos = std::cos(_zRot);
	auto sin = std::sin(_zRot);

	m1 = cos * xLen;    m4 = -sin * yLen;
	m2 = sin * xLen;    m5 = cos * yLen;
}

float Mat3::GetRotationX()
{
	return std::atan2(m2, m1);
}

float Mat3::GetRotationY()
{
	return std::atan2(-m4, m5);
}

float Mat3::GetRotationZ()
{
	return std::atan2(m7, m9);
}

void Mat3::SetTranslation(float _tx, float _ty)
{
	m7 = _tx;
	m8 = _ty;
}

void Mat3::Translate(float _xAmount, float _yAmount)
{
	m7 += _xAmount;
	m8 += _yAmount;
}

Vec2* Mat3::GetTranslation()
{
	return new Vec2(m7, m8);
}

void Mat3::SetScale(float _xs, float _ys, float _zs)
{
	Vec3* xVec = new Vec3(m1, m2, m3);
	Vec3* yVec = new Vec3(m4, m5, m6);

	xVec->Normalise();
	yVec->Normalise();

	xVec->Scale(_xs);
	yVec->Scale(_ys);

	m1 = xVec->x; m2 = xVec->y; m3 = xVec->z;
	m4 = yVec->x; m5 = yVec->y; m6 = yVec->z;
}

Vec2* Mat3::GetScale()
{
	Vec3* colx = new Vec3(m1, m2, m3);
	Vec3* coly = new Vec3(m4, m5, m6);

	float xMag = colx->Magnitude();
	float yMag = coly->Magnitude();

	delete colx;
	delete coly;

	return new Vec2(xMag, yMag);
}

Mat3* Mat3::Multiply(Mat3* _rhs)
{
	return new Mat3(
		m1 * _rhs->m1 + m2 * _rhs->m4 + m3 * _rhs->m7,
		m4 * _rhs->m1 + m5 * _rhs->m4 + m6 * _rhs->m7,
		m7 * _rhs->m1 + m8 * _rhs->m4 + m9 * _rhs->m7,

		m1 * _rhs->m2 + m2 * _rhs->m5 + m3 * _rhs->m8,
		m4 * _rhs->m2 + m5 * _rhs->m5 + m6 * _rhs->m8,
		m7 * _rhs->m2 + m8 * _rhs->m5 + m9 * _rhs->m8,

		m1 * _rhs->m3 + m2 * _rhs->m6 + m3 * _rhs->m9,
		m4 * _rhs->m3 + m5 * _rhs->m6 + m6 * _rhs->m9,
		m7 * _rhs->m3 + m8 * _rhs->m6 + m9 * _rhs->m9
	);
}

Vec3* Mat3::operator*(Vec3 _rhs)
{
	return new Vec3(
		_rhs.x * m1 + _rhs.y * m4 + _rhs.z * m7,
		_rhs.x * m2 + _rhs.y * m5 + _rhs.z * m8,
		_rhs.x * m3 + _rhs.y * m6 + _rhs.z * m9
	);
}

Vec2* Mat3::TransformPoint(Vec2 _point)
{
	return new Vec2(m7 + _point.x, m8 + _point.y);
}

Vec2* Mat3::TransformVector(Vec2 _vector)
{
	return new Vec2((m1 * _vector.x + m4 * _vector.y), (m2 * _vector.x + m5 * _vector.y));
}
