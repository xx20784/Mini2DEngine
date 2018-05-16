#pragma once
#include "pch.h"
#include "Component.h"

#include "Matrix3x2.h"

// �̵� ����(���) ����� �����ϴ� Component.
class TransformComponent : public Component
{
public:
	virtual ~TransformComponent() = default;

public:
	virtual void Update() override;
	virtual void Draw() override;

	// ���, ȸ��, �̵� ����.
	void Scale(const Vector2& _scale);
	void Rotate(float _axis);
	void Translate(const Vector2& _pos);

	// Get Method.
	const Matrix3x2& GetWorldMatrix() const;

private:
	Matrix3x2 m_worldMat = {};
	Vector2 m_pos = {};
	Vector2 m_scale = { 1.0f, 1.0f };
	float m_axis = 0.0f;
};