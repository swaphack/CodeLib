#include "system.h"

#include "Content.h"
#include "../String/import.h"
#include "../Target/import.h"


using namespace search;

Content::Content()
{

}

Content::~Content()
{
	this->removeAllTargets();
}

void Content::addTarget( Target* target )
{
	if (target == nullptr)
	{
		return;
	}

	_targetKeys[target];
}

void Content::removeTarget( Target* target )
{
	if (target == nullptr)
	{
		return;
	}

	_targetKeys.erase(target);
}

void Content::addKey( const char* key )
{
	if (key == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);

	_keyTargets[word];
}

void Content::removeKey( const char* key )
{
	if (key == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);

	_keyTargets.erase(word);
}

void Content::addKeyToTarget( Target* target, const char* key )
{
	if (target == nullptr || key == nullptr)
	{
		return;
	}

	std::set<std::string*>* keys = this->getKeysByTarget(target);
	if (keys == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);

	keys->insert(word);
}

void Content::removeKeyFromTarget( Target* target, const char* key )
{
	if (target == nullptr || key == nullptr)
	{
		return;
	}

	std::set<std::string*>* keys = this->getKeysByTarget(target);
	if (keys == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);

	keys->erase(word);
}

void Content::addTargetToKey( const char* key, Target* target )
{
	if (target == nullptr || key == nullptr)
	{
		return;
	}

	std::set<Target*>* targets = this->getTargetsByKey(key);
	if (targets == nullptr)
	{
		return;
	}

	targets->insert(target);
}

void Content::removeTargetFromKey( const char* key, Target* target )
{
	if (target == nullptr || key == nullptr)
	{
		return;
	}

	std::set<Target*>* targets = this->getTargetsByKey(key);
	if (targets == nullptr)
	{
		return;
	}

	targets->erase(target);
}

std::set<Target*>* Content::getTargetsByKey(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}

	std::string* word = GET_STRING_PTR(key);

	if (_keyTargets.find(word) == _keyTargets.end())
	{
		return nullptr;
	}

	return &_keyTargets[word];
}

std::set<std::string*>* Content::getKeysByTarget(Target* target)
{
	if (target == nullptr)
	{
		return nullptr;
	}

	if (_targetKeys.find(target) == _targetKeys.end())
	{
		return nullptr;
	}

	return &_targetKeys[target];
}

void Content::addNewKeyTarget( const char* key, Target* target )
{
	if (key == nullptr || target == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);


	this->addKey(key);
	this->addTarget(target);

	_keyTargets[word].insert(target);
	_targetKeys[target].insert(word);

// 	this->addTargetToKey(key, target);
// 	this->addKeyToTarget(target, key);
	
}

void Content::removeTargetsKey( Target* target, const char* key )
{
	if (key == nullptr || target == nullptr)
	{
		return;
	}

	this->removeKeyFromTarget(target, key);
	this->removeTargetFromKey(key, target);


	std::set<std::string*>* keys = this->getKeysByTarget(target);

	if (keys == nullptr || keys->size() == 0)
	{
		this->removeTarget(target);
		target->dispose();
	}
}

void Content::removeKeysTarget( const char* key, Target* target )
{
	if (key == nullptr || target == nullptr)
	{
		return;
	}

	this->removeTargetFromKey(key, target);
	this->removeKeyFromTarget(target, key);

	std::set<std::string*>* keys = this->getKeysByTarget(target);

	if (keys == nullptr || keys->size() == 0)
	{
		this->removeTarget(target);
		target->dispose();
	}
}

void Content::removeAllTargets()
{
	std::map<Target*, std::set<std::string*>>::iterator it = _targetKeys.begin();
	for (;it != _targetKeys.end(); it++)
	{
		it->first->dispose();
	}

	_targetKeys.clear();
}
