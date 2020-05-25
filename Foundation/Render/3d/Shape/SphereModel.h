#pragma once

#include "Common/import.h"

#include "3d/Common/Model.h"

namespace render
{
	// 3dģ�ͻ�������
	/*
	        z (��)
			|   P
			|  /
			| /
		  O |/_______ y
		   / \ 
		  /   \
		 x (��)M
	
	��xOM  ��
	��zOP  ��

	����P��x��y��z��Ϊ�ռ���һ�㣬���PҲ�������������д������(r���ȣ���)��ȷ����
	����rΪԭ��O���P��ľ��룻��Ϊ�����߶�OP��z������ļнǣ���Ϊ����z��������x�ᰴ��ʱ�뷽��ת��OM��ת���Ľǣ�����MΪ��P��xOy���ϵ�ͶӰ����
	������������r���ȣ��ս�����P���������꣬��Ȼ������r���ȣ��յı仯��ΧΪr��[0,+��)���ȡ�[0, ��]�� �ա�[0,2��]
	��r,�Ȼ�շֱ�Ϊ����ʱ,���Ա�ʾ������������:
		r = ����������ԭ��Ϊ�ĵ����棻
		��= ����������ԭ��Ϊ���㡢z��Ϊ���Բ׶�棻
		��= ����������z��İ�ƽ�档

	������ϵ(r,��,��)��ֱ������ϵ(x,y,z)��ת����ϵ:
	x=rsin��cos��
	y=rsin��sin��
	z=rcos��

	ֱ������ϵ(x,y,z)��������ϵ(r,��,��)��ת����ϵΪ:
	r = sqrt(x^2 + y^2 + z^2);
	�� = arccos(z/r)
	�� = arctan(y/x)

	*/
	class SphereModel : public Model // ��������
	{
	public:
		SphereModel();
		virtual ~SphereModel();
	public:
		virtual bool init();
	public:
		// ������뾶
		void setRadius(float radius);
		// ��ȡ��뾶
		float getRadius();
	protected:
		math::Vector3 getPoint(const math::Vector2& uv);
		math::Vector3 getPoint(float u, float v);

		void updateSphere();
	protected:
		virtual void onDraw();
		virtual void initBufferObject();
		virtual void updateBufferData();
	private:
		// ��뾶
		float _radius = 1;
	};
}