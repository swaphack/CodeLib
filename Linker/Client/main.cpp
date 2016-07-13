#include "system.h"
#include <windows.h>
#include <thread>
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
		if (dataQueue.empty())
		{
			return;
		}
		NetData* top = dataQueue.top();
		std::string recvData = std::string(top->data, top->size);
		LOG("Receive : %s\n", recvData.c_str());
		dataQueue.pop();
		delete top;

		_client->sendString(recvData.c_str());
	}
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
		client->sendString(msg.c_str());

		clients[i] = std::make_pair(client, recv);
	}
}

int main(int argc, char** argv)
{
	Socket::InitSockModule();
	
	std::map<int, std::pair<Client*, ClientRecv*>> clients;

	initManyClients(clients, 1);

	std::map<int, std::pair<Client*, ClientRecv*>>::iterator it;

	std::thread* th = new std::thread([&]() {
		while (true)
		{
			Sleep(100);
			it = clients.begin();
			while (it != clients.end())
			{
				it->second.first->update();
				it++;
			}
		}
	});
	th->detach();

	while (true)
	{
		std::string word = G_CONSOLE->readLine();
		if (word.empty())
		{
			continue;
		}
		NetData* data = new NetData(word.c_str());
		clients[0].first->sendMessage(data);
	}

	delete th;
	Socket::ReleaseSockModule();
	return 0;
};