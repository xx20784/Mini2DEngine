#pragma once
#include "pch.h"
#include "Vector2.h"

struct Matrix3x2
{
	Vector2 dirX = { 1.0f, 0.0f };
	Vector2 dirY = { 0.0f, 1.0f };
	Vector2 Origin = { 0.0f, 0.0f };

	Matrix3x2() = default;
	Matrix3x2(Vector2 _dirX, Vector2 _dirY, Vector2 _o);
	Matrix3x2(float _00, float _01, float _10, float _11, float _20, float _21);

	// D2D용 Matrix3x2F 변환.
	const D2D1::Matrix3x2F D2DMatrixF() const;
	// 역행렬로 변환.
	void Matrix3x2Inverse();
	// 비례행렬로 변환.
	void Matrix3x2Scaling(float _val);
	void Matrix3x2Scaling(float _valX, float _valY);
	// 회전행렬로 변환.
	void Matrix3x2RotationAxis(float _axis);
	// 이동행렬로 변환
	void Matrix3x2Translation(float _valX, float _valY);

	// 연산자 Overloading.
	Matrix3x2 operator*(const Matrix3x2& _rhs) const;
};