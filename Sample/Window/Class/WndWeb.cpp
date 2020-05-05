#include "WndWeb.h"

WndWeb::WndWeb( const std::string& ip, int port )
	:web::WebApplication(ip, port)
{
	this->init();
}
