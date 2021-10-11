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
		// ����������ʾ����
		void setRect(const math::Rect& rect);
		// ��ȡ������ʾ����
		const math::Rect& getRect() const;
		// �����������ʾ����
		void setTextureWithRect(const Texture* texture, const math::Rect& rect);
		// �����������ʾ����,Ĭ����ʾ����Ϊȫ��
		void setTextureWithRect(const Texture* texture);
	public:
		TexFrame& operator=(const TexFrame& value);
	private:
		// �������
		Texture* _texture;
		// ��ʾ����
		math::Rect _rect;
	};
}