/*************************************************************************
	> File Name: Address.h
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2017 05:38:06 PM UTC
 ************************************************************************/

#pragma once

class Address
{
public:

    struct addrinfo* GetAddrInfo();

    Address();

    Address(const char* address, int port);

    ~Address();

private:
    void SetAddrInfo(const char* address, int port);

    struct addrinfo* m_addrinfo;
};
