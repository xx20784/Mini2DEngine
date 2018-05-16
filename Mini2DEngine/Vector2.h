#pragma once
#include "pch.h"

struct Vector2
{
	float X = 0.0f;
	float Y = 0.0f;

	Vector2() = default;
	Vector2(float _x, float _y);

	// Vector�� ���� ����.
	void Inverse();
	// Vector�� ����ȭ��.
	void Normalize();
	// Vector�� ũ�⸦ ����.
	float Length() const;
	// �ٸ� Vector���� �Ÿ��� ����.
	float Distance(const Vector2& _vec) const;

	// Operator Overloading.
	Vector2  operator+ (const Vector2& _rhs) const;
	Vector2& operator+=(const Vector2& _rhs);
	Vector2  operator- (const Vector2& _rhs) const;
	Vector2& operator-=(const Vector2& _rhs);
	Vector2  operator* (const Vector2& _rhs) const;
	Vector2& operator*=(const Vector2& _rhs);
	Vector2  operator* (const float _val) const;
	Vector2& operator*=(const float _val);
	Vector2  operator/ (const float _val) const;
	Vector2& operator/=(const float _val);
	bool operator==(const Vector2& _rhs) const;
	bool operator!=(const Vector2& _rhs) const;
};