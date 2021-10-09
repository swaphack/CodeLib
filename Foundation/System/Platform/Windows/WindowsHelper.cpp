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
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С
	ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������
	ofn.lpstrFilter = tformat;//���ù���
	ofn.nFilterIndex = 1;//����������
	ofn.lpstrFile = szOpenFileNames;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(szOpenFileNames);//����������
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrInitialDir = tpath;//��ʼĿ¼ΪĬ��
	ofn.lpstrTitle = TEXT("Please Select File");//ʹ��ϵͳĬ�ϱ������ռ���
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER | OFN_ALLOWMULTISELECT;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��
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
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С
	ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������
	ofn.lpstrFilter = tformat;//���ù���
	ofn.nFilterIndex = 1;//����������
	ofn.lpstrFile = szPath;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(szPath);//����������
	ofn.lpstrInitialDir = tpath;//��ʼĿ¼ΪĬ��
	ofn.lpstrTitle = TEXT("Please Select File");//ʹ��ϵͳĬ�ϱ������ռ���
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��
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