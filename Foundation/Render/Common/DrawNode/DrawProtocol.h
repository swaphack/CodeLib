#pragma once

#include <cstdint>

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Camera;

	// ������ɫ����
	class ColorProtocol
	{
	public:
		ColorProtocol();
		virtual ~ColorProtocol();
	public:
		// ������ɫ
		void setColor(uint8_t r, uint8_t g, uint8_t b);
		// ������ɫ
		void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		// ������ɫ
		void setColor(float r, float g, float b);
		// ������ɫ
		void setColor(float r, float g, float b, float a);
		// ������ɫ
		void setColor(const phy::Color4B& color);
		// ������ɫ
		void setColor(const phy::Color3B& color);
		// ������ɫ
		void setColor(const phy::Color4F& color);
		// ������ɫ
		void setColor(const phy::Color3F& color);
		// ��ȡ��ɫ
		const phy::Color4B& getColor() const;
	protected:
		virtual void onColorChange() {};
	protected:
		// ���
		phy::Color4B _color;
	};

	// ��͸��������
	class OpacityProtocol
	{
	public:
		OpacityProtocol();
		virtual ~OpacityProtocol();
	public:
		// ���ò�͸����
		void setOpacity(uint8_t opacity);
		// ���ò�͸����
		uint8_t getOpacity();
	protected:
		// ��͸����
		uint8_t _opacity = 255;
	};

	// ��ϲ���
	struct BlendParam
	{
		BlendingFactorSrc src = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;

		BlendParam();

		BlendParam(BlendingFactorSrc src, BlendingFactorDest dest);

		BlendParam& operator=(const BlendParam& blend);
	};

	// ���
	class BlendProtocol
	{
	public:
		BlendProtocol();
		virtual ~BlendProtocol();
	public:
		// ���û������
		void setBlend(BlendingFactorSrc src, BlendingFactorDest dest);
		// ���û������
		void setBlend(const BlendParam& blend);
		// ������ɫ
		void setBlendColor(const phy::Color3B& color);
		// ������ɫ
		void setBlendColor(const phy::Color3F& color);
		// ������ɫ
		void setBlendColor(const phy::Color4B& color);
		// ������ɫ
		void setBlendColor(const phy::Color4F& color);
		// ��ȡ��ϲ���
		const BlendParam& getBlend();
	protected:
		virtual void onBlendChange() {};
	protected:
		// ��ϲ���
		BlendParam _blendParam;
		// �����ɫ
		phy::Color4F _blendColor;
	};
}
