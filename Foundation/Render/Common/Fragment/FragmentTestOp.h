#pragma once

namespace render
{
	/**
	*	ƬԪ���Ի����
	*	˳��: ���ǰ��Ĳ��Ի��߲�����ͬͨ���Ļ�������Ĳ�ִ��
	*	1.�ü�����
	*	2.���ز�������
	*	3.ģ�����
	*	4.��Ȳ���
	*	5.���
	*	6.�߼�����
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
		virtual void startTest();
		virtual void test();
		virtual void endTest();
	protected:
		bool _enabled = false;
	};
}
