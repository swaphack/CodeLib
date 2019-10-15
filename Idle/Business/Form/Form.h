#pragma once

#include <string>
#include <vector>
#include <map>

namespace business
{
	// ��ͷ
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
		// ����
		std::vector<std::string> m_vecName;
	};

	// ��¼
	class FormRecord
	{
	public:
		FormRecord();
		virtual ~FormRecord();
	public:
		void set(const std::string& strName, const std::string& strValue);
		const std::string& getValue(const std::string& strName);
	private:
		// ����
		std::map<std::string, std::string> m_vecValue;
	};

	// ���
	class Form
	{
	public:
	protected:
	private:
	};
}