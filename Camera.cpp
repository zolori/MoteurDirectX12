#include "Camera.h"

void Camera::SetIsOrthographic(bool isOrtho)
{
    mIsOrtho = isOrtho;
}

void Camera::SetView(float a_width, float a_heigth)
{
    mWidth = a_width;
    mHeight = a_heigth;
}

void Camera::SetNearZ(float a_nearZ)
{
    mNearZ = a_nearZ;
}

void Camera::SetFarZ(float a_farZ)
{
    mFarZ = a_farZ;
}

void Camera::SetFOV(float a_fov)
{
    mFOV = a_fov;
}

DirectX::XMMATRIX Camera::GetVPMatrix()
{
    return   DirectX::XMMatrixLookToLH(DirectX::XMLoadFloat4(&transform.m_position), DirectX::XMLoadFloat4(&transform.m_target), DirectX::XMLoadFloat4(&transform.m_up)) * DirectX::XMLoadFloat4x4(&transform.m_transformMatrix) * GetProjectionMatrix();
}

DirectX::XMMATRIX Camera::GetProjectionMatrix()
{
    return mIsOrtho ? DirectX::XMMatrixOrthographicLH(mWidth, mHeight, mNearZ, mFarZ) : DirectX::XMMatrixPerspectiveFovLH(mFOV * (3.14f / 180.0f), mWidth / mHeight, mNearZ, mFarZ);
}

Camera::Camera()
{
}


Camera::Camera(DirectX::XMFLOAT4 a_position, DirectX::XMFLOAT4 a_target, DirectX::XMFLOAT4 a_up, DirectX::XMFLOAT4 a_right)
{

}



Camera::~Camera()
{
}

void Camera::UpdateCamera()
{
    //Move Up and bottom
    if (GetAsyncKeyState('Z')) {
        transform.Translate(0.0f, 0.0f, -speed / 4.0f);
    }
    else if (GetAsyncKeyState('S')) {
        transform.Translate(0.0f, 0.0f, speed / 4.0f);
    }

    //Move Right and Left
    if (GetAsyncKeyState('Q')) {
        transform.Translate(speed / 4.0f, 0.0f, 0.0f);
    }
    else if (GetAsyncKeyState('D')) {
        transform.Translate(-speed / 4.0f, 0.0f, 0.0f);
    }

    //Move forward/Backward
    if (GetAsyncKeyState('P')) {
        transform.Translate(0.0f, -speed / 4.0f, 0.0f);
    }
    else if (GetAsyncKeyState('M')) {
        transform.Translate(0.0f, speed / 4.0f, 0.0f);
    }

    //Rotate Y axis
    if (GetAsyncKeyState('A')) {
        transform.Rotate(0.0f, 1.0f, 0.0f, speed);
    }
    else if (GetAsyncKeyState('E')) {
        transform.Rotate(0.0f, 1.0f, 0.0f, -speed);
    }

    //Rotate X axis
    if (GetAsyncKeyState('R')) {
        transform.Rotate(0.0f, 0.0f, 1.0f, speed);
    }
    else if (GetAsyncKeyState('T')) {
        transform.Rotate(0.0f, 0.0f, 1.0f, -speed);
    }

    //Rotate Z axis
    if (GetAsyncKeyState('F')) {
        transform.Rotate(1.0f, 0.0f, 0.0f, speed);
    }
    else if (GetAsyncKeyState('G')) {
        transform.Rotate(1.0f, 0.0f, 0.0f, -speed);
    }
}
