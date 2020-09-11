#pragma once

#include "MapObject.h"
#include "MapObjects.h"

namespace alg
{
	/**
	*	��ͼ�������
	*/
	class MapPoint : public MapObject
	{
	public:
		MapPoint();
		virtual ~MapPoint();
	public:
		/**
		*	��������
		*/
		void setPosition(const math::Vector3& pos);
		/**
		*	��ȡ����
		*/
		const math::Vector3& getPosition() const;
	protected:
		math::Vector3 _position;
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	��ͼ��ϵ��
	*/
	class MapRelation : public MapObject
	{
	public:
		MapRelation();
		virtual ~MapRelation();
	public:
		/**
		*	��ӵ�����
		*/
		void addMapIndex(uint32_t nLength, uint32_t startIndex, ...);
		/**
		*	��ӵ�����
		*/
		void addMapIndex(uint32_t nLength, uint32_t startIndex, va_list ap);
		/**
		*	��ӵ�����
		*/
		void addMapIndex(uint32_t mapIndex);
		/**
		*	�Ƴ�������
		*/
		void removeMapIndex(uint32_t mapIndex);
		/**
		*	�Ƴ����е�����
		*/
		void removeAllMapIndices();
		/**
		*	�Ƿ����������
		*/
		bool containMapIndex(uint32_t mapIndex) const;
		/**
		*	��ȡ��������
		*/
		const std::vector<uint32_t>& getMapIndices() const;
	public:
		/**
		*	��������
		*/
		uint32_t getMapIndexCount() const;
		/**
		*	��ȡ������
		*/
		uint32_t getMapIndex(uint32_t index) const;
		/**
		*	��ȡ����
		*/
		int32_t getIndex(uint32_t mapIndex) const;
	public:

	protected:
		// ������
		std::vector<uint32_t> _mapIndices;
	};
	//////////////////////////////////////////////////////////////////////////
	/**
	*	��ͼ
	*/
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	��������
		*/
		int32_t addPoint(const math::Vector3& point);
		/**
		*	�Ƴ����������
		*/
		void removeAllPoints();
		/**
		*	��ȡ����������
		*/
		uint32_t getPointCount() const;
		/**
		*	��ȡ������
		*/
		const math::Vector3* getPoint(uint32_t nIndex) const;
	public:
		/**
		*	��ӹ�ϵ
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<MapRelation, T>::value, T>::type>
		int32_t addRelation(uint32_t nLength, uint32_t start, ...)
		{
			T* mr = _mapRelations.create<T>();
			if (mr)
			{
				va_list ap;
				va_start(ap, start);
				mr->addMapIndex(nLength, start, ap);
				va_end(ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	��ӹ�ϵ
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<MapRelation, T>::value, T>::type>
		int32_t addRelation(uint32_t nLength, uint32_t start, va_list ap)
		{
			T* mr = _mapRelations.create<T>();
			if (mr)
			{
				mr->addMapIndex(nLength, start, ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	�Ƴ����й�ϵ
		*/
		void removeAllRelations();
		/**
		*	��ȡ��ϵ����
		*/
		uint32_t getRelationCount() const;
		/**
		*	��ȡ��ϵ
		*/
		bool getRelation(uint32_t nIndex, std::vector<uint32_t>& indices) const;
	public:
		/**
		*	�������ڽڵ�
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		// ��ͼ�����꼯
		MapObjects<MapPoint> _mapPoints;
		// ��ͼ���ϵ��
		MapObjects<MapRelation> _mapRelations;
	};
}
