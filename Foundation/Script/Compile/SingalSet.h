#pragma once

#include <functional>
#include <vector>
#include <map>
#include <string>

#include "macros.h"

namespace script
{
	// ���ż���
	class SingalSet
	{
	private:
		SingalSet();
	public:
		~SingalSet();
	public:
		static SingalSet* getInstance();
		/** 
		*	���һ�������
		*	@param name �����
		*/
		void addOperator(const char* name);
		/**
		*	�ж��Ƿ�����������,�����ж��ַ�������
		*	�ɹ�������������ȣ�ʧ�ܷ���-1
		*	@param name �����
		*/
		int containOperator(const char* name);
		/** 
		*	������������
		*/
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::vector<std::string> > OperatorLevelAry;
		OperatorLevelAry m_vOperatorSingals;

	};	
}