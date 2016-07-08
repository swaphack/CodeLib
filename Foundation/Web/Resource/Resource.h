#pragma once

#include <string>

namespace web
{
	// վ����Դ����
	class Resource
	{
	public:
		Resource();
		~Resource();
	public:
		// ������Դ·��
		void setResourcePath(const char* resPath);
		// ��ȡ��Դ·��
		const char* getResourcePath();
		// �����ļ�
		std::string loadFile(const char* filename);
	private:
		// ��Դλ��
		std::string _resPath;
	};
}