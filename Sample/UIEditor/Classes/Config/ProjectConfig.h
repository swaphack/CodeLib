#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// ���� ����
	/// </summary>
	class ProjectConfig : public Config
	{
	public:
		/// <summary>
		/// ����
		/// </summary>
		struct ProjectSetting
		{
		public:
			/// <summary>
			/// ��Ŀ¼
			/// </summary>
			std::string Root;
		};
		/// <summary>
		/// ������ļ�
		/// </summary>
		struct RecentSetting
		{
		public:
			/// <summary>
			/// Ŀ¼
			/// </summary>
			std::vector<std::string> Files;
		public:
			/// <summary>
			/// ��ȡ�ļ�
			/// </summary>
			/// <param name="index"></param>
			/// <returns></returns>
			std::string getFile(int index) const;
		};
	public:
		/// <summary>
		/// ��������
		/// </summary>
		const ProjectSetting& getProject() const;
		/// <summary>
		/// �����������
		/// </summary>
		const RecentSetting& getRecent() const;
	public:
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		/// <summary>
		/// ����
		/// </summary>
		ProjectSetting _project;
		/// <summary>
		/// ������ļ�
		/// </summary>
		RecentSetting _recentFiles;
		/// <summary>
		/// xml����
		/// </summary>
		tool::XmlHelper _helper;
	};
}
