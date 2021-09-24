#include "Terrian.h"
#include "algorithm.h"
#include "Common/Mesh/Mesh.h"

render::Terrian::Terrian()
{
}

render::Terrian::~Terrian()
{
}

bool render::Terrian::init()
{
	if (!DrawNode3D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->onTerrianChange();
	});

    this->getMesh()->setDrawMode(DrawMode::TRIANGLES);

	return true;
}

void render::Terrian::setTerrianSize(float width, float height)
{
    _terrianSize.setWidth(width);
    _terrianSize.setHeight(height);
    this->notify(NodeNotifyType::GEOMETRY);
}

void render::Terrian::setTerrianWidth(float width)
{
    _terrianSize.setWidth(width);
	this->notify(NodeNotifyType::GEOMETRY);
}

float render::Terrian::getTerrianWidth() const
{
    return _terrianSize.getWidth();
}

void render::Terrian::setTerrianLength(float length)
{
    _terrianSize.setHeight(length);
	this->notify(NodeNotifyType::GEOMETRY);
}

float render::Terrian::getTerrianLength() const
{
	return _terrianSize.getHeight();
}

void render::Terrian::setTerrianHeight(float minHeight, float maxHeight)
{
    _terrianHeight.setMinValue(minHeight);
    _terrianHeight.setMaxValue(maxHeight);
    this->notify(NodeNotifyType::GEOMETRY);
}

void render::Terrian::setFractalCount(int count)
{
    _fractalCount = count;
    this->notify(NodeNotifyType::GEOMETRY);
}

int render::Terrian::getFractalCount() const
{
    return _fractalCount;
}

void render::Terrian::onTerrianChange()
{
    this->startThread([this]() {
    int aryIndex[4] = { 0, 1, 2, 3 };
    math::Vector3 aryPoint[4] = { math::Vector3() };

    std::vector<math::Vector3> points;
    std::vector<int> indices;
    std::vector<phy::Color4F> colorData;

    alg::DiamondSquareTerrian terrian;
    terrian.setOffset(_terrianHeight.getMinValue(), _terrianHeight.getMaxValue());
    terrian.setPoints(math::Vector3(0, 0, 0), math::Vector3(getTerrianWidth(), 0, 0),
        math::Vector3(getTerrianWidth(), 0, getTerrianLength()), math::Vector3(0, 0, getTerrianLength()));

    std::map<std::string, int> keys;
    math::Vector3 origin(_anchor.getX() * getTerrianWidth(), 0, _anchor.getY() * getTerrianLength());
    auto polygons = terrian.createQuads(_fractalCount);
    if (polygons.size() >= 0)
    {
        for (int i = 0; i < polygons.size(); i++)
        {
            aryPoint[0] = polygons[i].leftBottom;
            aryPoint[1] = polygons[i].rightBottom;
            aryPoint[2] = polygons[i].rightTop;
            aryPoint[3] = polygons[i].leftTop;

            for (int j = 0; j < 4; j++)
            {
                math::Vector3 value = aryPoint[j];
                std::string key = value.toString();
                auto it = keys.find(key);
                if (it == keys.end())
                {
                    int index = points.size();
                    keys[key] = index;

                    phy::Color4F color(
                        value.getX() / getTerrianWidth(), 
                        value.getY() / _terrianHeight.getMaxValue(),
                        value.getZ() / getTerrianLength());
                    colorData.push_back(color);

                    value -= origin;
                    points.push_back(value);

                    aryIndex[j] = index;
                }
                else
                {
                    aryIndex[j] = it->second;
                }
            }
            //zÖáÏòÍâ 0, 1, 2, 0, 2, 3
            indices.push_back(aryIndex[0]);
            indices.push_back(aryIndex[2]);
            indices.push_back(aryIndex[1]);

            indices.push_back(aryIndex[0]);
            indices.push_back(aryIndex[3]);
            indices.push_back(aryIndex[2]);
        }
    }

    this->getMesh()->setVertices(points);
    this->getMesh()->setColors(colorData);
    this->getMesh()->setIndices(indices);
    this->notify(NodeNotifyType::MESH);

    });
}
