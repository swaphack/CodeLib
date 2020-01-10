#pragma once

namespace alg
{
	struct Node;
	/**
	*	地图
	*/
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	添加点
		*/
		void addNode(Node* node);
		/**
		*	移除点
		*/
		void removeNode(Node* node);
		/**
		*	清空点
		*/
		void clearNodes();
	private:
		std::map<>
	};
}