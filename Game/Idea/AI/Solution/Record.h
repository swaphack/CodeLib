#pragma once

#include "macros.h"
#include "system.h"
#include <string>

namespace idea
{
	// ��¼�¼�
	class Record : public Event
	{
	public:
		Record();
		virtual ~Record();
	public:
		// ��ȡ��¼��������
		const sys::Time* getTime();
		// ���ü�¼��������
		void setTime(sys::Time* time);
		// ��ȡ��¼����
		const char* getText();
		// ���ü�¼����
		void setText(const char* text);
		// ��ȡ��¼��ʶ�ȼ�
		int getLevel();
		// ���ü�¼��ʶ�ȼ�
		void setLevel(int level);
	private:
		// ʱ��
		sys::Time _time;
		// �ı�
		std::string _text;
		// ����
		int _level;
	};
}