#pragma once

#include "Property.h"

namespace tribe
{
	// ����
	class Job
	{
	public:
		Job();
		virtual ~Job();
	public:
		// ��ȡְҵ����
		inline int getProfession() const { return _profession; }
		// ����ְҵ����
		inline void setProfession(int val) { _profession = val; }
		// ��ȡ������ʼʱ��
		inline int getBeginTime() const { return _beginTime; }
		// ���ù�����ʼʱ��
		inline void setBeginTime(int val) { _beginTime = val; }
		// ��ȡ��������ʱ��
		inline int getEndTime() const { return _endTime; }
		// ���ù�������ʱ��
		inline void setEndTime(int val) { _endTime = val; }

		// ��ȡ�����ȼ�
		inline int getLevel() const { return _level; }
		// ���ù����ȼ�
		inline void setLevel(int val) { _level = val; }
		// ��ȡ��������
		inline int getExp() const { return _exp; }
		// ���ù�������
		inline void setExp(int val) { _exp = val; }
	protected:
	private:
		// ְҵ����
		int _profession;
		// ����
		Property* _property;
		// ������ʼʱ��
		int _beginTime;
		// ��������ʱ��
		int _endTime;
		// �ȼ�
		int _level;
		// ����
		int _exp;
	};
}