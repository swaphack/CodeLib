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
		float getPositionX() const;

		float getPositionY() const;

		float getPositionZ() const;

		const math::Vector3& getPosition() const;
		// �������ű�
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const math::Vector2& scale);

		void setScale(const math::Vector3& scale);

		void setScale(float scale);
		// ��ȡ���ű�
		float getScaleX() const;

		float getScaleY() const;

		float getScaleZ() const;

		const math::Vector3& getScale() const;
		// ������תϵ��
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const math::Vector3& rotation);
		// ��ȡ��תϵ��
		float getRotationX() const;

		float getRotationY() const;

		float getRotationZ() const;

		const math::Vector3& getRotation() const;

		
	public:
		virtual void onSpaceChange() {}
	protected:
		// λ������
		math::Vector3 _position;
		// ���ű�
		math::Vector3 _scale;
		// ��ת
		math::Vector3 _rotation;
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
		// ��ȡê��
		float getAnchorPointX();
		// ����ê��
		void setAnchorPointX(float value);
		// ��ȡê��
		float getAnchorPointY();
		// ����ê��
		void setAnchorPointY(float value);
		// ��ȡê��
		float getAnchorPointZ();
		// ����ê��
		void setAnchorPointZ(float value);
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

	// ��������
	class DirectionProtocol
	{
	public:
		enum class ZDirectionType
		{
			// ������Ļ��
			INSIDE,
			// ������Ļ��
			OUTSIDE,
		};
	public:
		DirectionProtocol();
		virtual ~DirectionProtocol();
	public:
		const math::Vector3& getUp() const;

		const math::Vector3& getRight() const;

		const math::Vector3& getFront() const;
	
		void setZDirection(ZDirectionType type);

		ZDirectionType getZDirection() const;

		const math::Vector3& getDefaultUp() const;

		const math::Vector3& getDefaultRight() const;

		const math::Vector3& getDefaultFront() const;
	protected:
		void setUp(const math::Vector3& up);
		void setRight(const math::Vector3& right);
		void setFront(const math::Vector3& front);
	protected:
		// ͷ����
		math::Vector3 _up;
		// �ұ߷���
		math::Vector3 _right;
		// ǰ��
		math::Vector3 _front;

		ZDirectionType _zDirection = ZDirectionType::OUTSIDE;

		// Ĭ��ͷ����
		math::Vector3 _defaultUp;
		// Ĭ���ұ߷���
		math::Vector3 _defaultRight;
		// Ĭ��ǰ��
		math::Vector3 _defaultFront;
	};
	
}