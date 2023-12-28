#include "GameObject.h"
#include <d3dcompiler.h>

void GameObject::SetParent(GameObject* a_parent)
{
	a_parent->AddChildren(this);
}

void GameObject::AddChildren(GameObject* a_child)
{
	m_children.push_back(a_child);
	a_child->m_parent = this;
}

void GameObject::Draw(ID3D12GraphicsCommandList* a_commandList, int a_frameIndex, Camera* a_camera, DirectX::XMMATRIX a_transformationMatrix)
{
}

void GameObject::CreateCBUploadHeap(ID3D12Device* a_device, int a_frameBufferCount)
{
}

DirectX::XMMATRIX GameObject::GetLocalWorldMatrix()
{
	return XMLoadFloat4x4(&transform.m_transformMatrix) * DirectX::XMMatrixTranslation(transform.m_position.x, transform.m_position.y, transform.m_position.z);
}


DirectX::XMMATRIX GameObject::GetWorldMatrix()
{
	DirectX::XMMATRIX parentWorld = DirectX::XMMatrixIdentity();
	if (m_parent) {
		parentWorld *= m_parent->GetWorldMatrix();
	}

	return GetLocalWorldMatrix() * parentWorld;
}

GameObject::GameObject()
{

}

GameObject::GameObject(DirectX::XMFLOAT4 a_position)
{
}

GameObject::GameObject(DirectX::XMFLOAT4 a_position, DirectX::XMFLOAT4 a_target, DirectX::XMFLOAT4 a_up, DirectX::XMFLOAT4 a_right)
{
}

GameObject::~GameObject()
{
	for (int i = 0; i < m_frameBufferCount; ++i) {
		if (constantBufferUploadHeaps) {
			SAFE_RELEASE(constantBufferUploadHeaps[i]);
		}
	}
	if (constantBufferUploadHeaps)
		delete constantBufferUploadHeaps;
	if (cbvGPUAddress)
		delete cbvGPUAddress;
}
