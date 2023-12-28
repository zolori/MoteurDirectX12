#pragma once
#include <DirectXMath.h>
using namespace DirectX;

class Transform
{
public: 
	void Rotate(float x, float y, float z, float angle);
	void Translate(float x, float y, float z);
	void Scale(float x, float y, float z);

	XMFLOAT4 m_up;
	XMFLOAT4 m_right;
	XMFLOAT4 m_position;
	XMFLOAT4 m_target;
	XMFLOAT4X4 m_transformMatrix;
	XMFLOAT4X4 m_viewmatrix;
};