#pragma once

namespace render
{
	class Node;
	class ShaderProgram;

	// ���սӿ�
	class LightProtocol
	{
	public:
		LightProtocol();
		virtual ~LightProtocol();
	public:
		// ֧�ֹ�Դ
		void setSupportLight(bool support);
		// ֧�ֹ�Դ
		bool isSupportedLight();
		// ֧�ֶ��Դ
		void setSupportMultiLight(bool support);
		// ֧�ֶ��Դ
		bool isSupportedMultiLight();

		// ��ʾ��Ӱ
		void setCastShadow(bool show);
		// ��ʾ��Ӱ
		bool isCastShadow();
		// ������Ӱ
		void setRecieveShadow(bool recieve);
		// ������Ӱ
		bool isRecieveShadow();
	protected:
		// ֧�ֶ��Դ
		bool _bSupportMultiLight = false;
		// ֧�ֶ��Դ
		bool _bSupportLight = false;

		// ��ʾ��Ӱ
		bool _bCastShadow = false;
		// ������Ӱ
		bool _bRecieveShadow = false;
	};
}