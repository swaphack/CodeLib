#pragma once

#include <cstdint>

namespace render
{
	/**
	*	多重采样 MSAA
	*	是一种抗锯齿的技术，它通过在一个像素上进行多次采样多次计算并最终汇总(Resolve to single-sample)，可使绘制的图像边缘更加平滑
	*	将单个像素分割为多份 4， 8，16，32
	*/
	class MultiSampling
	{
	public:
		// 使用片元的alpha值计算最后的采样覆盖率
		static void enableSampleAlphaToCoverage();
		// 将片元的alpha值设置为最大的alpha值，计算最后的采样覆盖率
		static void enableSampleAlphaToOne();
		// 使用glSampleCoverage来计算，与覆盖率计算的结果进行与操作
		static void enableSampleCoverage();

		static void disableSampleAlphaToCoverage();
		static void disableSampleAlphaToOne();
		static void disableSampleCoverage();

		static void setSampleCoverage(float value, bool invert);
		/**
			设置一个32为的采样掩码mask，如果当前帧缓存包含多于32个采样数，采样掩码的长度可能是多个32位大小的字段组成
			这样需要用index设置
			也可以通过片源着色器写入gl_SampleMask来设置
		*/ 
		static void setSampleMask(uint32_t index, uint32_t mask);
	};
}

