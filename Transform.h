#pragma once
#include <DirectXMath.h>
using namespace DirectX;

class Transform
{
public:
    Transform(): 
        position(0.0f, 0.0f, 0.0f), 
        rotation(0.0f, 0.0f, 0.0f), 
        scale(1.0f, 1.0f, 1.0f) {}

    // Fonction pour obtenir la matrice de transformation
    XMMATRIX GetTransformMatrix() const
    {
        XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);
        XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
        XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);

        // L'ordre des transformations peut varier en fonction de vos besoins
        XMMATRIX transformMatrix = translationMatrix * rotationMatrix * scaleMatrix;

        return transformMatrix;
    }

    // Fonctions pour définir la position, la rotation et l'échelle
    void SetPosition(float x, float y, float z) { position = XMFLOAT3(x, y, z); }
    void SetRotation(float pitch, float yaw, float roll) { rotation = XMFLOAT3(pitch, yaw, roll); }
    void SetScale(float x, float y, float z) { scale = XMFLOAT3(x, y, z); }

private:
    XMFLOAT3 position;
    XMFLOAT3 rotation;
    XMFLOAT3 scale;
};