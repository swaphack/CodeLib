#pragma once

#include <vector>
#include <string>

namespace script
{
	// ���ż���
	class SingalSet
	{
	private:
		SingalSet();
	public:
		~SingalSet();
	public:
		static SingalSet* getInstance();
		// ׷��һ���ؼ���
		void append(const char* keyword);
		// �ж��Ƿ�����Ĺؼ���,
		// �ɹ����عؼ��ֳ��ȣ�ʧ�ܷ���-1
		int contain(const char* keyword);
		// ������йؼ���
		void clear();
	protected:
		void init();
	private:
		typedef std::vector<std::string> Words;
		// ������
		Words m_vSingals;
	};	
}