#pragma once

#include "../macros.h"

namespace render
{
	// ģ��
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		virtual void draw();
		// ����ģ�Ͳ��� 
		void setMatrial(const Material* material);
		// ��ȡģ�Ͳ���
		const Material* getMatrial() const;
		// ��ȡģ�Ͳ���
		Material* getMatrial();
		// ��ȡģ���������
		const Mesh* getMesh() const;
		// ��ȡģ���������
		Mesh* getMesh();
		
		// ���������������֡
		void setTexFrame(const TexFrame* frame);
	protected:
		// ģ�Ͳ���
		Material* _material;
		// ����
		TexFrame* _texFrame;
		// ��������
		Mesh* _mesh;
	};
}