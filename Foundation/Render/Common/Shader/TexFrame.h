#pragma once

#include "system.h"
#include "Texture.h"

namespace render
{
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
		void setRect(const sys::Rect& rect);
		// ��ȡ������ʾ����
		const sys::Rect& getRect() const;
		// �����������ʾ����
		void setTextureWithRect(Texture* texture, const sys::Rect& rect);
		// �����������ʾ����,Ĭ����ʾ����Ϊȫ��
		void setTextureWithRect(Texture* texture);
	private:
		// �������
		Texture* _texture;
		// ��ʾ����
		sys::Rect _rect;
	};
}