#pragma once

#include "macros.h"
#include <map>
#include <string>

namespace uieditor
{
	class UIElementLoader
	{
	public:
		UIElementLoader();
		virtual ~UIElementLoader();
	public:
		// 获取名称
		const char* getName();
		// 设置名称
		void setName(const char* name);

		// 设置属性值
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
		void setAttribute(const char* name, sys::Vector vec);
		void setAttribute(const char* name, sys::Point point);
		void setAttribute(const char* name, sys::Color4B color);
		void setAttribute(const char* name, sys::Size zie);
		void setAttribute(const char* name, sys::Rect rect);


		// 获取属性值
		const char* getAttribute(const char* name, const char* defaultValue = nullptr);
		char getChar(const char* name, char defaultValue = 0);
		short getShort(const char* name, short defaultValue = 0);
		int getInteger(const char* name, int defaultValue = 0);
		float getFloat(const char* name, float defaultValue = 0);
		double getDouble(const char* name, double defaultValue = 0);
		long getLong(const char* name, long defaultValue = 0);
		uchar getUChar(const char* name, uchar defaultValue = 0);
		ushort getUShort(const char* name, ushort defaultValue = 0);
		uint getUInteger(const char* name, uint defaultValue = 0);
		ulong getULong(const char* name, ulong defaultValue = 0);
		sys::Vector gsetAttribute(const char* name, sys::Vector defaultValue = { 0, 0, 0 });
		sys::Point getAttribute(const char* name, sys::Point defaultValue = { 0, 0 });
		sys::Color4B getAttribute(const char* name, sys::Color4B defaultValue = { 0, 0, 0, 0 });
		sys::Size getAttribute(const char* name, sys::Size defaultValue = { 0, 0 });
		sys::Rect getAttribute(const char* name, sys::Rect defaultValue = { 0, 0, 0, 0 });
	protected:
		std::map<std::string, std::string> _attributes;
	private:
	};
}