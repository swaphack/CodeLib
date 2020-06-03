#include "PostProcessing.h"
#include "PostProcessingNode.h"

render::PostProcessing* render::PostProcessing::getInstance()
{
	static PostProcessing* sInstance = nullptr;
	if (sInstance  == nullptr)
	{
		sInstance = new PostProcessing;
	}

	return sInstance;
}

void render::PostProcessing::use()
{
	if (_node == nullptr)
	{
		return;
	}

	_node->bindFrameBuffer();
}

void render::PostProcessing::draw()
{
	if (_node == nullptr)
	{
		return;
	}

	_node->updateNode();
	_node->drawNode();
}

void render::PostProcessing::setPostProcessingNode(PostProcessingNode* node)
{
	SAFE_RELEASE(_node);
	SAFE_RETAIN(node);

	_node = node;
}

