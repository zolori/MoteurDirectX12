#include "Transform.h"
using namespace DirectX;


void Transform::Rotate(float x, float y, float z, float angle)
{
	XMFLOAT4 axis(x, y, z, 0.0f);

	XMStoreFloat4x4(&m_transformMatrix, XMLoadFloat4x4(&m_transformMatrix) *= XMMatrixRotationAxis(XMLoadFloat4(&axis), angle));
}

void Transform::Translate(float x, float y, float z)
{
	XMStoreFloat4x4(&m_transformMatrix, XMLoadFloat4x4(&m_transformMatrix) *= XMMatrixTranslation(x, y, z));
}

void Transform::Scale(float x, float y, float z)
{
	XMStoreFloat4x4(&m_transformMatrix, XMLoadFloat4x4(&m_transformMatrix) *= XMMatrixScaling(x, y, z));
}
