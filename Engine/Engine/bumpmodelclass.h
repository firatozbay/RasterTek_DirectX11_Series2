////////////////////////////////////////////////////////////////////////////////
// Filename: bumpmodelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _BUMPMODELCLASS_H_
#define _BUMPMODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
using namespace std;
using namespace DirectX;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: BumpModelClass
////////////////////////////////////////////////////////////////////////////////
class BumpModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
		XMFLOAT3 tangent;
		XMFLOAT3 binormal;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
		float tx, ty, tz;
		float bx, by, bz;
	};

	struct TempVertexType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct VectorType
	{
		float x, y, z;
	};

public:
	BumpModelClass();
	BumpModelClass(const BumpModelClass&);
	~BumpModelClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*, WCHAR*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetColorTexture();
	ID3D11ShaderResourceView* GetNormalMapTexture();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTextures(ID3D11Device*, ID3D11DeviceContext*, WCHAR*, WCHAR*);
	void ReleaseTextures();

	bool LoadModel(char*);
	void ReleaseModel();

	void CalculateModelVectors();
	void CalculateTangentBinormal(TempVertexType, TempVertexType, TempVertexType, VectorType&, VectorType&);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	ModelType* m_model;
	TextureClass* m_ColorTexture;
	TextureClass* m_NormalMapTexture;
};

#endif