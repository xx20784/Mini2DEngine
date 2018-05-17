#include "pch.h"
#include "TransformComponent.h"

#include "GameObject.h"

void TransformComponent::Update()
{
	Matrix3x2 matParent = {};
	// 부모 오브젝트가 있다면
	if (m_owner->GetParent() != nullptr) {
		// 부모 오브젝트의 세계 행렬을 구한다.
		matParent = m_owner->GetParent()->GetComponent<TransformComponent>()->GetWorldMatrix();
	}

	// 객체의 좌표계를 국소좌표계로 만들고
	Matrix3x2 matLocal = {};
	// 크기 변환을 만들고(S)
	Matrix3x2 matScale = {};
	matScale.Matrix3x2Scaling(m_scale.X, m_scale.Y);
	// 회전 변환을 만들고(R)
	Matrix3x2 matRot = {};
	matRot.Matrix3x2RotationAxis(m_axis);
	// 이동 변환을 만든다.(T)
	Matrix3x2 matTrans = {};
	matTrans.Matrix3x2Translation(m_pos.X, m_pos.Y);
	// 최종행렬 = Local * S * R * T * P
	m_worldMat = matLocal * matScale * matRot * matTrans * matParent;
}

void TransformComponent::Draw()
{}



void TransformComponent::Translate(float _x, float _y)
{
	Vector2 temp = { _x, _y };
	m_pos += temp;
}

void TransformComponent::Scale(float _x, float _y)
{
	Vector2 temp = { _x, _y };
	m_scale = temp;
}

void TransformComponent::Rotate(float _axis)
{
	m_axis += _axis;
}



const Matrix3x2& TransformComponent::GetWorldMatrix() const
{
	return m_worldMat;
}