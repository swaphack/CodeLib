#pragma once

#include "web.h"

class WndWeb : public web::WebApplication
{
public:
	WndWeb(const std::string& ip, int port);
protected:
private:
};