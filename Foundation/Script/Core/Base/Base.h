#pragma once

#include "macros.h"
#include <string>

namespace script
{
	// 访问域
	enum AccessType
	{
		// 公共
		E_ACCESSTYPE_PUBLIC,
		// 保护
		E_ACCESSTYPE_PROTECTED,
		// 内部
		E_ACCESSTYPE_INTERNAL,
		// 私有
		E_ACCESSTYPE_PRIVATE,
	};

	class Base
	{
	public:
		Base();
		virtual ~Base();
	public:
		// 设置访问域类型
		int getAccessType();
		// 设置访问域类型
		void setAccessType(int nType);

		// 获取名称
		const char* getName();
		// 设置名称
		void setName(const char* name);
		// 销毁
		virtual void dispose();
	private:
		std::string m_strName;
		// 访问域类型
		int m_nAccessType;
	};
}