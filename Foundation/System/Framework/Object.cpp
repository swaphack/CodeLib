#include "Object.h"
#include "AutoReleasePool.h"


using namespace sys;


Object::Object( int64 id /*= 0*/ )
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

int64 Object::getID() const
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
	if (this->RetainCount <= 0)
	{
		this->dispose();
	}
}

void Object::dispose()
{
	delete this;
}

void Object::autoRelease()
{
	G_AUTORELEASEPOOL->addObject(this);
	this->_bAutoRelease = true;
}

void Object::setID(int32 id)
{
	_id = id;
}
