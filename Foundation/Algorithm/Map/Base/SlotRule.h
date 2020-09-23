#pragma once

#include "RelationTable.h"

namespace alg
{
	namespace map
	{
		// ��۹���
		template<const int Count, const uint8_t DefaultValue>
		class SlotRule : public RelationSquareTable<Count>
		{
			typedef RelationSquareTable<Count> base;
		public:
			SlotRule() {}
			virtual ~SlotRule() {}
		public:
			/**
			*	��Ӳ�۹���
			*/
			template<uint32_t Key, uint32_t Length>
			void addRelation(uint32_t startIndex, ...)
			{
				uint32_t* value = math::GET_PARAMETERS(Length, startIndex);
				for (int i = 0; i < Length; i++)
				{
					base::setValue(Key, value[i], DefaultValue);
				}
				free(value);
			}
			/**
			*	��Ӳ�۹���
			*/
			template<uint32_t Key, uint32_t Length>
			void addRelation(uint32_t startIndex, va_list ap)
			{
				uint32_t* value = math::GET_PARAMETERS(Length, startIndex, ap);
				for (int i = 0; i < Length; i++)
				{
					base::setValue(Key, value[i], DefaultValue);
				}
				free(value);
			}
			/**
			*	��Ӳ�۹���
			*/
			template<uint32_t Length>
			void addRelation(uint32_t key, uint32_t startIndex, va_list ap)
			{
				uint32_t* value = math::GET_PARAMETERS(Length, startIndex, ap);
				for (int i = 0; i < Length; i++)
				{
					base::setValue(key, value[i], DefaultValue);
				}
				free(value);
			}
			/**
			*	��ȡ����
			*/
			template<uint32_t Key>
			bool getRelations(std::vector<uint32_t>& relations) const
			{
				return base::getRelations(Key, DefaultValue, relations);
			}
			/**
			*	��ȡ����
			*/
			bool getRelations(uint32_t Key, std::vector<uint32_t>& relations) const
			{
				return base::getRelations(Key, DefaultValue, relations);
			}

			/**
			*	�ж������Ƿ��й���
			*/
			bool hasRelation(uint32_t src, uint32_t dest)
			{
				return base::equal(src, dest, DefaultValue);
			}
		};
	}
}