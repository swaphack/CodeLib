#include "AccountHttpDispatcher.h"

#include "../DataBase/DBManager.h"

using namespace hs;

#define BREAK_IF_EMPTY(str) { if (str.empty()) return false; }

// зЂВс
class Login : public IHttpAction
{
public:
	virtual const char* getUrl()
	{
		return "/Login/";
	}
	virtual bool hand(sys::HttpResponse& response)
	{
		std::string username = getParam("username");
		BREAK_IF_EMPTY(username);
		std::string password = getParam("password");
		BREAK_IF_EMPTY(password);
		std::string confirmPasssword = getParam("confirmpwd");
		BREAK_IF_EMPTY(confirmPasssword);

		if (password != confirmPasssword)
		{
			return false;
		}

		std::map<std::string, std::string> keys;
		keys["Name"] = username;
		sys::IDataRecord* pRecord = DBManager::getInstance()->find("User", keys);
		if (pRecord != nullptr)
		{
			return false;
		}
		keys["Password"] = password;
		DBManager::getInstance()->insert("User", keys);

		response.getDocument()->writeContentString("Login OK");

		return true;
	}
};


AccountHttpDispatcher::AccountHttpDispatcher()
{
	this->init();
}

AccountHttpDispatcher::~AccountHttpDispatcher()
{

}

void AccountHttpDispatcher::init()
{
	this->registerHttpAction(new Login());
}
