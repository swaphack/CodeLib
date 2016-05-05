#include "Action.h"

#include <ctime>

using namespace user;

class ActionRecord : public ILoggerRecord
{
public:
	ActionRecord(long id, const char* word):_id(id),_string(word){}
public:
	virtual long getID() { return _id; }
	virtual const char* getString() { return _string.c_str(); }
protected:
private:
	long _id;
	std::string _string;
};

//////////////////////////////////////////////////////////////////////////

Action::Action()
{

}

const char* Action::getActionString()
{
	return "";
}

ILoggerRecord* Action::generateRecord()
{
	return this->generateRecord(this);
}


ILoggerRecord* Action::generateRecord(Action* action)
{
	time_t t;
	time(&t);

	ILoggerRecord* record = new ActionRecord(t, action->getActionString());

	return record;
}
