#include "pch.h"
#include "Component.h"

void Component::SetOwner(GameObject* _owner)
{
	m_owner = _owner;
}



GameObject* Component::GetOwner() const
{
	return m_owner;
}