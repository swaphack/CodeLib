#include "WindowsHelper.h"
#include<windows.h>
#include<Commdlg.h>
#include <atlbase.h>
#include <atlstr.h> 

#include "Type/String.h"
#include "Text/CharsetHelper.h"

std::vector<std::string> sys::WindowsHelper::selectFiles(const std::string & path, const std::vector<std::string>&vecFormat)
{
	std::string format = "File Format\0";
	for (const auto& item : vecFormat)
	{
		format += "*.";
		format += item;
		format += ";";
	}
	if (vecFormat.size() > 0)
	{
		format = format.substr(0, format.size() - 1);
	}
	format += "\0\0";

	LPSTR tpath = CA2T(path.c_str());
	LPSTR tformat = CA2T(format.c_str());

	TCHAR szOpenFileNames[80 * MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szFileName[80 * MAX_PATH];
	TCHAR* p;
	int nLen = 0;

	std::vector<std::string> files;

	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);//结构体大小
	ofn.hwndOwner = NULL;//拥有着窗口句柄，为NULL表示对话框是非模态的，实际应用中一般都要有这个句柄
	ofn.lpstrFilter = tformat;//设置过滤
	ofn.nFilterIndex = 1;//过滤器索引
	ofn.lpstrFile = szOpenFileNames;//接收返回的文件名，注意第一个字符需要为NULL
	ofn.nMaxFile = sizeof(szOpenFileNames);//缓冲区长度
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrInitialDir = tpath;//初始目录为默认
	ofn.lpstrTitle = TEXT("Please Select File");//使用系统默认标题留空即可
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER | OFN_ALLOWMULTISELECT;//文件、目录必须存在，隐藏只读选项
	if (GetOpenFileName(&ofn))
	{
		lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset);
		szPath[ofn.nFileOffset] = '\0';
		nLen = lstrlen(szPath);
		if (szPath[nLen - 1] != TEXT('\\'))
		{
			lstrcat(szPath, TEXT("\\"));
		}
		p = szFileName + ofn.nFileOffset;
		while (*p)
		{
			ZeroMemory(&szFileName, sizeof(szFileName));
			lstrcat(szFileName, p);
			lstrcat(szFileName, TEXT("\n")); 
			p += lstrlen(p) + 1;
			std::string selectPath = CT2A(szFileName);
			if (selectPath.find_first_of(path) != -1)
			{
				String text = selectPath.substr(path.size());
				if (!text.empty())
				{
					text = text.replace("\\", "/");
					text = text.subString(1);
					files.push_back(text.getString());
				}
			}
		}
	}

	return files;
}

std::string sys::WindowsHelper::selectFile(const std::string& path, const std::vector<std::string>& vecFormat)
{
	std::string format = "File Format\0";
	for (const auto& item : vecFormat)
	{
		format += "*.";
		format += item;
		format += ";";
	}
	if (vecFormat.size() > 0)
	{
		format = format.substr(0, format.size() - 1);
	}
	format += "\0\0";

	LPSTR tpath = CA2T(path.c_str());
	LPSTR tformat = CA2T(format.c_str());

	TCHAR szPath[MAX_PATH];

	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);//结构体大小
	ofn.hwndOwner = NULL;//拥有着窗口句柄，为NULL表示对话框是非模态的，实际应用中一般都要有这个句柄
	ofn.lpstrFilter = tformat;//设置过滤
	ofn.nFilterIndex = 1;//过滤器索引
	ofn.lpstrFile = szPath;//接收返回的文件名，注意第一个字符需要为NULL
	ofn.nMaxFile = sizeof(szPath);//缓冲区长度
	ofn.lpstrInitialDir = tpath;//初始目录为默认
	ofn.lpstrTitle = TEXT("Please Select File");//使用系统默认标题留空即可
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//文件、目录必须存在，隐藏只读选项
	if (GetOpenFileName(&ofn))
	{
		std::string selectPath = CT2A(ofn.lpstrFile);
		if (selectPath.find_first_of(path) == -1)
			return "";

		String text = selectPath.substr(path.size());
		if (text.empty())
		{
			return "";
		}
		text = text.replace("\\", "/");
		text = text.subString(1);
		return text.getString();
	}

	return "";
}