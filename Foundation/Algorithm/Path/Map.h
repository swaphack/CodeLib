#pragma once

namespace alg
{
	struct Node;
	/**
	*	��ͼ
	*/
	class Map
	{
	public:
		Map();
		virtual ~Map();
	public:
		/**
		*	��ӵ�
		*/
		void addNode(Node* node);
		/**
		*	�Ƴ���
		*/
		void removeNode(Node* node);
		/**
		*	��յ�
		*/
		void clearNodes();
	private:
		std::map<>
	};
}