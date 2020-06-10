#include "CtrlPointSprite.h"
#include "Common/Mesh/Mesh.h"
#include "Common/Material/Material.h"
#include "Common/Shader/import.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TextureCache.h"
#include "Graphic/import.h"

render::CtrlPointSprite::CtrlPointSprite()
{

}

render::CtrlPointSprite::~CtrlPointSprite()
{

}

bool render::CtrlPointSprite::init()
{
	if (!CtrlAnimation::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::GEOMETRY, [this]() {
		this->updatePointSprite();
	});

	getMaterial()->setProgramFunc([this](ShaderProgram* program) {
		ShaderUniform* pValue = program->getUniform("pointScale");
		if (pValue)
		{
			pValue->setValue(sys::Random::getNumber0_1());
		}
	});


	return true;
}

void render::CtrlPointSprite::setSpriteCount(int count)
{
	_spriteCount = count;

	this->notify(NodeNotifyType::GEOMETRY);
}

int render::CtrlPointSprite::getSpriteCount() const
{
	return _spriteCount;
}

void render::CtrlPointSprite::setPointSize(int size)
{
	_pointSize = size;

	this->notify(NodeNotifyType::GEOMETRY);
}

int render::CtrlPointSprite::getPointSize() const
{
	return _pointSize;
}

void render::CtrlPointSprite::setImagePath(const std::string& filepath)
{
	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(filepath);
	if (texture == nullptr)
	{
		return;
	}

	this->setTexture(texture);
}

void render::CtrlPointSprite::setTexture(const Texture2D* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	addMaterialTexture(MAT_TEXTURE_NAME, texture);
	setTextureName(MAT_TEXTURE_NAME);
}

void render::CtrlPointSprite::updatePointSprite()
{
	math::Vector3 leftDown = _rectVertex.leftDown;
	math::Vector3 rightUp = _rectVertex.rightUp;

	auto vertice = (float*)getMesh()->getMeshDetail()->createVertices(_spriteCount, sizeof(float), 3);
	auto indice = (uint32_t*)getMesh()->getMeshDetail()->createIndices(_spriteCount, sizeof(uint32_t), 1);
	int i = 0;
	while (i < _spriteCount)
	{
		math::Vector3 pos(
			sys::Random::getNumber(leftDown.getX(), rightUp.getX()),
			sys::Random::getNumber(leftDown.getY(), rightUp.getY()),
			0);

		PRINT("%s\n", pos.toString().c_str());
		memcpy(vertice + i * 3, pos.getValue(), 3 * sizeof(float));
		memcpy(indice + i, &i, sizeof(uint32_t));
		i++;
	}

	this->updateBufferData();
}

void render::CtrlPointSprite::beforeDraw()
{
	GLState::enable(EnableMode::POINT_SPRITE);
	GLDebug::showError();
	GLState::setPointSize(_pointSize);
	GLDebug::showError();
	GLFixedFunction::setTexEnv(TextureEnvTarget::POINT_SPRITE, TextureEnvParameter::COORD_REPLACE, 1);
	GLDebug::showError();
	GLState::setPointSpriteCoordOrigin(PointSpriteCoordType::LOWER_LEFT);
	GLDebug::showError();
	getMesh()->setDrawMode(DrawMode::POINTS);
	GLDebug::showError();
	CtrlAnimation::beforeDraw();
}

void render::CtrlPointSprite::afterDraw()
{
	CtrlAnimation::afterDraw();
	GLState::disable(EnableMode::POINT_SPRITE);
}

