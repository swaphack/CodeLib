#pragma once

#include "mathlib.h"

namespace render
{
	

	// �ռ�����
	class SpaceProtocol
	{
	public:
		SpaceProtocol();
		virtual ~SpaceProtocol();
	public:
		// ��������
		void setPositionX(float x);

		void setPositionY(float y);

		void setPositionZ(float z);

		void setPosition(float x, float y);

		void setPosition(float x, float y, float z);

		void setPosition(const math::Vector3& position);

		void setPosition(const math::Vector2& position);
		// ��ȡ����
		float getPositionX();

		float getPositionY();

		float getPositionZ();

		const math::Vector3& getPosition();
		// �������ű�
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const math::Vector3& scale);

		void setScale(float scale);
		// ��ȡ���ű�
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const math::Vector3& getScale();
		// ������תϵ��
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const math::Vector3& rotation);
		// ��ȡ��תϵ��
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const math::Vector3& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// λ������
		math::Vector3 _position;
		// ���ű�
		math::Vector3 _scale;
		// ��ת
		math::Vector3 _rotation;
	private:
	};


	// ��������
	class BodyProtocol
	{
	public:
		BodyProtocol();
		virtual ~BodyProtocol();
	public:
		// ����ê��
		void setAnchorPoint(float x, float y, float z);
		// ����ê��
		void setAnchorPoint(float x, float y);
		// ����ê��
		void setAnchorPoint(const math::Vector3& anchor);
		// ����ê��
		void setAnchorPoint(const math::Vector2& anchor);
		// ��ȡê��
		const math::Vector3& getAnchorPoint();
		// ��ȡ���
		float getAnchorPointX();
		// ��ȡ�߶�
		float getAnchorPointY();
		// ��ȡ���
		float getAnchorPointZ();
		// ���ÿ��
		void setWidth(float w);
		// ���ø߶�
		void setHeight(float h);
		// �������
		void setDepth(float d);
		// �������
		void setVolume(float w, float h, float d);
		// �������
		void setVolume(float w, float h);
		// �������
		void setVolume(const math::Volume& volume);
		// ���������Ĭ�����
		void setVolume(const math::Size& size);
		// ��ȡ���
		float getWidth();
		// ��ȡ�߶�
		float getHeight();
		// ��ȡ���
		float getDepth();
		// ��ȡ���
		const math::Volume& getVolume();
		// ��ȡ���
		math::Size getSize();
	public:
		virtual void onBodyChange() {}
	protected:
		// ê��
		math::Vector3 _anchor;
		// ���
		math::Volume _volume;
	private:
	};
}