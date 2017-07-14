/*************************************************************************
	> File Name: Address.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2017 05:42:33 PM UTC
 ************************************************************************/

#include "vpn.h"

Address::Address()
{
    m_addrinfo = nullptr;
}

Address::Address(const char* address, int port)
{
    SetAddrInfo(address, port);
}

void Address::SetAddrInfo(const char* address, int port)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = IPPROTO_TCP;

    int ret;
    std::string s_portno = std::to_string(port);
    if ((ret = getaddrinfo(address, s_portno.c_str(), &hints, &m_addrinfo)) != 0)
    {
        // error out
    }
}

struct addrinfo* Address:GetAddrInfo()
{
    retrun m_addrinfo;
}

Address::~Address()
{
    if (m_addrinfo != nullptr)
    {
        freeaddrinfo(m_addrinfo);
    }
}
