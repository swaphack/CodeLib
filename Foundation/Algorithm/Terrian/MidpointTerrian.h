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
    *   һά�����е�������
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
        *   ��ʼ��
        */
        void setSrc(const math::Vector3& src);
        /**
        *   ��ʼ��
        */
        const math::Vector3& getSrc() const;
        /**
        *   Ŀ���
        */
        void setDest(const math::Vector3& dest);
        /**
        *   Ŀ���
        */
        const math::Vector3& getDest() const;
        /**
        *   ƫ��ֵ
        */
        void setOffsetPosition(const math::Vector3& offset);
        /**
        *   ƫ��ֵ
        */
        const math::Vector3& getOffsetPosition() const;
    public:
        /**
        *   ���ɵ�
        */
        std::vector<math::Vector3> createPoints(int count);
    private:
        /**
        *   ��ʼλ��
        */
        math::Vector3 _src;
        /**
        *   �յ�λ��
        */
        math::Vector3 _dest;
        /**
        *   ƫ��λ��
        */
        math::Vector3 _offsetPosition;
    };
}