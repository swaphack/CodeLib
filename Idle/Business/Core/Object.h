#pragma once

#include <cstdint>
#include <string>

namespace business
{
	// 对象
	class Object
	{
	public:
		Object();
		virtual ~Object();
	public:
		// 编号
		uint64_t getID();
		// 名称
		const std::string& getName();
		void setName(const std::string& strName);

		// 创建时间
		uint64_t getCreateTime();
	protected:
	private:
		static uint64_t s_nID;

		// 编号
		uint64_t m_nID = 0;
		// 名称
		std::string m_strName;
		// 创建时间
		uint64_t m_nCreateTime = 0;
	};
}