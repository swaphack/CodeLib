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

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
{
	_texFrame = CREATE_OBJECT(TexFrame);
	SAFE_RETAIN(_texFrame);

	_material = CREATE_OBJECT(Material);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(_mesh);
}

CtrlFrame::~CtrlFrame()
{
	SAFE_RELEASE(_texFrame);
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

void CtrlFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_material->addTexture(MAT_TEXTURE_NAEM, (Texture2D*)texture);

	_texFrame->setTexture(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTextureWithRect(const Texture* texture)
{
	_material->addTexture(MAT_TEXTURE_NAEM, (Texture2D*)texture);

	_texFrame->setTextureWithRect(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTexRect(const math::Rect& rect)
{
	_texFrame->setRect(rect);
	this->notify(ENP_TEXTURE_FRAME);
} 

void CtrlFrame::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}
	_material->addTexture(MAT_TEXTURE_NAEM, (Texture2D*)texFrame->getTexture());
	*_texFrame = *texFrame;
	this->notify(ENP_TEXTURE_FRAME);
}

const TexFrame* CtrlFrame::getTexFrame()
{
	return _texFrame;
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
	const Texture* texture = _texFrame->getTexture();
	if (texture == nullptr)
	{
		return;
	}

	math::Size size = math::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

	TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());
	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}

void render::CtrlFrame::drawSampleWithClientArray()
{
	if (_texFrame->getTexture() == nullptr)
	{
		return;
	}

	int textID = _texFrame->getTexture()->getTextureID();
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
	math::Matrix44 projMat = Camera::getMainCamera()->getProjectMatrix();
	math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Matrix44 modelMat = this->getWorldMatrix();

	_material->startUpdateShaderUniformValue(projMat, viewMat, modelMat);
	_mesh->draw(_material);
	_material->endUpdateShaderUniformValue();
}

void render::CtrlFrame::initBufferObject()
{
	ModelDetail* pModelDetail = CREATE_OBJECT(ModelDetail);

	auto pMat = CREATE_OBJECT(MaterialDetail);	
	pMat->setAmbientTextureMap(MAT_TEXTURE_NAEM);
	pModelDetail->addMaterial(0, pMat);

	auto pMesh = CREATE_OBJECT(MeshDetail);
	pMesh->setMaterial(0);
	pModelDetail->addMesh(0, pMesh);

	uint32_t nVerticeSize = sizeof(_texRect.vertices);
	uint32_t nColorSize = sizeof(_texRect.colors);
	uint32_t nUVSize = sizeof(_texRect.uvs);
	uint32_t nIndiceSize = sizeof(_texRect.indices);

	pMesh->setVertices(nVerticeSize, _texRect.vertices);
	pMesh->setColors(nColorSize, _texRect.colors);
	pMesh->setUVs(nUVSize, _texRect.uvs);
	pMesh->setIndices(nIndiceSize, _texRect.indices);

	_material->setModelDetail(pModelDetail);
	_mesh->setModelDetail(pModelDetail);
}