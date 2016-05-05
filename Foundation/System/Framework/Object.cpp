#include "Object.h"
#include "AutoReleasePool.h"


using namespace sys;


Object::Object( long id /*= 0*/ )
:_id(id)
,RetainCount(1)
,_bAutoRelease(false)
{

}

Object::~Object()
{
	if (this->_bAutoRelease)
	{
		G_AUTORELEASEPOOL->removeObject(this);
	}
}

long Object::getID() const
{
	return _id;
}

void Object::retain()
{
	this->RetainCount++;
}

void Object::release()
{
	this->RetainCount--;
	if (this->RetainCount <= 1)
	{
		this->disponse();
	}
}

void Object::disponse()
{
	delete this;
}

void Object::autoRelease()
{
	G_AUTORELEASEPOOL->addObject(this);
	this->_bAutoRelease = true;
}
