#include "pch.h"
#include "TransformComponent.h"

#include "GameObject.h"

void TransformComponent::Update()
{
	Matrix3x2 matParent = {};
	// �θ� ������Ʈ�� �ִٸ�
	if (m_owner->GetParent() != nullptr) {
		// �θ� ������Ʈ�� ���� ����� ���Ѵ�.
		matParent = m_owner->GetParent()->GetComponent<TransformComponent>()->GetWorldMatrix();
	}

	// ��ü�� ��ǥ�踦 ������ǥ��� �����
	Matrix3x2 matLocal = {};
	// ũ�� ��ȯ�� �����(S)
	Matrix3x2 matScale = {};
	matScale.Matrix3x2Scaling(m_scale.X, m_scale.Y);
	// ȸ�� ��ȯ�� �����(R)
	Matrix3x2 matRot = {};
	matRot.Matrix3x2RotationAxis(m_axis);
	// �̵� ��ȯ�� �����.(T)
	Matrix3x2 matTrans = {};
	matTrans.Matrix3x2Translation(m_pos.X, m_pos.Y);
	// ������� = Local * S * R * T * P
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