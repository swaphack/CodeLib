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

void render::NotifyCenter::addDirtyNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (_bHandDirtyEvent)
	{
		_waitDirtyNodes.insert(node);
		return;
	}
	if (_allDirtyNodes.size() == 0)
	{// 空
		_allDirtyNodes.insert(node);
		return;
	}

	auto it = _allDirtyNodes.find(node);
	if (it != _allDirtyNodes.end())
	{// 已有
		return;
	}

	bool bDescendants = false;
	
	// 子节点
	for (auto item : _allDirtyNodes)
	{
		if (node->isDescendantsOf(item))
		{
			bDescendants = true;
			break;
		}
	}
	if (bDescendants)
	{// 子节点
		return;
	}

	//_allDirtyNodes = tempNodes;

	// 父节点
	bool bParent = false;
	std::set<Node*> tempNodes;
	for (auto item : _allDirtyNodes)
	{
		if (item->isDescendantsOf(node))
		{
			tempNodes.insert(node);
			bParent = true;
		}
		else
		{
			tempNodes.insert(item);
		}
	}

	if (!bParent)
	{
		tempNodes.insert(node);
	}

	_allDirtyNodes = tempNodes;
}

void render::NotifyCenter::updateAllDirtyNodes()
{
	if (_allDirtyNodes.size() == 0)
	{
		return;
	}
	_bHandDirtyEvent = false;
	for (auto item : _waitDirtyNodes)
	{
		this->addDirtyNode(item);
	}
	_waitDirtyNodes.clear();
	_bHandDirtyEvent = true;
	for (auto& item : _allDirtyNodes)
	{
		SAFE_RETAIN(item);
		item->updateNode();
		SAFE_RELEASE(item);
	}
	_allDirtyNodes.clear();
	_bHandDirtyEvent = false;
}
