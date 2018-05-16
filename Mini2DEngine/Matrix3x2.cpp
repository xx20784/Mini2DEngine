#include "pch.h"
#include "Matrix3x2.h"

Matrix3x2::Matrix3x2(Vector2 _dirX, Vector2 _dirY, Vector2 _o)
	:dirX(_dirX), dirY(_dirY), Origin(_o) {}

Matrix3x2::Matrix3x2(float _00, float _01, float _10, float _11, float _20, float _21)
{
	dirX.X = _00;   dirX.Y = _01;
	dirY.X = _10;   dirY.Y = _11;
	Origin.X = _20; Origin.Y = _21;
}



const D2D1::Matrix3x2F Matrix3x2::D2DMatrixF() const
{
	D2D1::Matrix3x2F mat;

	mat._11 = (FLOAT)dirX.X;   mat._12 = (FLOAT)dirX.Y;
	mat._21 = (FLOAT)dirY.X;   mat._22 = (FLOAT)dirY.Y;
	mat._31 = (FLOAT)Origin.X; mat._32 = (FLOAT)Origin.Y;

	return mat;
}

void Matrix3x2::Matrix3x2Inverse()
{
	float det = dirX.X * dirY.Y - dirX.Y * dirY.X;

	dirY.Y /= det; dirX.Y /= -det;
	dirY.X /= -det; dirX.X /= det;
	Origin.X = (dirY.X * Origin.Y - dirY.Y * Origin.X) / det;
	Origin.Y = -(dirX.Y * Origin.Y - dirX.Y * Origin.X) / det;
}

void Matrix3x2::Matrix3x2Scaling(float _val)
{
	Matrix3x2Scaling(_val, _val);
}

void Matrix3x2::Matrix3x2Scaling(float _valX, float _valY)
{
	dirX.X = _valX;  dirX.Y = 0.0f;
	dirY.X = 0.0f;   dirY.Y = _valY;
	Origin.X = 0.0f; Origin.Y = 0.0f;
}

void Matrix3x2::Matrix3x2RotationAxis(float _axis)
{
	dirX.X = cos(_axis); dirX.Y = sin(_axis);
	dirY.X = -sin(_axis); dirY.Y = cos(_axis);
	Origin.X = 0.0f;     Origin.Y = 0.0f;
}

void Matrix3x2::Matrix3x2Translation(float _valX, float _valY)
{
	dirX.X = 1.0f;    dirX.Y = 0.0f;
	dirY.X = 0.0f;    dirY.Y = 1.0f;
	Origin.X = _valX; Origin.Y = _valY;
}



Matrix3x2 Matrix3x2::operator*(const Matrix3x2& _rhs) const
{
	return Matrix3x2(Vector2(dirX.X * _rhs.dirX.X + dirX.Y * _rhs.dirY.X, dirX.X * _rhs.dirX.Y + dirX.Y * _rhs.dirY.Y),
		Vector2(dirY.X * _rhs.dirX.X + dirY.Y * _rhs.dirY.X, dirY.X * _rhs.dirX.Y + dirY.Y * _rhs.dirY.Y),
		Vector2(Origin.X * _rhs.dirX.X + Origin.Y * _rhs.dirY.X + _rhs.Origin.X, Origin.X * _rhs.dirX.Y + Origin.Y * _rhs.dirY.Y + _rhs.Origin.Y));
}