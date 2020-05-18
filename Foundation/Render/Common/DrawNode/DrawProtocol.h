#pragma once

#include <cstdint>

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
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
		void setColor(const sys::Color4B& color);
		// ������ɫ
		void setColor(const sys::Color3B& color);
		// ��ȡ��ɫ
		const sys::Color4B& getColor();
	protected:
		virtual void onColorChange() {};
	protected:
		// ���
		sys::Color4B _color;
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
		BlendingFactorSrc src = BlendingFactorSrc::ONE;
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
		// ��ȡ��ϲ���
		const BlendParam& getBlend();
	protected:
		virtual void onBlendChange() {};
	protected:
		// ��ϲ���
		BlendParam _blendParam;
	};
}
