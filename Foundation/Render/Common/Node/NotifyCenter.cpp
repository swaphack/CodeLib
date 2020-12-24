#include "NotifyCenter.h"
#include "Node.h"

render::NotifyCenter::NotifyCenter()
{
}

render::NotifyCenter::~NotifyCenter()
{
}

render::NodeNotify* render::NotifyCenter::alloct(Node* node)
{
	if (node == nullptr) return nullptr;

	auto it = _mapNotifies.find(node);
	if (it != _mapNotifies.end())
	{
		PRINT("Error. NodeNotify had allocted with node");
		return it->second;
	}

	NodeNotify* notify = new NodeNotify();

	_mapNotifies.insert(std::make_pair(node, notify));

	return notify;
}

void render::NotifyCenter::release(Node* node)
{
	if (node == nullptr) return;

	auto it = _mapNotifies.find(node);
	if (it == _mapNotifies.end())
	{
		PRINT("Error. NodeNotify was not allocted with node");
		return;
	}

	SAFE_DELETE(it->second);
	_mapNotifies.erase(it);
}

void render::NotifyCenter::dispatch(NodeNotifyType type)
{
	for (const auto& item : _mapNotifies)
	{
		item.first->notify(type);
	}
}
