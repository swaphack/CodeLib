#include "Script.h"
#include "Document/import.h"


using namespace script;

Script* Script::s_script = nullptr;

Script::Script()
:_mainDocument(nullptr)
{
}

Script::~Script()
{
	removeAllDocuments();
}

Script* Script::getInstance()
{
	if (s_script == nullptr)
	{
		s_script = new Script();
	}

	return s_script;

}

bool Script::load(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	Document* pDoc = new Document();
	if (!pDoc->loadFile(filepath))
	{
		delete pDoc;
		return false;
	}

	_mainDocument = pDoc;

	this->run();

	return true;
}

bool Script::import(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	Document* pDoc = new Document();
	if (!pDoc->loadFile(filepath))
	{
		delete pDoc;
		return false;
	}

	this->addDocument(filepath, pDoc);

	return true;
}

void Script::run()
{

}

void Script::addDocument(const char* name, Document* document)
{
	if (name == nullptr || document == nullptr)
	{
		return;
	}

	removeDocument(name);

	_documents[name] = document;
}

void Script::removeDocument(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	std::map<std::string, Document*>::iterator iter = _documents.find(name);
	
	if (iter == _documents.end())
	{
		return;
	}

	delete iter->second;

	_documents.erase(iter);
}

void Script::removeAllDocuments()
{
	std::map<std::string, Document*>::iterator iter = _documents.begin();

	while (iter != _documents.end())
	{
		delete iter->second;
		iter++;
	}

	_documents.clear();
}
