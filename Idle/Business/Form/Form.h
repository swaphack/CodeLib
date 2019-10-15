#pragma once

#include <string>
#include <vector>
#include <map>

namespace business
{
	// 表头
	class FormHead
	{
	public:
		FormHead();
		virtual ~FormHead();
	public:
		void add(const std::string& strName);
		void remove(const std::string& strName);
		void insert(int nIdx, const std::string& strName);
		void removeAt(int nIdx);
		int indexOf(const std::string& strName);
		int length();
		void setHead(const std::vector<std::string>& vecName);
	private:
		// 名称
		std::vector<std::string> m_vecName;
	};

	// 记录
	class FormRecord
	{
	public:
		FormRecord();
		virtual ~FormRecord();
	public:
		void set(const std::string& strName, const std::string& strValue);
		const std::string& getValue(const std::string& strName);
	private:
		// 数据
		std::map<std::string, std::string> m_vecValue;
	};

	// 表格
	class Form
	{
	public:
	protected:
	private:
	};
}