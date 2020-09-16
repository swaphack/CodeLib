#pragma once

#include "MapObject.h"

namespace alg
{
	/**
	*	��ͼ��ϵ
	*/
	class MapRelation : public MapObject
	{
	public:
		MapRelation();
		virtual ~MapRelation();
	public:
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t nLength, uint32_t startIndex, ...);
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t nLength, uint32_t startIndex, va_list ap);
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t relationIndex);
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t relationIndex0, uint32_t relationIndex1);
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t relationIndex0, uint32_t relationIndex1, uint32_t relationIndex2);
		/**
		*	��ӹ���
		*/
		void addRelation(uint32_t nLength, uint32_t relationIndex[]);
		/**
		*	��ӹ���
		*/
		void addRelation(const std::vector<uint32_t>& relationIndex);
		/**
		*	�Ƴ�����
		*/
		void removeRelation(uint32_t relationIndex);
		/**
		*	�Ƴ����й���
		*/
		void removeAllRelations();
		/**
		*	�Ƿ��������
		*/
		bool containRelation(uint32_t relationIndex) const;
		/**
		*	��ȡ��������
		*/
		const std::vector<uint32_t>& getAllRelations() const;
	public:
		/**
		*	��������
		*/
		uint32_t getRelationCount() const;
		/**
		*	��ȡ����
		*/
		uint32_t getRelation(uint32_t index) const;
		/**
		*	��ȡ����
		*/
		int32_t getRelationIndex(uint32_t relationIndex) const;
	public:

	protected:
		// ����
		std::vector<uint32_t> _relations;
	};
}