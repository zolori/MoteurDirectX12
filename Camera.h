#pragma once
#include <DirectXMath.h>
#include "Transform.h"

using namespace DirectX;

class Camera
{
public:
    Camera();
    Camera(XMFLOAT4 position, XMFLOAT4 target, XMFLOAT4 up, XMFLOAT4 right);
    ~Camera();

    void SetIsOrthographic(bool isOrtho);
    void SetView(float width, float height);
    void SetNearZ(float nearZ);
    void SetFarZ(float FarZ);
    void SetFOV(float fov);

    XMMATRIX GetVPMatrix();
    XMMATRIX GetProjectionMatrix();

protected:
    bool mIsOrtho;
    float mWidth;
    float mHeight;
    float mNearZ;
    float mFarZ;
    float mFOV;
};
