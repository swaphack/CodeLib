#pragma once

namespace render
{
	class TessilationProtocol
	{
	public:
		TessilationProtocol();
		virtual ~TessilationProtocol();
	public:
		/**
		*	�����Ƿ�����ϸ����ɫ��
		*/
		void setEnableTessilation(bool bEnable);
		/**
		*	�Ƿ�����ϸ����ɫ��
		*/
		bool isTessilationEnable() const;
	public:
		/**
		*	����ϸ�ֶ�����
		*/
		void setTessVerticeCount(int value);
		/**
		*	ϸ�ֶ�����
		*/
		int getTessVerticeCount() const;
		/**
		*	����ϸ���ⲿ�ȼ�
		*/
		void setTessOuterLevel(float value[4]);
		/**
		*	ϸ���ⲿ�ȼ�
		*/
		const float* getTessOuterLevel() const;
		/**
		*	����ϸ���ڲ��ȼ�
		*/
		void setTessInnerLevel(float value[2]);
		/**
		*	ϸ���ڲ��ȼ�
		*/
		const float* getTessInnerLevel() const;
	protected:
		/**
		*	����ϸ��
		*/
		void updateTessilation();
	protected:
		// �Ƿ�����ϸ��
		bool _bTessilationEnable = false;
		// ϸ�ֶ�����, Ĭ��������
		int _tessVerticeCount = 3;
		// ϸ���ⲿ�ȼ�
		float _tessOuterLevel[4];
		// ϸ���ڲ��ȼ�
		float _tessInnerLevel[2];
	};
}
