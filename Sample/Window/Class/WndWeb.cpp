#include "WndWeb.h"

WndWeb::WndWeb( const char* ip, int port )
	:web::WebApplication(ip, port)
{
	this->init();
}
