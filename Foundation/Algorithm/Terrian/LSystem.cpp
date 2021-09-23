#include "LSystem.h"

const std::string& alg::LSystem::getOrigin() const
{
    return _origin;
}

void alg::LSystem::setOrigin(const std::string& origin)
{
    _origin = origin;
}

void alg::LSystem::addWord(const std::string& word)
{
    _words.push_back(word);
}

void alg::LSystem::removeWord(const std::string& word)
{
    auto it = std::find(_words.begin(), _words.end(), word);
    if (it != _words.end()) _words.erase(it);
}

void alg::LSystem::setGenerateSymbol(const std::string& symbol)
{
    _generateSymbol = symbol;
}

const std::string& alg::LSystem::getGenerateSymbol()
{
    return _generateSymbol;
}

void alg::LSystem::setWordHandle(const WordHandle& handle)
{
    _wordHandle = handle;
}

const alg::LSystem::WordHandle& alg::LSystem::getWordHandle() const
{
    return _wordHandle;
}