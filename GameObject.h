#pragma once
#include "Transform.h"
#include <vector>
#include <d3d12.h>

class Camera;

struct ConstantBufferObject {
    DirectX::XMFLOAT4X4 wvpMat;
};


class GameObject
{
protected:
    ID3D12Device* m_device = nullptr;
    ID3D12Resource** constantBufferUploadHeaps = nullptr;
    UINT8** cbvGPUAddress = nullptr;

    GameObject* m_parent = nullptr;
    int m_frameBufferCount = 0;
    ConstantBufferObject cbObject;
    std::vector<GameObject*> m_children;
    DirectX::XMFLOAT4 m_up;
    DirectX::XMFLOAT4 m_right;
    DirectX::XMFLOAT4 m_target;
    DirectX::XMFLOAT4 m_position;
    DirectX::XMFLOAT4X4 m_transformationMatrix;
    DirectX::XMFLOAT4X4 m_viewMatrix;

public:

    void Rotate(float x, float y, float z, float value);
    void Translate(float x, float y, float z);
    void Scale(float x, float y, float z);
    void SetParent(GameObject* a_parent);
    void AddChildren(GameObject* a_child);
    void Draw(ID3D12GraphicsCommandList* a_commandList, int a_frameIndex, Camera* a_camera, DirectX::XMMATRIX a_transformationMatrix = DirectX::XMMatrixIdentity());

    void CreateCBUploadHeap(ID3D12Device* device, int frameBufferCount);


    DirectX::XMMATRIX GetLocalWorldMatrix();

    DirectX::XMMATRIX GetWorldMatrix();





    GameObject();
    GameObject(DirectX::XMFLOAT4 a_position);
    GameObject(DirectX::XMFLOAT4 a_position, DirectX::XMFLOAT4 a_target, DirectX::XMFLOAT4 a_up, DirectX::XMFLOAT4 a_right);
    ~GameObject();


};

