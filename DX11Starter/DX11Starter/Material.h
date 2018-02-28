#pragma once
#include "SimpleShader.h"
#include "WICTextureLoader.h"

class Material 
{
public:
	Material(SimpleVertexShader * vs, SimplePixelShader * ps, ID3D11ShaderResourceView * texView, ID3D11SamplerState * samState);
	~Material();
	SimpleVertexShader* GetVertexShader();
	SimplePixelShader* GetPixelShader();
	ID3D11ShaderResourceView * GetTextureView();
	ID3D11SamplerState * GetSamplerState();

private:
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;
	ID3D11ShaderResourceView * textureView;
	ID3D11SamplerState * samplerState;
};