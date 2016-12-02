#pragma once

#include <functional>
#include <vector>
#include <map>
#include <string>

#include "macros.h"

namespace script
{
	// 符号集合
	class SingalSet
	{
	private:
		SingalSet();
	public:
		~SingalSet();
	public:
		static SingalSet* getInstance();
		/** 
		*	添加一个运算符
		*	@param name 运算符
		*/
		void addOperator(const char* name);
		/**
		*	判断是否包含改运算符,优先判断字符串长度
		*	成功返回运算符长度，失败返回-1
		*	@param name 运算符
		*/
		int containOperator(const char* name);
		/** 
		*	清空所有运算符
		*/
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::vector<std::string> > OperatorLevelAry;
		OperatorLevelAry m_vOperatorSingals;

	};	
}