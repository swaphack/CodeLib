#pragma once

#include <cstdint>

namespace render
{
	/**
	*	���ز��� MSAA
	*	��һ�ֿ���ݵļ�������ͨ����һ�������Ͻ��ж�β�����μ��㲢���ջ���(Resolve to single-sample)����ʹ���Ƶ�ͼ���Ե����ƽ��
	*	���������طָ�Ϊ��� 4�� 8��16��32
	*/
	class MultiSampling
	{
	public:
		// ʹ��ƬԪ��alphaֵ�������Ĳ���������
		static void enableSampleAlphaToCoverage();
		// ��ƬԪ��alphaֵ����Ϊ����alphaֵ���������Ĳ���������
		static void enableSampleAlphaToOne();
		// ʹ��glSampleCoverage�����㣬�븲���ʼ���Ľ�����������
		static void enableSampleCoverage();

		static void disableSampleAlphaToCoverage();
		static void disableSampleAlphaToOne();
		static void disableSampleCoverage();

		static void setSampleCoverage(float value, bool invert);
		/**
			����һ��32Ϊ�Ĳ�������mask�������ǰ֡�����������32������������������ĳ��ȿ����Ƕ��32λ��С���ֶ����
			������Ҫ��index����
			Ҳ����ͨ��ƬԴ��ɫ��д��gl_SampleMask������
		*/ 
		static void setSampleMask(uint32_t index, uint32_t mask);
	};
}

