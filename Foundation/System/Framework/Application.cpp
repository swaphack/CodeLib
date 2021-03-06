#include "Application.h"
#include "AutoReleasePool.h"

using namespace sys;

Application::Application()
{
}

Application::~Application()
{
	this->clearProtocolManagers();
}

void Application::addProtocolManager( const std::string& protocolName, Object* protocolManager )
{
	if (protocolName.empty() || protocolManager == nullptr)
	{
		return;
	}

	this->removeProtocolManager(protocolName);

	_protocolManagers[protocolName] = protocolManager;
}

void Application::removeProtocolManager( const std::string& protocolName )
{
	if (protocolName.empty())
	{
		return;
	}

	std::map<std::string, Object*>::iterator iter = _protocolManagers.find(protocolName);

	if (iter == _protocolManagers.end())
	{
		return;
	}

	delete iter->second;

	_protocolManagers.erase(iter);
}

Object* Application::getProtocolManager( const std::string& protocolName )
{
	if (protocolName.empty())
	{
		return nullptr;
	}


	std::map<std::string, Object*>::iterator iter = _protocolManagers.find(protocolName);

	if (iter == _protocolManagers.end())
	{
		return nullptr;
	}

	return iter->second;
}

void Application::clearProtocolManagers()
{
	std::map<std::string, Object*>::iterator iter = _protocolManagers.begin();

	while (iter != _protocolManagers.end())
	{
		delete iter->second;
		iter++;

	}
	_protocolManagers.clear();
}

void Application::checkAutoRealsePool()
{
	G_AUTORELEASEPOOL->checkAutoRelease();
}