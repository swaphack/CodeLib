#pragma once

namespace ui
{
	// ��С��������
	enum class SizeType
	{
		// �̶�
		FIXED,
		// ��С����Сʱ������С
		MINIMUM,
		// �Ŵ����ʱ�������
		MAXIMUM,
		// �Զ�����
		EXPANDING,
	};

	/**
	*	 �����С��������
	*/
	struct SizePolicy
	{
		// ��ȵ�������
		SizeType width;
		// �߶ȵ�������
		SizeType height;

		SizePolicy() :width(SizeType::EXPANDING), height(SizeType::EXPANDING) {}
		SizePolicy(SizeType w, SizeType h) :width(w), height(h) {}

		SizePolicy& operator=(const SizePolicy& value)
		{
			width = value.width;
			height = value.height;

			return *this;
		}
	};
}
