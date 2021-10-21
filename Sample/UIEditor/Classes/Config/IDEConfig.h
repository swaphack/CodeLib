#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	// ide ����
	class IDEConfig : public Config
	{
	public:
		struct IDESetting
		{
			// ��ƽ���
			std::string Design;
			// �ؼ�����
			std::string Control;
			// ��ɫ��ģʽ 0-Ĭ�ϣ�1-������2-��ͼ
			int ShaderMode = 0;
		};

		struct ShaderSetting
		{
			// ��������ɫ��
			std::string TexVertex;
			// ����ƬԪ��ɫ��
			std::string TexFragment;
			// ��ɫ������ɫ��
			std::string ColorVertex;
			// ��ɫƬԪ��ɫ��
			std::string ColorFragment;
		};

		struct TextSetting
		{
		public:
			// ����
			std::string FontPath;
			// �ֺ�
			int FontSize = 0;
			//��ɫ
			phy::Color3B TextColor;
		};
	public:
		// �ı�����
		const TextSetting& getText() const;
		// ide�����ļ�
		const IDESetting& getIDE() const;
		// ��ɫ������
		const ShaderSetting* getShader() const;
	public:
		// ��������
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		// xml����
		tool::XmlHelper _helper;
		// �ı� ����
		TextSetting _text;
		// ��ɫ������
		std::vector<ShaderSetting> _shaders;
		// ide ����
		IDESetting _ide;
	};
}
