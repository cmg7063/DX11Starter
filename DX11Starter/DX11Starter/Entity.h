#pragma once
#include "Mesh.h"
#include "Material.h"
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include "DirectionalLight.h"

using namespace DirectX;
class Entity 
{
public:
	Entity(Mesh *m, Material* mat, XMFLOAT3 pos);
	~Entity();
	void PositionDelta(XMFLOAT3 delta);
	void SetPosition(XMFLOAT3 pos);
	void SetRotation(XMFLOAT4X4 rot);
	void SetScale(XMFLOAT3 sc);
	XMMATRIX GetWorldMatrix();
	Mesh* GetMesh();
	void PrepareMaterial(XMFLOAT4X4 view, XMFLOAT4X4 projection, DirectionalLight dLight, DirectionalLight dLight2);

private:
	XMFLOAT4X4 worldMatrix;
	bool dirty;
	Mesh* mesh;
	Material* material;
	XMFLOAT3 position;
	XMFLOAT4X4 rotation;
	XMFLOAT3 scale;
};