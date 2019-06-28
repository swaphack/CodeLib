#pragma once

#include <functional>
#include <cstdint>
#include <map>

namespace game
{
	/**
	*	属性
	*	新的属性类型，需要重载模板
	*/
	class Property
	{
	public:
		struct ValueItem
		{
			void* ptr = nullptr;
			size_t size = 0;
			ValueItem()
			{}
			ValueItem(void* ptr, size_t size)
				:ptr(ptr), size(size)
			{
			}
			~ValueItem()
			{
				if (ptr)
				{
					free(ptr);
				}
			}

			ValueItem clone()
			{
				ValueItem item;
				item.size = size;
				item.ptr = malloc(size);
				memcpy(item.ptr, this->ptr, this->size);
				return item;
			}
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
		void setValue(const std::string& nType, const void* src, size_t size);

		bool getValue(const std::string& nType, bool& value);
		bool getValue(const std::string& nType, int8_t& value);
		bool getValue(const std::string& nType, uint8_t& value);
		bool getValue(const std::string& nType, int16_t& value);
		bool getValue(const std::string& nType, uint16_t& value);
		bool getValue(const std::string& nType, int32_t& value);
		bool getValue(const std::string& nType, uint32_t& value);
		bool getValue(const std::string& nType, int64_t& value);
		bool getValue(const std::string& nType, uint64_t& value);
		bool getValue(const std::string& nType, float& value);
		bool getValue(const std::string& nType, double& value);
		bool getValue(const std::string& nType, std::string& value);
		bool getValue(const std::string& nType, void* src, size_t& size);

		void setValue(const std::string& nType, const ValueItem& item);
		void setValues(const std::map<std::string, ValueItem>& values);
		const std::map<std::string, ValueItem>& getValues();

		template<typename T>
		void setValue(const std::string& nType, T value)
		{
			this->setValue(nType, &value, sizeof(T));
		}
		template<typename T>
		bool getValue(const std::string& nType, T& value)
		{
			this->getValue(nType, &value, sizeof(T));
		}
		/**
		*	克隆
		*/
		Property* clone();
	private:
		std::map<std::string, ValueItem> m_mapValues;
	};
}