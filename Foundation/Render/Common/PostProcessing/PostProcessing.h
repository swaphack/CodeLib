#pragma once

namespace render
{
	class PostProcessingNode;
	class View;

	/**
	*	���ڴ���
	*/
	class PostProcessing
	{
	public:
		static PostProcessing* getInstance();
	public:
		bool hasNode();
		/**
		*	�Ƿ���
		*/
		bool isEnable();
		/**
		*	��¼
		*/
		void record();
		/**
		*	�Ƿ���
		*/
		void draw();
	public:
		void setPostProcessingNode(PostProcessingNode* node);
	protected:
	private:
		PostProcessingNode* _node = nullptr;
	};
}