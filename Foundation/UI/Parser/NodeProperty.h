#pragma once

#include "macros.h"
#include <map>
#include <string>

namespace ui
{
	typedef std::map<std::string, std::string> Attributes;

	// ui����
	class NodeProperty: public sys::Name
	{
	public:
		NodeProperty();
		virtual ~NodeProperty();
	public:
		// ���������������
		void Clear();

		// ��������ֵ
		void setAttribute(const char* name, bool value);
		void setAttribute(const char* name, const char* value);
		void setAttribute(const char* name, char value);
		void setAttribute(const char* name, short value);
		void setAttribute(const char* name, int value);
		void setAttribute(const char* name, float value);
		void setAttribute(const char* name, double value);
		void setAttribute(const char* name, long value);
		void setAttribute(const char* name, uchar value);
		void setAttribute(const char* name, ushort value);
		void setAttribute(const char* name, uint value);
		void setAttribute(const char* name, ulong value);
		void setAttribute(const char* name, const sys::Vector& value);
		void setAttribute(const char* name, const sys::Point& value);
		void setAttribute(const char* name, const sys::Color4B& value);
		void setAttribute(const char* name, const sys::Size& value);
		void setAttribute(const char* name, const sys::Rect& value);

		template<typename T>
		void setAttribute(const char* name, const T& value);

		// ��ȡ����ֵ
		bool getAttribute(const char* name, bool& value);
		bool getAttribute(const char* name, std::string& defaultValue);
		bool getAttribute(const char* name, char& defaultValue);
		bool getAttribute(const char* name, short& defaultValue);
		bool getAttribute(const char* name, int& defaultValue);
		bool getAttribute(const char* name, float& defaultValue);
		bool getAttribute(const char* name, double& defaultValue);
		bool getAttribute(const char* name, long& defaultValue);
		bool getAttribute(const char* name, uchar& defaultValue);
		bool getAttribute(const char* name, ushort& defaultValue);
		bool getAttribute(const char* name, uint& defaultValue);
		bool getAttribute(const char* name, ulong& defaultValue);
		bool getAttribute(const char* name, sys::Vector& defaultValue);
		bool getAttribute(const char* name, sys::Point& defaultValue);
		bool getAttribute(const char* name, sys::Color4B& defaultValue);
		bool getAttribute(const char* name, sys::Size& defaultValue);
		bool getAttribute(const char* name, sys::Rect& defaultValue);

		template<typename T>
		bool getAttribute(const char* name, T& defaultValue);

		Attributes::const_iterator getAttributeFirst();
		Attributes::const_iterator getAttributeEnd();
	protected:
		// ͨ�ã���ȡ���Ե�ֵ���ַ������ͣ�
		const char* getAttribute(const char* name);
	protected:
		// ����
		Attributes _attributes;
	};

	template<typename T>
	bool NodeProperty::getAttribute(const char* name, T& defaultValue)
	{
		std::string value = "";
		if (!getAttribute(name, value))
		{
			return false;
		}

		defaultValue = *((T*)(value.c_str()));

		return true;
	}

	template<typename T>
	void NodeProperty::setAttribute(const char* name, const T& value)
	{
		int size = sizeof(T);
		char* dest = (char*)malloc(size);
		memcpy(dest, &defaultValue, size);
		this->setAttribute(name, dest);
		free(dest);
	}

}