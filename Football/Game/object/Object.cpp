#include "Object.h"

using namespace game;


Object::Object()
{
	this->setPosition(Vector::Zero);
	this->setScale(Vector::One);
	this->setVolume(Vector::One);
}

Object::~Object()
{

}
