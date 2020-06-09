#pragma once

namespace render
{
	class PostProcessingNode;
	class View;

	/**
	*	后期处理
	*/
	class PostProcessing
	{
	public:
		static PostProcessing* getInstance();
	public:
		bool hasNode();
		/**
		*	是否开启
		*/
		bool isEnable();
		/**
		*	记录
		*/
		void record();
		/**
		*	是否开启
		*/
		void draw();
	public:
		void setPostProcessingNode(PostProcessingNode* node);
	protected:
	private:
		PostProcessingNode* _node = nullptr;
	};
}