#pragma once

#include <string>

namespace web
{
	// �������
	class CacheIdentity
	{
	public:
		CacheIdentity();
		virtual ~CacheIdentity();
	public:
		// ��ʶid
		int getID();
		// ����
		const char* getName();
		void setName(const char* name);
		// �������
		void setInControl(bool status);
		bool isInControl();
	protected:
		// ����id����cachemgr����
		void makeID();
	private:
		// ��ʶid
		int _id;
		// ����
		std::string _name;
		// �Ƿ��ڻ��������
		bool _bInCacheControl;
	};
}