#include "system.h"
#include "web.h"
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
	void onRecv(int id, DataQueue& dataQueue)
	{
		if (dataQueue.empty())
		{
			return;
		}
		NetData* top = dataQueue.top();
		std::string recvData = std::string(top->data, top->size);
		PRINT("Receive : %s\n", recvData.c_str());
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
		if (!client->connect())
		{
			delete client;
			break;
		}

		ClientRecv* recv = new ClientRecv(client);
		client->setRecvHandler(recv, static_cast<CLIENT_RECV_HANDLER>(&ClientRecv::onRecv));

 		std::string msg = "Hello world!";
		client->sendString(msg.c_str());

		clients[i] = std::make_pair(client, recv);
	}
}

void test1()
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
}

void onDownloadCallback(int tag, const char* data, int size)
{
	PRINT("%s", data);
}

void test2()
{
	const char* url = "blog.csdn.net";
	const char* ip = "127.0.0.1";
	int port = 9547;

	Socket::InitSockModule();

	web::HttpDownload* pDownload = new web::HttpDownload();

	if (pDownload->download(ip, port, "", onDownloadCallback, 1))
	{
		while (true);
	}

	Socket::ReleaseSockModule();
}

int main(int argc, char** argv)
{
	
	test2();
	
	
	return 0;
};