#pragma once

#include <cstdint>
#include <vector>
#include <stack>
#include <map>
#include "Path.h"

namespace alg
{
	class MapProtocol;
	/**
	*	A* [1]  ��A-Star)�㷨��һ�־�̬·����������·������Ч��ֱ������������Ҳ�������������ĳ�������ʽ�㷨��
	*	ע�⡪��������Ч��ֱ�������㷨��֮��ӿ���˺ܶ�Ԥ�����㷨����ALT��CH��HL�ȵȣ������߲�ѯЧ����A*�㷨����ǧ�������򱶡�
	*	��ʽ��ʾΪ�� f(n)=g(n)+h(n),
	*	���У� f(n) �Ǵӳ�ʼ״̬����״̬n��Ŀ��״̬�Ĵ��۹��ƣ�
	*	g(n) ����״̬�ռ��дӳ�ʼ״̬��״̬n��ʵ�ʴ��ۣ�
	*	h(n) �Ǵ�״̬n��Ŀ��״̬�����·���Ĺ��ƴ��ۡ�
	*	������·���������⣬״̬����ͼ�еĽڵ㣬���۾��Ǿ��룩
	*	h(n)��ѡȡ
	*	��֤�ҵ����·�������Ž�ģ��������ؼ����ڹ��ۺ���f(n)��ѡȡ������˵h(n)��ѡȡ����
	*	������d(n)���״̬n��Ŀ��״̬�ľ��룬��ôh(n)��ѡȡ�������������������
	*	���h(n)< d(n)��Ŀ��״̬��ʵ�ʾ��룬��������£������ĵ����࣬������Χ��Ч�ʵ͡����ܵõ����Ž⡣
	*	���h(n)=d(n)�����������h(n)������̾��룬��ô�������ϸ��������·�����У� ��ʱ������Ч������ߵġ�
	*	��� h(n)>d(n)�������ĵ����٣�������ΧС��Ч�ʸߣ������ܱ�֤�õ����Ž�
	* 
	* 
// A* Search Algorithm
1.  Initialize the open list
2.  Initialize the closed list
	put the starting node on the open list (you can leave its f at zero)

3.  while the open list is not empty
	a) find the node with the least f on the open list, call it "q"

	b) pop q off the open list

	c) generate q's 8 successors and set their
	   parents to q

	d) for each successor
		i) if successor is the goal, stop search

		  successor.g = q.g + distance between successor and q
		  successor.h = distance from goal to successor (This can be done using many ways, we will discuss three heuristics-Manhattan, Diagonal and Euclidean Heuristics)
		  successor.f = successor.g + successor.h

		ii) if a node with the same position as	successor is in the OPEN list which has a
		   lower f than successor, skip this successor

		iii) if a node with the same position as successor  is in the CLOSED list which has
			a lower f than successor, skip this successor 
			
			otherwise, add the node to the open list
	 end (for loop)

	e) push q on the closed list
	end (while loop)
	*/
	class AStar : public Path
	{
		struct AStartNode 
		{
		private:
			// ��ǰ����
			uint32_t _index = 0;
			// ���ڵ�����
			int32_t _parent = -1;
			// ���뿪ʼ��ֵ
			float _g = 0;
			// ��Ŀ���ֵ
			float _h = 0;
		public:
			AStartNode();
			AStartNode(uint32_t index);
		public:
			// ��ǰ����
			uint32_t getIndex() const;
			// ���ڵ�����
			void setParent(int32_t parent);
			int32_t getParent() const;
			// ���뿪ʼ��ֵ
			void setG(float value);
			float getG() const;
			// ��Ŀ���ֵ
			void setH(float value);
			float getH() const;

			float getF() const;
		};
	public:
		AStar();
		virtual ~AStar();
	public:
		/**
		*	Ѱ·
		*/
		bool findWay(const MapProtocol* map, uint32_t srcIndex, uint32_t destIndex, std::vector<uint32_t>& path);
	protected:
		/**
		*	��ʼ���ڵ�
		*/
		void initNodes();
		/**
		*	��ȡ�ڵ�
		*/
		AStartNode* getAStartNode(uint32_t index);
		/**
		*	��ȡ·��
		*/
		bool getPath(uint32_t srcIndex, uint32_t endIndex, std::vector<uint32_t>& path);
	private:
		// �����Ľڵ�
		std::set<uint32_t> _openSet;
		// �����Ľڵ�
		std::set<uint32_t> _closeSet;
		// �ڵ���Ϣ
		std::map<uint32_t, AStartNode> _mapNode;
	};

}