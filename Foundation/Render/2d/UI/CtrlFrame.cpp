#include "CtrlFrame.h"

#include "Common/Texture/Texture.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Tool/Tool.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/View/import.h"
#include "Common/Buffer/import.h"
#include "Resource/Detail/import.h"
#include "Graphic/import.h"
#include "Common/Node/import.h"

#define MAT_TEXTURE_NAEM "MAT_TEXTURE_NAEM"
#define MATERIAL_INDEX 0
#define MESH_INDEX 0

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
{
	_material = CREATE_OBJECT(Material);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(_mesh);
}

CtrlFrame::~CtrlFrame()
{
	SAFE_RELEASE(_material);
	SAFE_RELEASE(_mesh);
}

bool CtrlFrame::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		onTextureChange();		
	});

	_notify->addListen(ENP_TEXTURE_FRAME, [this](){
		_material->updateMatTexture();
		onTextureChange();
	});

	initBufferObject();

	return true;
}

void CtrlFrame::drawSample()
{
#if USE_BUFFER_OBJECT
	this->drawSampleWithBufferObject();
#else
	this->drawSampleWithClientArray();
#endif
}

void CtrlFrame::setTexture(const Texture2D* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_material->addTexture(MAT_TEXTURE_NAEM, texture);

	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTextureWithRect(const Texture2D* texture)
{
	_material->addTexture(MAT_TEXTURE_NAEM, texture);
	this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDepth());

	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTexRect(const math::Rect& rect)
{
	const auto& size = rect.getSize();
	this->setVolume(size.getWidth(), size.getHeight());

	this->notify(ENP_TEXTURE_FRAME);
} 

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipY()
{
	return _bFlipY;
}

void CtrlFrame::onTextureChange()
{
	math::Size size = math::Size(this->getWidth(), this->getHeight());
	math::Rect rect(math::Vector2(), size);
	TextureTool::setTexture2DCoords(&_texRect, size, rect);
	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);

	updateBufferData();
}

render::Material* render::CtrlFrame::getMaterial()
{
	return _material;
}

render::Mesh* render::CtrlFrame::getMesh()
{
	return _mesh;
}

void render::CtrlFrame::drawSampleWithClientArray()
{

	int textID = _material->getTexture(MAT_TEXTURE_NAEM);
	if (textID == 0)
	{
		return;
	}

	GLState::enable(EnableModel::TEXTURE_2D);
	GLTexture::bindTexture2D(textID);

	GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::setVertexPointer(3, DataType::FLOAT, 0, _texRect.vertices);

	GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::setTexCoordPointer(2, DataType::FLOAT, 0, _texRect.uvs);

	GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
	GLClientArrays::setColorPointer(4, DataType::FLOAT, 0, _texRect.colors);

	GLClientArrays::drawElements(DrawMode::TRIANGLES, 6, IndexDataType::UNSIGNED_INT, _texRect.indices);

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

	GLState::disable(EnableModel::TEXTURE_2D);
}

void render::CtrlFrame::drawSampleWithBufferObject()
{
	_mesh->draw(this, _material);
}

void render::CtrlFrame::initBufferObject()
{
	ModelDetail* pModelDetail = CREATE_OBJECT(ModelDetail);

	auto pMat = CREATE_OBJECT(MaterialDetail);	
	pMat->setAmbientTextureMap(MAT_TEXTURE_NAEM);
	pModelDetail->addMaterial(MATERIAL_INDEX, pMat);

	auto pMesh = CREATE_OBJECT(MeshDetail);
	pMesh->setMaterial(MATERIAL_INDEX);
	pModelDetail->addMesh(MESH_INDEX, pMesh);

	_material->setModelDetail(pModelDetail);
	_mesh->setModelDetail(pModelDetail);
}

void render::CtrlFrame::updateBufferData()
{
	auto pMesh = _mesh->getMesh(MESH_INDEX);
	if (pMesh)
	{
		pMesh->setVertices(12, _texRect.vertices);
		pMesh->setColors(16, _texRect.colors);
		pMesh->setUVs(8, _texRect.uvs);
		pMesh->setIndices(6, _texRect.indices);
	}

	_mesh->updateBufferData();
}
