#include "TerrianNode.h"
#include "algorithm.h"
#include "render.h"
#include "Utility.h"

TerrianNode::TerrianNode()
{
}

TerrianNode::~TerrianNode()
{
}

void TerrianNode::initNodes()
{
	this->addTerrian();
}


void TerrianNode::addTerrian()
{
	int width = 5000;
    int length = 5000;
    int minHeight = 100;
    int maxHeight = 1000;

    render::Terrian* pTerrian = CREATE_NODE(render::Terrian);
    pTerrian->setAnchorPoint(0.5f, 0.5f, 0.5f);
    pTerrian->setVolume(width, maxHeight, length);
    pTerrian->setPosition(512, 384);
    pTerrian->setTerrianSize(width, length);
    pTerrian->setTerrianHeight(minHeight, maxHeight);
    pTerrian->setFractalCount(7);
    this->addChild(pTerrian);

    Utility::loadDefaultShader(pTerrian);
}
