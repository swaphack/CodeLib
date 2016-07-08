#pragma once

#include "commandbase.h"
#include "tinyxml\tinyxml.h"
#include "tinyxml2\tinyxml2.h"

struct SSkillExportImgMeta
{
	void reset()
	{
		m_strFolderName.clear();
		m_vectNodeId.clear();
	}

	std::string m_strFolderName;
	std::vector<int> m_vectNodeId;
};

typedef std::vector<SSkillExportImgMeta>			SkillExportImgMetaVector;
typedef SkillExportImgMetaVector::const_iterator	SkillExportImgMetaConstIterator;

class ParseCCSkill
{
public:
	ParseCCSkill();
	~ParseCCSkill();
	
public:
	//为目录末尾加'/'或'\'
	std::string NormalizeDir(const std::string& strDir);
	void setSrcRootDir(const std::string& strDir);
	bool PrepareData();
	int getLosResNum() const;
	const SkillExportImgMetaConstIterator GetExportImgBeginIterator() const;
	const SkillExportImgMetaConstIterator GetExportImgEndIterator() const;

private:
	bool loadSkillXml();
	bool loadSKillListXml();
	bool loadBuffListXml();
	bool loadListXml();
	bool generatemSkillExportImgMetaVector();

private:
	typedef std::vector<int>				IDVector;

	struct SSkillExportMeta
	{
		SSkillExportMeta()
		{
			reset();
		}

		void reset()
		{
			m_strName.clear();
			m_vecBufferType.clear();
		}

		std::string m_strName;
		IDVector m_vecBufferType;
	};

	typedef std::map<int, SSkillExportMeta> SkillExportMetaMap; //<mark, skill>
	typedef std::map<int, IDVector>			ActNodeIdMap;

private:
	SkillExportMetaMap m_mapSkillExportMeta;
	std::map<int, int> m_mapActSkillList;
	std::map<int, int> m_mapBuffSkillList;
	ActNodeIdMap m_mapActNodeId;
	SkillExportImgMetaVector m_vectSkillExportImgMeta;

private:
	std::string m_strSrcRootDir;     //输入文件的根目录
	int m_nLossResNum; //缺少的资源数量
};

