#pragma once

#include <vector>
#include <string>

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
		// 追加一个关键字
		void append(const char* keyword);
		// 判断是否包含改关键字,
		// 成功返回关键字长度，失败返回-1
		int contain(const char* keyword);
		// 清空所有关键字
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// 符号字
		Words m_vSingals;
	};	
}