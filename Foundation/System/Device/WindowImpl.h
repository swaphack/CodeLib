#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	class WindowImpl
	{
	public:
		WindowImpl();
		virtual ~WindowImpl();
	public:
		void initWindow(const std::string& title, float width, float height, float posX, float posY);
	public:
		// ����λ��x
		void setPositionX(float posX);
		// ����λ��x
		float getPositionX();
		// ����λ��y
		void setPositionY(float posY);
		// ����λ��y
		float getPositionY();
		// ���ڸ߶�
		void setWidth(float width);
		// ���ڿ��
		float getWidth();
		// ���ڸ߶�
		void setHeight(float height);
		// ���ڸ߶�
		float getHeight();
		// ����
		void setTile(const std::string& name);
		// ����
		std::string getTitle();
	protected:
		// ���ڿ��
		float _width = 0;
		// ���ڸ߶�
		float _height = 0;
		// ����x��λ��
		float _posX = 0;
		// ����y��λ��
		float _posY = 0;
		// ���ڱ���
		std::string _title;
	};
}