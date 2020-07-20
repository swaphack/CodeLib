#include "PostProcessing.h"

#include "FramePostProcessingNode.h"

render::PostProcessing::PostProcessing()
{

}

render::PostProcessing::~PostProcessing()
{
}

void render::PostProcessing::addFramePostProcessing(FramePostProcessingNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	_framePostProcessingNodes.insert(node);
}

void render::PostProcessing::removeFramePostProcessing(FramePostProcessingNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	_framePostProcessingNodes.erase(node);
}

void render::PostProcessing::begin()
{
	for (auto item : _framePostProcessingNodes)
	{
		item->beginRecord();
	}
}

void render::PostProcessing::end()
{
	for (auto item : _framePostProcessingNodes)
	{
		item->endRecord();
	}
}

