#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "system.h"
#include "mathlib.h"

namespace alg
{
    /**
    *   一维地形中点生成器
    */
    class MidpointTerrian
    {
    public:
        typedef std::function<void(math::Vector3 startPoint, math::Vector3 midPoint, math::Vector3 endPoint)> MidpointHandle;
    public:
        MidpointTerrian();
        ~MidpointTerrian();
    public:
        /**
        *   起始点
        */
        void setSrc(const math::Vector3& src);
        /**
        *   起始点
        */
        const math::Vector3& getSrc() const;
        /**
        *   目标点
        */
        void setDest(const math::Vector3& dest);
        /**
        *   目标点
        */
        const math::Vector3& getDest() const;
        /**
        *   偏移值
        */
        void setOffsetPosition(const math::Vector3& offset);
        /**
        *   偏移值
        */
        const math::Vector3& getOffsetPosition() const;
    public:
        /**
        *   生成点
        */
        std::vector<math::Vector3> createPoints(int count);
    private:
        /**
        *   起始位置
        */
        math::Vector3 _src;
        /**
        *   终点位置
        */
        math::Vector3 _dest;
        /**
        *   偏移位置
        */
        math::Vector3 _offsetPosition;
    };
}