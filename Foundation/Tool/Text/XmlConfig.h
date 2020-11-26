#pragma once

#include "tinyxml2.h"
#include <string>

namespace tool
{
	// xml ��������
	class XmlHelper
	{
	public:
		XmlHelper();
		~XmlHelper();
	public:
		/// <summary>
		/// ����xml�ļ�
		/// </summary>
		/// <param name="filepath"></param>
		/// <returns></returns>
		bool loadFile(const std::string& filepath);
		/// <summary>
		/// ��ȡ�ڵ�
		/// ���� "a.b.c"
		/// </summary>
		/// <param name="nodePath"></param>
		/// <returns></returns>
		tinyxml2::XMLElement* getElement(const std::string& nodePath);
		/// <summary>
		/// ��ȡ�ڵ������ֵ
		/// </summary>
		/// <param name="nodepath"></param>
		/// <param name="name"></param>
		/// <returns></returns>
		std::string getAttribute(const std::string& nodepath, const std::string& name);
	private:
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}