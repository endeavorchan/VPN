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

void Server::ConfigureEpoll(int epollFd, SockEvent* sockevent, int op, struct epoll_event* pev)
{
    int r = epoll_ctl(epollFd, op, sockevent->selfstreamsock, pev);
    if (r != 0)
    {
        // report error
    }
}

void Server::RegisterEpollEvent(int epollFd, SockEvent* sockevent, struct epoll_event *pev)
{
    pev->data.ptr = sockevent;
    ConfigureEpoll(epollFd, sockevent, EPOLL_CTL_ADD, pev);
}

void Server::InitSockEvent(SockEvent* sockevent, SockState state, SockRole role, int sockfd)
{
    sockevent->state = state;
    sockevent->role = role;
    sockevent->selfstreamsock = sockfd;
    sockevent->send_buffer = nullptr; 
}

void Server::EventLoop()
{
    int efd = epoll_create(1);    

}



