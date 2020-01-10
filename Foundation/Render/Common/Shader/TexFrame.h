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
		void setRect(const math::Rect& rect);
		// ��ȡ������ʾ����
		const math::Rect& getRect() const;
		// �����������ʾ����
		void setTextureWithRect(const Texture* texture, const math::Rect& rect);
		// �����������ʾ����,Ĭ����ʾ����Ϊȫ��
		void setTextureWithRect(const Texture* texture);

		TexFrame& operator=(const TexFrame& value);
	private:
		// �������
		Texture* _texture;
		// ��ʾ����
		math::Rect _rect;
	};
}