#pragma once

#include "Common/Node/Node.h"

namespace render
{
	/**
	*	ģ�� 
	*	(1)��ģ����ԵĹ����У�������ʹ��һ���Ƚ������루comparison mask����ģ�建�����е�ֵ����λ�����㣬
	*	����ο�ֵ���бȽϣ��Ӷ�ʵ�ֶ�ģ�建�����е�ֵ��ĳһλ�ϵ���λ״̬���жϡ�
	*	������ģ�建�����е�ֵ����������Ϊһ������������ʹ�ã���������Ϊһ�����ؼ���ʹ�á�
	*	��OpenGL�У�����ͨ������glStencilFunc()�������趨
	*		�Ƚ�������comparison function����
	*		�ο�ֵ��reference value���Լ���
	*		�������루comparison mask����
	*	(2)���˱Ƚϲο�ֵ��ģ��ֵ֮�⣬���ǻ���Ҫʹ��һЩ����������ģ�建�����е�ֵ����Щ��������Ϊģ�������stencil operation����ģ�建�����ĸ�����ģ����ԵĽ���Լ���Ȳ��ԵĽ���������е���ϵ�������������ͼ��ʾ��ģ���������Ϊ��������������ֱ�ָ����Ӧ�ĸ��·�����
	*
	*	1. ģ�����ʧ�ܡ�
	*	
	*	2. ģ�����ͨ��������Ȳ���ʧ�ܡ�
	*	
	*	3. ģ�����ͨ��������Ȳ���ͨ����
	*	
	*	����������е�һ������ʱ���ͻ�ִ��Ԥ���趨�ĸ��²�������OpenGL�У�����ʹ��glStencilOp()������Ϊ������������ֱ����ø��·��������磬
	*	
	*	glStencilOp(GL_KEEP, // ��һ��������·���
	*	
	*	GL_DECR, // �ڶ�������ĸ��·���
	*	
	*	GL_INCR); // ����������ĸ��·���
	*/
	class Stencil : public Node
	{
	public:
		Stencil();
		virtual ~Stencil();
	public:
		virtual void draw();

		virtual void visit();
		// ����ģ��ڵ�
		void setStencilNode(Node* node);
		// ��ȡģ��ڵ�
		Node* getStencilNode();
	protected:
		// ���ü�����
		int _ref;
		// ģ��ڵ�
		Node* _stencilNode;
	};
}