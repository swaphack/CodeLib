#include "BusinessDataBase.h"

using namespace user;


BusinessDataBase::BusinessDataBase( long type, const char* url )
	:DataBase(type, url)
{
	GET_GLOBAL_INSTANCE(DataBases)->addDataBase(type, this);

	this->load();
}


BusinessDataBase::~BusinessDataBase()
{
	this->flush();

	GET_GLOBAL_INSTANCE(DataBases)->removeDataBase(this->getType());
}


void BusinessDataBase::load()
{

}


void BusinessDataBase::save()
{

}