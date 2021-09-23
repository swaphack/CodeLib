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
	float width = 1024;
	float length = 1366;

	int aryIndex[4] = {0, 1, 2, 3 };
	math::Vector3 aryPoint[4] = { math::Vector3() };
    math::Vector3 offset(1, 10, 1);

    std::vector<math::Vector3> points;
    std::vector<int> indices;
    std::vector<phy::Color4F> colorData;

	alg::DiamondSquareTerrian terrian;
	terrian.setPoints(math::Vector3(0, 0, 0), math::Vector3(width, 0, 0), math::Vector3(width, 0, length), math::Vector3(0, 0, length));

    std::map<std::string, int> keys;

	auto polygons = terrian.createQuads(2);
	if (polygons.size() >= 2)
	{
        for (int i = 0; i < polygons.size(); i++)
        {
            aryPoint[0] = polygons[i].leftBottom;
            aryPoint[1] = polygons[i].rightBottom;
            aryPoint[2] = polygons[i].rightTop;
            aryPoint[3] = polygons[i].leftTop;

            for (int j = 0; j < 4; j++)
            {
                auto value = aryPoint[j];
                std::string key = value.toString();
                auto it = keys.find(key);
                if (it == keys.end())
                {
                    int index = points.size();
                    keys[key] = index;
                    points.push_back(value);
                    colorData.push_back(phy::Color4F(value.getX() / width, value.getY() / offset.getY(), value.getZ() / length));

                    aryIndex[j] = index;
                }
                else
                {
                    aryIndex[j] = it->second;
                }
            }
            // 0, 1, 2, 0, 2, 3
            indices.push_back(aryIndex[0]);
            indices.push_back(aryIndex[1]);
            indices.push_back(aryIndex[2]);

            indices.push_back(aryIndex[0]);
            indices.push_back(aryIndex[2]);
            indices.push_back(aryIndex[3]);
        }
	}

    render::Model* pModel = CREATE_NODE(render::Model);
    pModel->getMesh()->setVertices(points);
    pModel->getMesh()->setColors(colorData);
    pModel->getMesh()->setIndices(indices);
    pModel->forceUpdateMeshData();
    Utility::loadDefaultShader(pModel);
    this->addChild(pModel);
}
