/*************************************************************************
	> File Name: server.h
	> Author: 
	> Mail: 
	> Created Time: Thu 29 Jun 2017 06:20:16 PM UTC
 ************************************************************************/
#pragma once

class Server
{
public:
    Server();

    // Create a server and listen on the paticular port
    //
    Server(const char* hostname, int port);

    void EventLoop();

private:

    int m_listenfd;
    // int m_port;
    // std::string m_hostname; 
    Address m_addr;
};
