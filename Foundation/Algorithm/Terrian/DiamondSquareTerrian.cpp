#include "DiamondSquareTerrian.h"
#include "TerrianHelper.h"

alg::DiamondSquareTerrian::DiamondSquareTerrian()
{
}

alg::DiamondSquareTerrian::~DiamondSquareTerrian()
{
}

void alg::DiamondSquareTerrian::setPoints(const math::Vector3& leftBottom, const math::Vector3& rightBottom, const math::Vector3& rightTop, const math::Vector3& leftTop)
{
    _leftBottom = leftBottom;
    _rightBottom = rightBottom;
    _rightTop = rightTop;
    _leftTop = leftTop;
}

std::vector<alg::DiamondSquareTerrian::Quadrilateral> alg::DiamondSquareTerrian::createQuads(int count)
{
    math::Vector3 offset0 = _offset;
    math::Vector3 offset1 = -1.0f * _offset;

    math::Vector3 minOffset, maxOffset;
    TerrianHelper::getRange(offset0, offset1, minOffset, maxOffset);

    std::vector<Quadrilateral> quads;
    quads.push_back(Quadrilateral(_leftBottom, _rightBottom, _rightTop, _leftTop));

    Quadrilateral quad0, quad1, quad2, quad3;
    for (int i = 0; i < count; i++)
    {
        float value = 1.0f / powf(2, i);
        offset0 = minOffset * value;
        offset1 = maxOffset * value;

        std::vector<Quadrilateral> newQuads;
        for(auto item : quads)
        {
            math::Vector3 offset = TerrianHelper::getRandomPosition(offset0, offset1);
            this->autoDivide(item, offset,
                quad0, quad1, quad2, quad3);
            newQuads.push_back(quad0);
            newQuads.push_back(quad1);
            newQuads.push_back(quad2);
            newQuads.push_back(quad3);
        }
        quads = newQuads;
    }

    return quads;
}

void alg::DiamondSquareTerrian::autoDivide(const Quadrilateral& quad, const math::Vector3& offset, Quadrilateral& quad0, Quadrilateral& quad1, Quadrilateral& quad2, Quadrilateral& quad3)
{
    // 3  2
    // 0  1
    math::Vector3 centerPoint = quad.getCenterPoint();

    centerPoint += offset;

    math::Vector3 midPoint01 = 0.5f * (quad.leftBottom + quad.rightBottom);
    math::Vector3 midPoint12 = 0.5f * (quad.rightBottom + quad.rightTop);
    math::Vector3 midPoint23 = 0.5f * (quad.rightTop + quad.leftTop);
    math::Vector3 midPoint30 = 0.5f * (quad.leftTop + quad.leftBottom);

    quad0 = Quadrilateral(quad.leftBottom, midPoint01, centerPoint, midPoint30);
    quad1 = Quadrilateral(midPoint01, quad.rightBottom, midPoint12, centerPoint);
    quad2 = Quadrilateral(centerPoint, midPoint12, quad.rightTop, midPoint23);
    quad3 = Quadrilateral(midPoint30, centerPoint, midPoint23, quad.leftTop);
}
