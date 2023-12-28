#pragma once
#include "Transform.h"
#include "d3dUtil.h"
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

    Transform transform;

public:

    void SetParent(GameObject* a_parent);
    void AddChildren(GameObject* a_child);
    void Draw(ID3D12GraphicsCommandList* a_commandList, int a_frameIndex, Camera* a_camera, DirectX::XMMATRIX a_transformationMatrix = DirectX::XMMatrixIdentity());

    void CreateCBUploadHeap(ID3D12Device* device, int frameBufferCount);


    DirectX::XMMATRIX GetLocalWorldMatrix();

    DirectX::XMMATRIX GetWorldMatrix();





    GameObject();
    GameObject(DirectX::XMFLOAT4 position);
    GameObject(DirectX::XMFLOAT4 position, DirectX::XMFLOAT4 target, DirectX::XMFLOAT4 up, DirectX::XMFLOAT4 right);
    ~GameObject();


};

