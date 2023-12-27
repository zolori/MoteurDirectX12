#include "GameObject.h"
#include <d3dcompiler.h>

void GameObject::Rotate(float x, float y, float z, float value)
{
	//DirectX::XMMatrixRotationRollPitchYaw();
}

void GameObject::Translate(float x, float y, float z)
{
}

void GameObject::Scale(float x, float y, float z)
{
}

void GameObject::SetParent(GameObject* a_parent)
{
}

void GameObject::AddChildren(GameObject* a_child)
{
}

void GameObject::Draw(ID3D12GraphicsCommandList* a_commandList, int a_frameIndex, Camera* a_camera, DirectX::XMMATRIX a_transformationMatrix)
{
}

void GameObject::CreateCBUploadHeap(ID3D12Device* a_device, int a_frameBufferCount)
{
}

DirectX::XMMATRIX GameObject::GetLocalWorldMatrix()
{
	return DirectX::XMMATRIX();
}

DirectX::XMMATRIX GameObject::GetWorldMatrix()
{
	return DirectX::XMMATRIX();
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
}
