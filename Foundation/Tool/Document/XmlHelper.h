#pragma once

#include "tinyxml2.h"
#include <string>
#include <map>
#include <vector>
#include <functional>

namespace tool
{
	// xml ��������
	class XmlHelper
	{
	public:
		XmlHelper();
		~XmlHelper();
	public:
		/**
		*	����xml�ļ�
		*/
		bool loadFile(const std::string& filepath);
		/**
		*	��ȡ�ڵ�
		*	���� "a.b.c"
		*	<a><b><c></c></b></a>
		*/
		tinyxml2::XMLElement* getElement(const std::string& nodePath, const std::string& spot =".");
		/**
		*	��ȡ�ڵ������ֵ
		*/
		std::string getAttribute(const std::string& nodepath, const std::string& name);
		/**
		*	�Ӹ��ڵ㿪ʼ����
		*/
		void foreach(const std::function<void(tinyxml2::XMLElement*)>& func);
	public:
		/**
		*	����xml�ļ�
		*/
		void saveTo(const std::string& filepath);
		/**
		*	׷��Ԫ��
		*/
		void appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	����xml�ļ�
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	����xml�ļ�
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::vector<std::pair<std::string, std::string>>& value);
	private:
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}