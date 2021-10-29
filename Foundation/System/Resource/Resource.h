#pragma once

#include <string>
#include <cstdint>

#include "Framework/Object.h"

#include "IResource.h"

namespace sys
{
	class CacheGroup;

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
		virtual CacheGroup* getCache() const;
		// �����ļ�����
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler);
	public:
		// ������Դλ��
		void setUrl(const std::string& url);
		// ��ȡ��Դλ��
		const std::string& getUrl() const;

		// �����Ƿ�ʹ�û���
		void setCacheEnable(bool status);
		// �Ƿ�ʹ�û���
		bool isCacheEnable() const;
		// ��ջ���
		void clearCache();
	protected:
		// ��Դλ��
		std::string _url;
		// �����Ƿ����
		bool _bCacheEnabled = false;
		// ����
		CacheGroup* _cache = nullptr;
	};
}