#include "CubeModel.h"
#include "Resource/Detail/ModelDetail.h"

using namespace render;

CubeModel::CubeModel()
{

}

CubeModel::~CubeModel()
{
	SAFE_RELEASE(_texture);
}

bool CubeModel::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		onCubeChange();
	});

	_notify->addListen(ENP_MODEL_FRAME, [this](){
		onCubeChange();
	});

	_modelDetail = new ModelDetail();

	auto pMesh = CREATE_OBJECT(Mesh);
	auto pMat = CREATE_OBJECT(Material);
	_modelDetail->addMesh(0, pMesh);
	_modelDetail->addMaterial(0, pMat);

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pFace = CREATE_OBJECT(Face);
		pFace->setMaterial(0);
		pMesh->addFace(i, pFace);
	}
	return true;
}

void CubeModel::draw()
{
	Model::draw();
	/*
	for (auto mesh : _meshes)
	{
		int textureID = 0;
		if (_texture)
		{
			textureID = _texture->getTextureID();
		}
		
		mesh.second->apply(textureID, getColor(), getOpacity(), getBlend());

		int matID = mesh.second->getMaterial();
		auto pMat = this->getMatrial(matID);
		if (pMat)
		{
			pMat->apply();
		}
	}
	*/
}

void CubeModel::onCubeChange()
{
	auto pMesh = _modelDetail->getMesh(0);
	if (!pMesh)
	{
		return;
	}

	TextureTool::setTexture3DVertexts(&_texCube, _position, _volume, _anchor);

	math::Vector3 coords[8];
	coords[0] = _texCube.front.leftDown.point;
	coords[1] = _texCube.front.rightDown.point;
	coords[2] = _texCube.front.rightUp.point;
	coords[3] = _texCube.front.leftUp.point;

	coords[4] = _texCube.back.rightDown.point;
	coords[5] = _texCube.back.leftDown.point;
	coords[6] = _texCube.back.leftUp.point;
	coords[7] = _texCube.back.rightUp.point;

	float vertexes[24] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		memcpy(vertexes + i * 3, coords[i].getValue(), 3 * sizeof(float));
	}

	uint16_t indexes[36] = {
		//前面
		0,1,2,
		0,2,3,
		// 后面
		4,6,5,
		4,7,6,
		//左面
		0,3,4,
		4,3,7,
		// 右面
		1,5,2,
		5,6,2,
		// 顶面
		3,2,7,
		2,6,7,
		// 底面
		4, 5, 0,
		0, 5, 1,
	};

	float uv[16] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1
	};

	float normal[24] = {
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
	};
	
	pMesh->setVertices(24, vertexes);
	pMesh->setUVs(16, uv, 2);
	pMesh->setNormals(24, normal);
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pFace = pMesh->getFace(i);
		if (pFace)
		{
			pFace->setIndices(6, indexes + i * CUBE_FACE_COUNT);
		}
	}
}

TextureRect* CubeModel::getTextureRect(ModelFace face)
{
	switch (face)
	{
	case EMF_FRONT:
		return &_texCube.front;
		break;
	case EMF_BACK:
		return &_texCube.back;
		break;
	case EMF_LEFT:
		return &_texCube.left;
		break;
	case EMF_RIGHT:
		return &_texCube.right;
		break;
	case EMF_TOP:
		return &_texCube.top;
		break;
	case EMF_BOTTOM:
		return &_texCube.bottom;
		break;
	default:
		break;
	}

	return nullptr;
}

void CubeModel::setTexture(const std::string& name, Texture* texture)
{
	SAFE_RELEASE(_texture);
	SAFE_RETAIN(texture);
	_texture = texture;

	_modelDetail->addTexture(name, texture->getTextureID());

	auto pMat = _modelDetail->getMaterial(0);
	if (pMat)
	{
		pMat->setTexture1(name);
	}
}

