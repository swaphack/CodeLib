#pragma once

#include <string>

#include "IResource.h"

namespace web
{
	// վ����Դ����
	class Resource : public IResource
	{
	public:
		Resource();
		virtual ~Resource();
	public:
		virtual void init();
		// ����
		virtual void save();
		// ����
		virtual void dispose();
		// ����
		virtual const char* getName() { return ""; }
		// ����
		virtual CacheGroup* getCache();
	public:
		// ������Դλ��
		void setUrl(const char* url);
		// ��ȡ��Դλ��
		const char* getUrl();

		// �����Ƿ�ʹ�û���
		void setCacheEnable(bool status);
		// �Ƿ�ʹ�û���
		bool isCacheEnable();
		// ��ջ���
		void clearCache();
	protected:
		// ��Դλ��
		std::string _url;
		// �����Ƿ����
		bool _bCacheEnabled;
		// ����
		CacheGroup* _cache;
	};
}