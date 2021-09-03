#include "PointSprite.h"
#include "Common/Mesh/Mesh.h"
#include "Common/Material/Material.h"
#include "Common/Shader/import.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TextureCache.h"
#include "Graphic/import.h"
#include "Common/Tool/VertexTool.h"

render::PointSprite::PointSprite()
{

}

render::PointSprite::~PointSprite()
{

}

bool render::PointSprite::init()
{
	if (!PrimitiveNode::init())
	{
		return false;
	}

	_mesh->setDrawMode(DrawMode::POINTS);

	_notify->removeListens(NodeNotifyType::GEOMETRY);

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->updatePointSprite();
		this->onPrimitiveChange();
	});

	return true;
}

void render::PointSprite::setSpriteCount(int count)
{
	_spriteCount = count;

	this->notify(NodeNotifyType::GEOMETRY);
}

int render::PointSprite::getSpriteCount() const
{
	return _spriteCount;
}

void render::PointSprite::updatePointSprite()
{
	render::RectVertex rectVertex;
	render::VertexTool::setTexture2DVertices(&rectVertex, math::Vector3(), _volume, _anchor);

	math::Vector3 leftDown = rectVertex.getLeftBottomPosition();
	math::Vector3 rightUp = rectVertex.getRightTopPosition();

	this->removeAllPoints();

	for (int i = 0; i < _spriteCount; i++)
	{
		math::Vector3 pos = math::Vector3(
			sys::Random::getNumber(leftDown.getX(), rightUp.getX()),
			sys::Random::getNumber(leftDown.getY(), rightUp.getY()),
			0);

		this->appendPoint(pos);
	}
}

void render::PointSprite::beforeDraw()
{
	GLState::enable(EnableMode::POINT_SPRITE);
	GLDebug::showError();
	GLDebug::showError();
	GLFixedFunction::setTexEnv(TextureEnvTarget::POINT_SPRITE, TextureEnvParameter::COORD_REPLACE, 1);
	GLDebug::showError();
	GLState::setPointSpriteCoordOrigin(PointSpriteCoordType::LOWER_LEFT);
	GLDebug::showError();
	getMesh()->setDrawMode(DrawMode::POINTS);
	GLDebug::showError();
	PrimitiveNode::beforeDraw();
}

void render::PointSprite::afterDraw()
{
	PrimitiveNode::afterDraw();
	GLState::disable(EnableMode::POINT_SPRITE);
}

