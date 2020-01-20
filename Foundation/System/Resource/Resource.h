#pragma once



#include "Framework/Object.h"

#include "IResource.h"

namespace sys
{
	// վ����Դ����
	class Resource : public Object, public IResource
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
		virtual std::string getName() { return ""; }
		// ����
		virtual CacheGroup* getCache();
		// �����ļ�����
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler);
	public:
		// ������Դλ��
		void setUrl(const std::string& url);
		// ��ȡ��Դλ��
		std::string getUrl();

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