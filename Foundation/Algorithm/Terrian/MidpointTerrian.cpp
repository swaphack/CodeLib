#include "MidpointTerrian.h"
#include "TerrianHelper.h"
alg::MidpointTerrian::MidpointTerrian()
{
}

alg::MidpointTerrian::~MidpointTerrian()
{
}

void alg::MidpointTerrian::setSrc(const math::Vector3& src)
{
    _src = src;
}

const math::Vector3& alg::MidpointTerrian::getSrc() const
{
    return _src;
}

void alg::MidpointTerrian::setDest(const math::Vector3& dest)
{
    _dest = dest;
}

const math::Vector3& alg::MidpointTerrian::getDest() const
{
    return _dest;
}

void alg::MidpointTerrian::setOffsetPosition(const math::Vector3& offset)
{
    _offsetPosition = offset;
}

const math::Vector3& alg::MidpointTerrian::getOffsetPosition() const
{
    return _offsetPosition;
}

std::vector<math::Vector3> alg::MidpointTerrian::createPoints(int count)
{
    std::vector<math::Vector3> points;
    points.push_back(_src);
    points.push_back(_dest);

    if (_src == _dest)
    {
        return points;
    }

    math::Vector3 offset0 = _offsetPosition;
    math::Vector3 offset1 = -1.0f * _offsetPosition;

    math::Vector3 minOffset, maxOffset;
    TerrianHelper::getRange(offset0, offset1, minOffset, maxOffset);

    for (int i = 0; i < count; i++)
    {
        float value = 1.0f / powf(2, i);
        offset0 = minOffset * value;
        offset1 = maxOffset * value;
        std::vector<math::Vector3> newPoints;
        for (int j = 0; j < points.size() - 1; j++)
        {
            math::Vector3 src = points[j];
            math::Vector3 dest = points[j + 1];
            math::Vector3 midpoint = 0.5f * (src + dest);
            math::Vector3 offset = TerrianHelper::getRandomPosition(offset0, offset1);
            midpoint += offset;
            newPoints.push_back(src);
            newPoints.push_back(midpoint);
        }
        newPoints.push_back(points[points.size() - 1]);
        points = newPoints;
    }

    return points;
}
