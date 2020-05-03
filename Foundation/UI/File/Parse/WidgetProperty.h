#pragma once

#include "system.h"
#include "render.h"
#include <map>
#include <string>

namespace ui
{
	typedef std::map<std::string, std::string> Attributes;

	struct SizePolicy;

	// ui属性
	class WidgetProperty: public sys::Name
	{
	public:
		WidgetProperty();
		virtual ~WidgetProperty();
	public:
		// 清除已有属性配置
		void Clear();

		// 设置属性值
		void setAttribute(const char* name, bool value);
		void setAttribute(const char* name, const char* value);
		void setAttribute(const char* name, const std::string& value);
		void setAttribute(const char* name, char value);
		void setAttribute(const char* name, short value);
		void setAttribute(const char* name, int value);
		void setAttribute(const char* name, float value);
		void setAttribute(const char* name, double value);
		void setAttribute(const char* name, long value);
		void setAttribute(const char* name, uint8_t value);
		void setAttribute(const char* name, uint16_t value);
		void setAttribute(const char* name, uint32_t value);
		void setAttribute(const char* name, uint64_t value);
		void setAttribute(const char* name, const math::Vector3& value);
		void setAttribute(const char* name, const math::Vector2& value);
		void setAttribute(const char* name, const sys::Color4B& value);
		void setAttribute(const char* name, const math::Size& value);
		void setAttribute(const char* name, const math::Rect& value);
		void setAttribute(const char* name, const sys::Margin& value);
		void setAttribute(const char* name, const render::BlendParam& value);
		void setAttribute(const char* name, const SizePolicy& value);

		template<typename T>
		void setAttribute(const char* name, const T& value);

		// 获取属性值
		bool getAttribute(const char* name, bool& value);
		bool getAttribute(const char* name, std::string& defaultValue);
		bool getAttribute(const char* name, char& defaultValue);
		bool getAttribute(const char* name, short& defaultValue);
		bool getAttribute(const char* name, int& defaultValue);
		bool getAttribute(const char* name, float& defaultValue);
		bool getAttribute(const char* name, double& defaultValue);
		bool getAttribute(const char* name, long& defaultValue);
		bool getAttribute(const char* name, uint8_t& defaultValue);
		bool getAttribute(const char* name, uint16_t& defaultValue);
		bool getAttribute(const char* name, uint32_t& defaultValue);
		bool getAttribute(const char* name, uint64_t& defaultValue);
		bool getAttribute(const char* name, math::Vector3& defaultValue);
		bool getAttribute(const char* name, math::Vector2& defaultValue);
		bool getAttribute(const char* name, sys::Color4B& defaultValue);
		bool getAttribute(const char* name, math::Size& defaultValue);
		bool getAttribute(const char* name, math::Rect& defaultValue);
		bool getAttribute(const char* name, sys::Margin& defaultValue);
		bool getAttribute(const char* name, render::BlendParam& defaultValue);
		bool getAttribute(const char* name, SizePolicy& defaultValue);

		template<typename T>
		bool getAttribute(const char* name, T& defaultValue);

		Attributes::const_iterator getAttributeBegin();
		Attributes::const_iterator getAttributeEnd();
	protected:
		// 通用，获取属性的值（字符串类型）
		const char* getAttribute(const char* name);
	protected:
		// 属性
		Attributes _attributes;
	};

	template<typename T>
	bool WidgetProperty::getAttribute(const char* name, T& defaultValue)
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
	void WidgetProperty::setAttribute(const char* name, const T& value)
	{
		int size = sizeof(T);
		sys::MemoryData data(size, &value);
		this->setAttribute(name, std::string(data.getValue(), size));
	}
}