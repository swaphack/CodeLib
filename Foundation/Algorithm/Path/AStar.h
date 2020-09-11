#pragma once

#include <cstdint>
#include <vector>
#include <stack>
#include "Path.h"

namespace alg
{
	class Map;
	/**
	*	A* [1]  ��A-Star)�㷨��һ�־�̬·����������·������Ч��ֱ������������Ҳ�������������ĳ�������ʽ�㷨��ע�⡪��������Ч��ֱ�������㷨��֮��ӿ���˺ܶ�Ԥ�����㷨����ALT��CH��HL�ȵȣ������߲�ѯЧ����A*�㷨����ǧ�������򱶡�
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
	*/
	class AStar : public Path
	{
	public:
		AStar();
		virtual ~AStar();
	public:
		/**
		*	Ѱ·
		*/
		bool findWay(const Map* map, uint32_t srcIndex, uint32_t destIndex);
	protected:
		/**
		*	��ʼ���ڵ�
		*/
		void initNodes(const Map* map);
		/**
		*	��������ڵ�
		*/
		bool findNeareastNode(const Map* map, uint32_t srcIndex, uint32_t destIndex);
	protected:
		/**
		*	���ҵ�ǰ����
		*/
		void pushCurrent(const Map* map, uint32_t srcIndex, uint32_t destIndex);
		/**
		*	�ع�����һ��
		*/
		void popCurrent(uint32_t srcIndex);
	private:
		// �����Ľڵ�
		std::set<uint32_t> _waitCheckNode;
		// �����Ľڵ�
		std::set<uint32_t> _checkedNode;
		// ·�ߵ�
		std::stack<uint32_t> _pathNode;
		// ����
		std::stack<float> _pathDistance;
	};

}