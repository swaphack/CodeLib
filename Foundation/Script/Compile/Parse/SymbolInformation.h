#pragma once

#include "macros.h"

namespace script
{
	// ������Ϣ
	struct SymbolInformation
	{
		// ����
		std::string name;
		// ���ʽ
		std::string expression;
		// ���ȼ�
		int priorityLevel;

		// �Ƿ���Ƕ
		bool embed;
		// ��ʼ����
		std::string begin;
		// ��������
		std::string end;

		SymbolInformation()
			:name(""), expression(""), priorityLevel(0)
			, embed(false), begin(""), end(""){}

		// �Ƿ��ǿ�ʼ����
		bool isBegin(const char* value) const {
			return begin == value;
		}

		// �Ƿ��ǽ�������
		bool isEnd(const char* value) const {
			return end == value;
		}
	};
}