#include "LSystem.h"

const std::string& alg::mesh::LSystem::getOrigin() const
{
    return _origin;
}

void alg::mesh::LSystem::setOrigin(const std::string& origin)
{
    _origin = origin;
}

void alg::mesh::LSystem::addWord(const std::string& word)
{
    _words.push_back(word);
}

void alg::mesh::LSystem::removeWord(const std::string& word)
{
    auto it = std::find(_words.begin(), _words.end(), word);
    if (it != _words.end()) _words.erase(it);
}

void alg::mesh::LSystem::setGenerateSymbol(const std::string& symbol)
{
    _generateSymbol = symbol;
}

const std::string& alg::mesh::LSystem::getGenerateSymbol()
{
    return _generateSymbol;
}

void alg::mesh::LSystem::setWordHandle(const WordHandle& handle)
{
    _wordHandle = handle;
}

const alg::mesh::LSystem::WordHandle& alg::mesh::LSystem::getWordHandle() const
{
    return _wordHandle;
}