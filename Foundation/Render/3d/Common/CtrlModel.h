#pragma once

#include "../macros.h"

namespace render
{
	// ģ��
	class CtrlModel : public ColorNode
	{
	public:
		CtrlModel();
		virtual ~CtrlModel();
	public:
		virtual void draw();
		// ����ģ�Ͳ��� 
		void setMatrial(const Material* material);
		// ��ȡģ�Ͳ���
		const Material* getMatrial() const;
		// ��ȡģ�Ͳ���
		Material* getMatrial();
		
		// ���������������֡
		virtual void setTexFrame(const TexFrame* frame);

		// ���ö���,���ߣ�����������Ϣ
		void setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords);
		// ��������������
		void setIndices(int count, int* indices);
		// ������
		int getVertexCount();
		// ��������
		int getTriangleCount();
	protected:
		virtual void initSelf();
	protected:
		// ģ�Ͳ���
		Material* _material;
		// ����
		TexFrame* _texFrame;

		// ������
		int _vertexCount;
		// �������� (x,y,z)
		float* _vertexes;
		// ���� (x,y,z)
		float* _normals;
		// ��ɫ (r,g,b)
		float* _colors;
		// �������� (x,y,z)
		float* _texCoords;
		
		// ��������
		int _triangleCount;
		// ��������
		int* _indices;
	};
}