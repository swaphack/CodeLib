#pragma once

#include "system.h"

namespace alg
{
	/**
	*	������Ϣ
	*/
	class ObjectDetail : public sys::Object
	{
	public:
		ObjectDetail();
		virtual ~ObjectDetail();
	public:
		/**
		*	��������
		*/
		void setName(const std::string& name);
		/**
		*	��ȡ����
		*/
		const std::string& getName() const;
		/**
		*	���ñ��
		*/
		void setTag(int tag);
		/**
		*	��ȡ���
		*/
		int getTag() const;
	protected:
		// ����
		std::string _name;
		// ���
		int _tag = 0;
	};
}