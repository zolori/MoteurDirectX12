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

//DirectX::XMMATRIX Camera::GetVPMatrix()
//{
//    return   DirectX::XMMatrixLookToLH(DirectX::XMLoadFloat4(&m_position), DirectX::XMLoadFloat4(&m_target), DirectX::XMLoadFloat4(&m_up)) * DirectX::XMLoadFloat4x4(&m_transformationMatrix) * GetProjectionMatrix();
//}

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