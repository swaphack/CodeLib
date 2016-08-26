#pragma once

#include <string>

namespace web
{
	enum DataType
	{
		EDT_TEXT,		// �ı�
		EDT_REAL,		// ʵ��
	};

	// ���Ա
	struct TableMember
	{
		// ����
		std::string Name;
		// ����
		int DataType;
		// ����
		int Length;
		// Ĭ��ֵ
		std::string Default;
		// �Ƿ�ؼ���
		bool PrimaryKey;
	};
}