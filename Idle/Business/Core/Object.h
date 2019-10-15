#pragma once

#include <cstdint>
#include <string>

namespace business
{
	// ����
	class Object
	{
	public:
		Object();
		virtual ~Object();
	public:
		// ���
		uint64_t getID();
		// ����
		const std::string& getName();
		void setName(const std::string& strName);

		// ����ʱ��
		uint64_t getCreateTime();
	protected:
	private:
		static uint64_t s_nID;

		// ���
		uint64_t m_nID = 0;
		// ����
		std::string m_strName;
		// ����ʱ��
		uint64_t m_nCreateTime = 0;
	};
}