#pragma once

#include "Common/Node/Node.h"

namespace render
{
	/**
	*	模板 
	*	(1)在模板测试的过程中，可以先使用一个比较用掩码（comparison mask）与模板缓冲区中的值进行位与运算，
	*	再与参考值进行比较，从而实现对模板缓冲区中的值的某一位上的置位状态的判断。
	*	这样，模板缓冲区中的值不仅可以作为一个独立的整体使用，还可以作为一个比特集合使用。
	*	在OpenGL中，可以通过调用glStencilFunc()函数来设定
	*		比较条件（comparison function）、
	*		参考值（reference value）以及比
	*		较用掩码（comparison mask）。
	*	(2)除了比较参考值与模板值之外，我们还需要使用一些操作来更新模板缓冲区中的值，这些操作被称为模板操作（stencil operation）。模板缓冲区的更新与模板测试的结果以及深度测试的结果有着密切的联系。如上面的流程图所示：模板操作可以为下述三种情况，分别指定相应的更新方法。
	*
	*	1. 模板测试失败。
	*	
	*	2. 模板测试通过，但深度测试失败。
	*	
	*	3. 模板测试通过，且深度测试通过。
	*	
	*	当上述情况中的一个发生时，就会执行预先设定的更新操作。在OpenGL中，可以使用glStencilOp()函数来为上述三种情况分别设置更新方法。例如，
	*	
	*	glStencilOp(GL_KEEP, // 第一种情况更新方法
	*	
	*	GL_DECR, // 第二种情况的更新方法
	*	
	*	GL_INCR); // 第三种情况的更新方法
	*/
	class Stencil : public Node
	{
	public:
		Stencil();
		virtual ~Stencil();
	public:
		virtual void draw();

		virtual void visit();
		// 设置模板节点
		void setStencilNode(Node* node);
		// 获取模板节点
		Node* getStencilNode();
	protected:
		// 引用计数器
		int _ref;
		// 模板节点
		Node* _stencilNode;
	};
}