#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// ide ����
	/// </summary>
	class IDEConfig : public Config
	{
	public:
		struct IDESetting
		{
			/// <summary>
			/// ��ƽ���
			/// </summary>
			std::string Design;
			/// <summary>
			/// �ؼ�����
			/// </summary>
			std::string Control;
		};
		/// <summary>
		/// �ı�����
		/// </summary>
		struct TextSetting
		{
		public:
			/// <summary>
			/// ����
			/// </summary>
			std::string FontPath;
			/// <summary>
			/// �ֺ�
			/// </summary>
			int FontSize = 0;
			/// <summary>
			/// ��ɫ
			/// </summary>
			phy::Color3B TextColor;
		};
	public:
		/// <summary>
		/// �ı�����
		/// </summary>
		const TextSetting& getText() const;
		/// <summary>
		/// ide�����ļ�
		/// </summary>
		/// <returns></returns>
		const IDESetting& getIDE() const;
	public:
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		/// <summary>
		/// xml����
		/// </summary>
		tool::XmlHelper _helper;
		/// <summary>
		/// �ı� ����
		/// </summary>
		TextSetting _text;
		/// <summary>
		/// ide ����
		/// </summary>
		IDESetting _ide;
	};
}
