#pragma once

#include <functional>
#include <cstdint>
#include <map>
#include <type_traits>
#include <cassert>

namespace game
{
	/**
	*	属性
	*	新的属性类型，需要重载模板
	*/
	class Property
	{
	#define GET_VALUE(name, Type, value) \
	{ \
		void* ptr = getValue(name, nullptr); \
		if (!ptr) return value; \
		return *((Type*)ptr); \
	}
	public:
		struct ValueItem
		{
			void* ptr = nullptr;
			size_t size = 0;
			bool bPtr = true;
			ValueItem();
			ValueItem(void* ptr, size_t size);
			ValueItem(void* ptr);
			~ValueItem();

			ValueItem clone();
		};
	public:
		Property();
		virtual ~Property();
	public:
		void setValue(const std::string& nType, bool value);
		void setValue(const std::string& nType, int8_t value);
		void setValue(const std::string& nType, uint8_t value);
		void setValue(const std::string& nType, int16_t value);
		void setValue(const std::string& nType, uint16_t value);
		void setValue(const std::string& nType, int32_t value);
		void setValue(const std::string& nType, uint32_t value);
		void setValue(const std::string& nType, int64_t value);
		void setValue(const std::string& nType, uint64_t value);
		void setValue(const std::string& nType, float value);
		void setValue(const std::string& nType, double value);
		void setValue(const std::string& nType, const std::string& value);
		void setValue(const std::string& nType, void* ptr);
		void setValue(const std::string& nType, const void* src, size_t size);
		void setValue(const std::string& nType, const ValueItem& item);
		void setValues(const std::map<std::string, ValueItem*>& values);

		bool getValue(const std::string& nType, bool value = false);
		int8_t getValue(const std::string& nType, int8_t value = 0);
		uint8_t getValue(const std::string& nType, uint8_t value = 0);
		int16_t getValue(const std::string& nType, int16_t value = 0);
		uint16_t getValue(const std::string& nType, uint16_t value = 0);
		int32_t getValue(const std::string& nType, int32_t value = 0);
		uint32_t getValue(const std::string& nType, uint32_t value = 0);
		int64_t getValue(const std::string& nType, int64_t value = 0);
		uint64_t getValue(const std::string& nType, uint64_t value = 0);
		float getValue(const std::string& nType, float value = 0);
		double getValue(const std::string& nType, double value = 0);
		std::string getValue(const std::string& nType, const std::string& value = "");
		const std::map<std::string, ValueItem*>& getValues() const;

		void* getPtr(const std::string& nType, void* value = nullptr);
		bool getPtr(const std::string& nType, void* &src, size_t& size);

		template<typename T, 
			typename = std::enable_if < std::is_class<T>::value || std::is_arithmetic<T>::value, T >::type >
		void setValue(const std::string& nType, T value)
		{
			this->setValue(nType, &value, sizeof(T));
		}
		template<typename T, 
			typename = std::enable_if < std::is_class<T>::value, T >::type >
		T& getClass(const std::string& nType)
		{
			void* ptr = getPtr(nType, nullptr);
			assert(ptr != nullptr);
			return *((T*)ptr);
		}

		template<typename T,
			typename = std::enable_if < std::is_arithmetic<T>::value, T >::type >
			T getArithmetic(const std::string& nType, const T& value = 0)
		{
			void* ptr = getPtr(nType, nullptr);
			if (!ptr) return value;
			return *((T*)ptr);
		}
		/**
		*	克隆
		*/
		Property* clone();
		/**
		*	清空
		*/
		void clear();
	private:
		// 对应的值
		std::map<std::string, ValueItem*> m_mapValues;
	};
}