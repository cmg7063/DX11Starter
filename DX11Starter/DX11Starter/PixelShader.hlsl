struct DirectionalLight
{
	float4 AmbientColor;
	float4 DiffuseColor;
	float3 Direction;
};

cbuffer externalData : register(b0)
{
	DirectionalLight light;
	DirectionalLight light2;
};

Texture2D diffuseTexture : register(t0);
SamplerState basicSampler : register(s0);

// Struct representing the data we expect to receive from earlier pipeline stages
// - Should match the output of our corresponding vertex shader
// - The name of the struct itself is unimportant
// - The variable names don't have to match other shaders (just the semantics)
// - Each variable must have a semantic, which defines its usage
struct VertexToPixel
{
	// Data type
	//  |
	//  |   Name          Semantic
	//  |    |                |
	//  v    v                v
	float4 position		: SV_POSITION;
	float3 normal		: NORMAL;
	float2 uv			: TEXCOORD;
};



// --------------------------------------------------------
// The entry point (main method) for our pixel shader
// 
// - Input is the data coming down the pipeline (defined by the struct)
// - Output is a single color (float4)
// - Has a special semantic (SV_TARGET), which means 
//    "put the output of this into the current render target"
// - Named "main" because that's the default the shader compiler looks for
// --------------------------------------------------------
float4 main(VertexToPixel input) : SV_TARGET
{
	float3 normalNormal = normalize(input.normal);
	float3 invDirection = float3(-light.Direction.x,-light.Direction.y,-light.Direction.z);
	float3 invDirection2 = float3(-light2.Direction.x, -light2.Direction.y, -light2.Direction.z);
	float lightAmt = saturate(dot(input.normal, invDirection));
	float lightAmt2 = saturate(dot(input.normal, invDirection2));
	// Just return the input color
	// - This color (like most values passing through the rasterizer) is 
	//   interpolated for each pixel between the corresponding vertices 
	//   of the triangle we're rendering
	//return input.color;
	//return float4(input.normal,1);
	return diffuseTexture.Sample(basicSampler, input.uv) * ((lightAmt*light.DiffuseColor) + light.AmbientColor + (lightAmt2*light2.DiffuseColor) + light2.AmbientColor);
	//return float4(light.Direction,1);
}