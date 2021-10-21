#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class Texture;
	// ֡������ʾ��������½ǿ�ʼ
	class TexFrame : public sys::Object
	{
	public:
		TexFrame();
		virtual ~TexFrame();
	public:
		// ��������
		void setTexture(const Texture* texture);
		// ��ȡ�������
		const Texture* getTexture() const;
		// ��������
		void setName(const std::string& name);
		// ��ȡ����
		const std::string& getName() const;
		// ����������ʾ����
		void setRect(const math::Rect& rect);
		// ��ȡ������ʾ����
		const math::Rect& getRect() const;
		// �Ƿ���ת
		void setRotate(bool bRotated);
		// �Ƿ���ת
		bool isRotated() const;
	public:
		// �Ƿ������С
		math::Size getFrameSize() const;
		// ��ȡ����λ��
		math::Vector2 getFramePosition() const;
	public:
		// �����������ʾ����
		void loadTexture(const Texture* texture, const math::Rect& rect);
		// �����������ʾ����,Ĭ����ʾ����Ϊȫ��
		void loadTexture(const Texture* texture);
	public:
		TexFrame& operator=(const TexFrame& value);
	private:
		// �������
		Texture* _texture = nullptr;
		// ����
		std::string _name;
		// ��ʾ����
		math::Rect _rect;
		// �Ƿ���ת
		bool _rotate = false;
	};
}