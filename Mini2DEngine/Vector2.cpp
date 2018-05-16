#include "pch.h"
#include "Vector2.h"

Vector2::Vector2(float _x, float _y)
	:X(_x), Y(_y)
{}



void Vector2::Inverse()
{
	X = -X;
	Y = -Y;
}

void Vector2::Normalize()
{
	float val = 1.0f / Length();

	X *= val;
	Y *= val;
}

float Vector2::Length() const
{
	return sqrtf(pow(X, 2) + pow(Y, 2));
}

float Vector2::Distance(const Vector2& _vec) const
{
	float dtX = _vec.X - X;
	float dtY = _vec.Y - Y;

	return sqrtf(pow(dtX, 2) + pow(dtY, 2));
}



Vector2 Vector2::operator+(const Vector2& _rhs) const
{
	return Vector2(X + _rhs.X, Y + _rhs.Y);
}


Vector2& Vector2::operator+=(const Vector2& _rhs)
{
	X += _rhs.X;
	Y += _rhs.Y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& _rhs) const
{
	return Vector2(X - _rhs.X, Y - _rhs.Y);
}

Vector2& Vector2::operator-=(const Vector2& _rhs)
{
	X -= _rhs.X;
	Y -= _rhs.Y;

	return *this;
}

Vector2 Vector2::operator*(const Vector2& _rhs) const
{
	return Vector2(X * _rhs.X, Y * _rhs.Y);
}

Vector2& Vector2::operator*=(const Vector2& _rhs)
{
	X *= _rhs.X;
	Y *= _rhs.Y;

	return *this;
}

Vector2 Vector2::operator*(const float _val) const
{
	return Vector2(X * _val, Y * _val);
}

Vector2& Vector2::operator*=(const float _val)
{
	X *= _val;
	Y *= _val;

	return *this;
}

Vector2 Vector2::operator/(const float _val) const
{
	return Vector2(X / _val, Y / _val);
}

Vector2& Vector2::operator/=(const float _val)
{
	X /= _val;
	Y /= _val;

	return *this;
}

bool Vector2::operator==(const Vector2& _rhs) const
{
	if ((X == _rhs.X) && (Y == _rhs.Y)) {
		return true;
	}
	return false;
}

bool Vector2::operator!=(const Vector2& _rhs) const
{
	if ((X != _rhs.X) || (Y != _rhs.Y)) {
		return true;
	}
	return false;
}