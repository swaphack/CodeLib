#pragma once

#include "Set.h"
#include "Function/Function.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	���
	*	����ö��
	*	һ���ú�����ʾ
	*/
	class InfiniteSet : public Set
	{
	public:
		InfiniteSet();
		InfiniteSet(const InfiniteSet& value);
		virtual ~InfiniteSet();
	public:
		/**
		*	������
		*/
		CREATE_CLASS_MEMBER(Domain, Domain);
		/**
		*	���ƺ���
		*/
		CREATE_CLASS_MEMBER(Function, Function);
	public:
		/**
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const Element* value) const;
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isNone() const;
		/**
		*	����
		*/
		InfiniteSet unionAll(const InfiniteSet& value) const;
		/**
		*	����
		*/
		InfiniteSet intersect(const InfiniteSet& value) const;
		/**
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		InfiniteSet complementary(const InfiniteSet& value) const;
		/**
		*	��̼�
		*/
		InfiniteSet successor() const;
	};
}