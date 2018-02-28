#include "Material.h"

Material::Material(SimpleVertexShader * vs, SimplePixelShader * ps, ID3D11ShaderResourceView * texView, ID3D11SamplerState * samState)
{
	vertexShader = vs;
	pixelShader = ps;
	textureView = texView;
	samplerState = samState;
}

Material::~Material() 
{
}

SimpleVertexShader * Material::GetVertexShader() 
{
	return vertexShader;
}

SimplePixelShader * Material::GetPixelShader() 
{
	return pixelShader;
}

ID3D11ShaderResourceView * Material::GetTextureView() 
{
	return textureView;
}

ID3D11SamplerState * Material::GetSamplerState() 
{
	return samplerState;
} 	 