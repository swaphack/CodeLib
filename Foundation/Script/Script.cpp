#include "Script.h"
#include "Document/import.h"
#include "Compile/import.h"
#include "Core/import.h"

using namespace script;

Script* Script::s_script = nullptr;

// ÎÄ±¾¹ýÂË
class TextFilter : public ITextFilter
{
public:
	TextFilter(WordSet* pWordSet) :m_pWordSet(pWordSet) {}
	virtual ~TextFilter(){}
private:
	WordSet* m_pWordSet = nullptr;
public:
	virtual bool match(const char* text, int& size)
	{
		if (m_pWordSet == nullptr)
		{
			return false;
		}
		return m_pWordSet->pickWord(text, size);
	}
};

Script::Script()
:_mainDocument(nullptr)
{
	_wordDocument = new WordDocument();
}

Script::~Script()
{
	removeAllDocuments();
	if (_wordDocument)
	{
		delete _wordDocument;
	}
}

Script* Script::getInstance()
{
	if (s_script == nullptr)
	{
		s_script = new Script();
	}

	return s_script;
}

bool Script::initWordSet(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	_wordDocument->getWordSet()->clear();
	if (!_wordDocument->loadFile(filepath))
	{
		return false;
	}
	return true;
}

bool Script::initWordFilter()
{
	WordFilters::getInstance()->addFilter(new TextFilter(_wordDocument->getWordSet()));

	return true;
}

bool Script::initSysmbolRule(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	return SymbolHandler::getInstance()->load(filepath);
}

bool Script::load(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	Document* pDoc = complieFile(filepath);
	if (pDoc == nullptr)
	{
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

	Document* pDoc = complieFile(filepath);
	if (pDoc == nullptr)
	{
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

Document* Script::complieFile(const char* filepath)
{
	Document* pDoc = new CompilerDocument();
	if (!pDoc->loadFile(filepath))
	{
		delete pDoc;
		return nullptr;
	}
	return pDoc;
}
