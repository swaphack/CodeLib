#pragma once

namespace render
{
	class PostProcessingNode;

	/**
	*	后期处理
	*/
	class PostProcessing
	{
	public:
		static PostProcessing* getInstance();
	public:
		void use();
		void draw();
	public:
		void setPostProcessingNode(PostProcessingNode* node);
	protected:
	private:
		PostProcessingNode* _node = nullptr;
	};
}