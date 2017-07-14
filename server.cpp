/*************************************************************************
	> File Name: server.cpp
	> Author: Chen Chen 
	> Mail: 
	> Created Time: Wed 28 Jun 2017 10:46:53 PM UTC
 ************************************************************************/

#include "vpn.h"

Server::Server():m_addr()
{
}

Server::Server(const char* hostname, int port)::m_addr(hostname, port)
{
    //m_hostname = std::string(hostname);
    //m_port = port;
    struct addrinfo *addr = m_addr.GetAddrInfo();
    m_listenfd= socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);

    bind(m_listenfd, addr->ai_addr, addr->ai_addrlen);
    
    // listen
}

Server::EventLoop()
{

}



