#include "pch.h"
#include "CameraObject.h"

#include "Matrix3x2.h"
#include "TransformComponent.h"

const Matrix3x2 CameraObject::GetViewMatrix() const
{
	Matrix3x2 viewMat = GetComponent<TransformComponent>()->GetWorldMatrix();
	viewMat.Matrix3x2Inverse();

	return viewMat;
}