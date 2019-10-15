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
	_worldFilter = new WordFilter();
	_symbolHandler = new SymbolHandler();

	_worldFilter->addFilter(new TextFilter(_wordDocument->getWordSet()));
}

Script::~Script()
{
	removeAllDocuments();
	if (_wordDocument)
	{
		delete _wordDocument;
	}

	if (_worldFilter)
	{
		delete _worldFilter;
	}

	if (_symbolHandler)
	{
		delete _symbolHandler;
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

bool Script::initWordSet(const std::string& filepath)
{
	_wordDocument->getWordSet()->clear();
	if (!_wordDocument->loadFile(filepath))
	{
		return false;
	}
	return true;
}

bool Script::initSysmbolRule(const std::string& filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	return _symbolHandler->load(filepath);
}

bool Script::load(const std::string& filepath)
{
	Document* pDoc = complieFile(filepath);
	if (pDoc == nullptr)
	{
		return false;
	}

	_mainDocument = pDoc;

	this->run();

	return true;
}

bool Script::import(const std::string& filepath)
{
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

void Script::addDocument(const std::string& name, Document* document)
{
	if (document == nullptr)
	{
		return;
	}

	removeDocument(name);

	_documents[name] = document;
}

void Script::removeDocument(const std::string& name)
{
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

Document* Script::complieFile(const std::string& filepath)
{
	Document* pDoc = new CompilerDocument();
	if (!pDoc->loadFile(filepath))
	{
		delete pDoc;
		return nullptr;
	}
	return pDoc;
}
