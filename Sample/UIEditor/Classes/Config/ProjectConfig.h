#pragma once

#include "system.h"
#include "toollib.h"
#include "Config.h"
#include <string>

namespace ue
{
	/// <summary>
	/// 工程 配置
	/// </summary>
	class ProjectConfig : public Config
	{
	public:
		/// <summary>
		/// 工程
		/// </summary>
		struct ProjectSetting
		{
		public:
			/// <summary>
			/// 根目录
			/// </summary>
			std::string Root;
		};
		/// <summary>
		/// 最近打开文件
		/// </summary>
		struct RecentSetting
		{
		public:
			/// <summary>
			/// 目录
			/// </summary>
			std::vector<std::string> Files;
		public:
			/// <summary>
			/// 获取文件
			/// </summary>
			/// <param name="index"></param>
			/// <returns></returns>
			std::string getFile(int index) const;
		};
	public:
		/// <summary>
		/// 工程配置
		/// </summary>
		const ProjectSetting& getProject() const;
		/// <summary>
		/// 最近操作配置
		/// </summary>
		const RecentSetting& getRecent() const;
	public:
		/// <summary>
		/// 加载配置
		/// </summary>
		/// <param name="filepath"></param>
		void loadXml(const std::string& filepath);

		virtual void Dispose();
	private:
		/// <summary>
		/// 工程
		/// </summary>
		ProjectSetting _project;
		/// <summary>
		/// 最近打开文件
		/// </summary>
		RecentSetting _recentFiles;
		/// <summary>
		/// xml工具
		/// </summary>
		tool::XmlHelper _helper;
	};
}
