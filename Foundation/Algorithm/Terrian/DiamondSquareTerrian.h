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
    *   ����-������
    */
    class DiamondSquareTerrian
    {
    public:
        /**
        *   �ı���
        */
        struct Quadrilateral
        {
            /**
            *   ���½�
            */
            math::Vector3 leftBottom;
            /**
            *   ���½�
            */
            math::Vector3 rightBottom;
            /**
            *    ���Ͻ�
            */
            math::Vector3 rightTop;
            /**
            *    ���Ͻ�
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
            *    ���ĵ�
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
        *   ƫ��ֵ
        */
        void setOffset(float min, float max);
        /**
        *   ���ö���
        */
        void setPoints(const math::Vector3& leftBottom, const math::Vector3& rightBottom,
            const math::Vector3& rightTop, const math::Vector3& leftTop);
    public:
        /**
        *   �����ı���
        */
        std::vector<Quadrilateral> createQuads(int count);
        /**
        *   ����
        */
        void autoDivide(const Quadrilateral& quad, const math::Vector3& offset,
            Quadrilateral& quad0, Quadrilateral& quad1, Quadrilateral& quad2, Quadrilateral& quad3);
    private:
        /**
        *   ���½�
        */
        math::Vector3 _leftBottom;
        /**
        *   ���½�
        */
        math::Vector3 _rightBottom;
        /**
        *    ���Ͻ�
        */
        math::Vector3 _rightTop;
        /**
        *    ���Ͻ�
        */
        math::Vector3 _leftTop;
        /**
        *    ƫ��
        */
        math::FloatInterval _offset;
    };
}
