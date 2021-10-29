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
		*	xml�ĵ�
		*/
		tinyxml2::XMLDocument* getDocument();
		/**
		*	���ڵ�
		*/
		tinyxml2::XMLElement* getRoot();
	public:
		/**
		*	����xml�ļ�
		*/
		bool loadFile(const std::string& filepath);
		/**
		*	����xml�ļ�
		*/
		void saveTo(const std::string& filepath);
	public:
		/**
		*	��ȡ���ڵ������
		*/
		void getRootAttributes(std::map<std::string, std::string>& value);
		/**
		*	���ø��ڵ������
		*/
		void setRootAttributes(const std::map<std::string, std::string>& value);
	public:
		/**
		*	������Ϊ����׷�ӵ��ڵ�
		*/
		void appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	������Ϊ�ӽڵ�׷�ӵ��ڵ�
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	������Ϊ�ӽڵ�׷�ӵ��ڵ㣨����
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::vector<std::pair<std::string, std::string>>& value);
	public:
		/**
		*	��ȡ�ڵ�
		*	���� "a.b.c"
		*	<a><b><c></c></b></a>
		*/
		tinyxml2::XMLElement* getElement(const std::string& nodePath, const std::string& spot = ".");
		/**
		*	��ȡ�ڵ������ֵ
		*/
		std::string getAttribute(const std::string& nodepath, const std::string& name);
		/**
		*	�Ӹ��ڵ���ӽڵ㿪ʼ����
		*/
		void foreach(const std::function<void(tinyxml2::XMLElement*)>& func);
	private:
		// xml�ĵ�
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}