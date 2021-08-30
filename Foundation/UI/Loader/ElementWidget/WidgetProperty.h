#pragma once

#include "system.h"
#include <map>
#include <string>
#include "render.h"
#include "Layout/macros.h"

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
		void setAttribute(const std::string& name, bool value);
		void setAttribute(const std::string& name, const std::string& value);
		void setAttribute(const std::string& name, char value);
		void setAttribute(const std::string& name, short value);
		void setAttribute(const std::string& name, int value);
		void setAttribute(const std::string& name, float value);
		void setAttribute(const std::string& name, double value);
		void setAttribute(const std::string& name, long value);
		void setAttribute(const std::string& name, uint8_t value);
		void setAttribute(const std::string& name, uint16_t value);
		void setAttribute(const std::string& name, uint32_t value);
		void setAttribute(const std::string& name, uint64_t value);
		void setAttribute(const std::string& name, const math::Vector3& value);
		void setAttribute(const std::string& name, const math::Vector2& value);
		void setAttribute(const std::string& name, const phy::Color4B& value);
		void setAttribute(const std::string& name, const phy::Color3B& value);
		void setAttribute(const std::string& name, const phy::Color4F& value);
		void setAttribute(const std::string& name, const phy::Color3F& value);
		void setAttribute(const std::string& name, const math::Size& value);
		void setAttribute(const std::string& name, const math::Rect& value);
		void setAttribute(const std::string& name, const sys::CSSMargin& value);
		void setAttribute(const std::string& name, const sys::CSSSize& value);
		void setAttribute(const std::string& name, const render::BlendParam& value);
		void setAttribute(const std::string& name, const MarginState& value);

// 		template<typename T>
// 		void setAttribute(const std::string& name, const T& value);

		// 获取属性值
		bool getAttribute(const std::string& name, bool& value);
		bool getAttribute(const std::string& name, std::string& defaultValue);
		bool getAttribute(const std::string& name, char& defaultValue);
		bool getAttribute(const std::string& name, short& defaultValue);
		bool getAttribute(const std::string& name, int& defaultValue);
		bool getAttribute(const std::string& name, float& defaultValue);
		bool getAttribute(const std::string& name, double& defaultValue);
		bool getAttribute(const std::string& name, long& defaultValue);
		bool getAttribute(const std::string& name, uint8_t& defaultValue);
		bool getAttribute(const std::string& name, uint16_t& defaultValue);
		bool getAttribute(const std::string& name, uint32_t& defaultValue);
		bool getAttribute(const std::string& name, uint64_t& defaultValue);
		bool getAttribute(const std::string& name, math::Vector3& defaultValue);
		bool getAttribute(const std::string& name, math::Vector2& defaultValue);
		bool getAttribute(const std::string& name, phy::Color3B& defaultValue);
		bool getAttribute(const std::string& name, phy::Color4B& defaultValue);
		bool getAttribute(const std::string& name, phy::Color3F& defaultValue);
		bool getAttribute(const std::string& name, phy::Color4F& defaultValue);
		bool getAttribute(const std::string& name, math::Size& defaultValue);
		bool getAttribute(const std::string& name, math::Rect& defaultValue);
		bool getAttribute(const std::string& name, sys::CSSMargin& defaultValue);
		bool getAttribute(const std::string& name, sys::CSSSize& defaultValue);
		bool getAttribute(const std::string& name, render::BlendParam& defaultValue);
		bool getAttribute(const std::string& name, MarginState& defaultValue);

// 		template<typename T>
// 		bool getAttribute(const std::string& name, T& defaultValue);

		Attributes::const_iterator getAttributeBegin();
		Attributes::const_iterator getAttributeEnd();
	protected:
		// 通用，获取属性的值（字符串类型）
		std::string getAttribute(const std::string& name);
	protected:
		// 属性
		Attributes _attributes;
	};

// 	template<typename T>
// 	bool WidgetProperty::getAttribute(const std::string& name, T& defaultValue)
// 	{
// 		std::string value = "";
// 		if (!getAttribute(name, value))
// 		{
// 			return false;
// 		}
// 
// 		defaultValue = *((T*)(value.c_str()));
// 
// 		return true;
// 	}

// 	template<typename T>
// 	void WidgetProperty::setAttribute(const std::string& name, const T& value)
// 	{
// 		int size = sizeof(T);
// 		sys::MemoryData data(size, (const char*)&value);
// 		this->setAttribute(name, std::string((const char*)data.getValue(), size));
// 	}
}