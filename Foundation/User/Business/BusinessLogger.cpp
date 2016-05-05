#include "BusinessLogger.h"

using namespace user;

BusinessLogger::BusinessLogger(long type, const char* url )
:Logger(type, url)
{
	GET_GLOBAL_INSTANCE(Loggers)->addLogger(type, this);

	this->load();
}


BusinessLogger::~BusinessLogger()
{
	this->flush();

	GET_GLOBAL_INSTANCE(Loggers)->removeLogger(this->getType());
}

void BusinessLogger::load()
{

}

void BusinessLogger::save()
{

}
