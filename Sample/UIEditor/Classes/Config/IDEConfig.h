#pragma once

#include "system.h"
#include "toollib.h"
#include <string>

namespace ue
{
	/// <summary>
	/// ide ����
	/// </summary>
	class IDEConfig
	{
	public:
		/// <summary>
		/// �ı�����
		/// </summary>
		struct Text
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
		const Text& getText() const;
	public:
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);
	private:
		/// <summary>
		/// �ı�����
		/// </summary>
		Text _text;
		/// <summary>
		/// xml����
		/// </summary>
		tool::XmlHelper _helper;
	};
}
