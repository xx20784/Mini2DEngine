#pragma once
#include "pch.h"
#include "GameObject.h"

struct Matrix3x2;

class CameraObject : public GameObject
{
public:
	virtual ~CameraObject() = default;

public:
	const Matrix3x2 GetViewMatrix() const;
};