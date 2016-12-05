#include "LayoutManager.h"

#include "Layout.h"

using namespace render;


LayoutManager::LayoutManager()
{

}

LayoutManager::~LayoutManager()
{
	this->removeAllLayouts();
}

LayoutManager* LayoutManager::getInstance()
{
	static LayoutManager* s_LayoutManager = nullptr;

	if (s_LayoutManager == nullptr)
	{
		s_LayoutManager = new LayoutManager();
	}

	return s_LayoutManager;
}

void LayoutManager::addLayout(Layout* layout)
{
	if (layout == nullptr)
	{
		return;
	}

	layout->retain();

	_layoutStack[layout->getName()] = layout;
}

void LayoutManager::removeLayout(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	std::map<std::string, Layout*>::iterator iter = _layoutStack.find(name);
	if (iter == _layoutStack.end())
	{
		return;
	}

	iter->second->release();

	_layoutStack.erase(iter);
}

Layout* LayoutManager::getLayout(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, Layout*>::iterator iter = _layoutStack.find(name);
	if (iter != _layoutStack.end())
	{
		return iter->second;
	}

	return nullptr;
}

void LayoutManager::removeAllLayouts()
{
	std::map<std::string, Layout*>::iterator iter = _layoutStack.begin();
	while (iter != _layoutStack.end())
	{
		iter->second->release();
		iter++;
	}

	_layoutStack.clear();
}
