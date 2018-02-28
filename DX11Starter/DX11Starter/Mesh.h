#pragma once

#include <d3d11.h>
#include "Vertex.h"
#include <vector>
#include <io.h>
#include <fstream>
#include <DirectXMath.h>

using namespace DirectX;
class Mesh
{
public:
	Mesh();
	Mesh(Vertex* verts, unsigned int vertCount, unsigned int* inds, unsigned int indCount, ID3D11Device* dev);
	Mesh(char* file, ID3D11Device * dev);
	~Mesh();
	ID3D11Buffer* GetVertexBuffer();
	ID3D11Buffer* GetIndexBuffer();
	unsigned int GetIndexCount();

private:
	ID3D11Buffer * vertexBuffer;
	ID3D11Buffer* indexBuffer;
	unsigned int indexCount;
};