#include "system.h"
#include <windows.h>
using namespace sys;

const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;

class ClientRecv : public Object
{
public:
	ClientRecv(Client* client):_client(client){}
public:
	void onRecv(DataQueue& dataQueue)
	{
		NetData* top = dataQueue.top();
		std::string recvData = std::string(top->data, top->size);
		_client->sendMessage(new NetData(top->data, top->size));
		dataQueue.pop();
		delete top;
	}
protected:
private:
	Client* _client;
};

void initManyClients(std::map<int, std::pair<Client*, ClientRecv*>>& clients, int count)
{
	for (int i = 0; i < count; i++)
	{
		Client* client = new Client(WEB_IP, WEB_PORT);

		ClientRecv* recv = new ClientRecv(client);
		client->setRecvHandler(recv, static_cast<CLIENT_RECV_HANDLER>(&ClientRecv::onRecv));

		std::string msg = "Hello world!";
		client->sendMessage(new NetData((char*)msg.c_str(), msg.size()));

		clients[i] = std::make_pair(client, recv);
	}
}

int main(int argc, char** argv)
{
	Socket::InitSockModule();
	
	std::map<int, std::pair<Client*, ClientRecv*>> clients;

	initManyClients(clients, 1000);

	std::map<int, std::pair<Client*, ClientRecv*>>::iterator it = clients.begin();

	while (true)
	{
		Sleep(100);
		while (it != clients.end())
		{
			it->second.first->update();
		}
	}

	Socket::ReleaseSockModule();
	return 0;
};