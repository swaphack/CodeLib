#pragma once

#include "system.h"

#include <set>

namespace render
{
	class FramePostProcessingNode;

	class PostProcessing 
	{
	public:
		PostProcessing();
		virtual ~PostProcessing();
	public:
		void AddFramePostProcessing(FramePostProcessingNode* node);
		void removeFramePostProcessing(FramePostProcessingNode* node);
	protected:
	private:
		std::set<FramePostProcessingNode> _framePostProcessingNodes;
	};

#define G_POSTPROCESSING sys::Instance<PostProcessing>::getInstance()
}