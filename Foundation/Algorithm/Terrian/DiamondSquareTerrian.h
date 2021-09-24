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
    *   棱形-正方形
    */
    class DiamondSquareTerrian
    {
    public:
        /**
        *   四边形
        */
        struct Quadrilateral
        {
            /**
            *   左下角
            */
            math::Vector3 leftBottom;
            /**
            *   右下角
            */
            math::Vector3 rightBottom;
            /**
            *    右上角
            */
            math::Vector3 rightTop;
            /**
            *    左上角
            */
            math::Vector3 leftTop;

            Quadrilateral() {}
            Quadrilateral(const math::Vector3& lb, const math::Vector3& rb,
                const math::Vector3& rt, const math::Vector3& lt)
            {
                leftBottom = lb;
                rightBottom = rb;
                rightTop = rt;
                leftTop = lt;
            }
            /**
            *    中心点
            */
            math::Vector3 getCenterPoint() const
            {
                return 0.25f * (leftBottom + rightBottom + rightTop + leftTop);
            }
        };
    public:
        DiamondSquareTerrian();
        ~DiamondSquareTerrian();
    public:
        /**
        *   偏移值
        */
        void setOffset(float min, float max);
        /**
        *   设置顶点
        */
        void setPoints(const math::Vector3& leftBottom, const math::Vector3& rightBottom,
            const math::Vector3& rightTop, const math::Vector3& leftTop);
    public:
        /**
        *   创建四边形
        */
        std::vector<Quadrilateral> createQuads(int count);
        /**
        *   分裂
        */
        void autoDivide(const Quadrilateral& quad, const math::Vector3& offset,
            Quadrilateral& quad0, Quadrilateral& quad1, Quadrilateral& quad2, Quadrilateral& quad3);
    private:
        /**
        *   左下角
        */
        math::Vector3 _leftBottom;
        /**
        *   右下角
        */
        math::Vector3 _rightBottom;
        /**
        *    右上角
        */
        math::Vector3 _rightTop;
        /**
        *    左上角
        */
        math::Vector3 _leftTop;
        /**
        *    偏移
        */
        math::FloatInterval _offset;
    };
}
