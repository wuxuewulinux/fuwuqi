
#ifndef _SOCKETDBCLIENT_HPP_
#define _SOCKETDBCLIENT_HPP_

#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define DBCLIENT SocketDBClient::Instance()

class SocketDBClient
{
public:
	SocketDBClient();
	~SocketDBClient();
	static SocketDBClient * Instance();
	int CreateSocket(const char * dizi,int duankou);
	int ConnectDB();
	int GetSocketIo(){return SocketIo;}

private:
	int SocketIo;
	struct sockaddr_in addrCli;
};




#endif