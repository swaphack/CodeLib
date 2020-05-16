#pragma once

namespace render
{
	/**
	*	片元测试或操作
	*	顺序: 如果前面的测试或者操作不同通过的话，后面的不执行
	*	1.裁剪测试
	*	2.多重采样操作
	*	3.模板测试
	*	4.深度测试
	*	5.混合
	*	6.逻辑操作
	*/
	class FragmentTestOp
	{
	public:
		FragmentTestOp();
		virtual ~FragmentTestOp();
	public:
		void setEnabled(bool enabled);
		bool isEnabled();
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		bool _enabled = false;
	};
}
