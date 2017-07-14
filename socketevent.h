/*************************************************************************
	> File Name: socketevent.h
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jul 2017 08:04:49 PM UTC
 ************************************************************************/

#pragma once
constexpr BufferLen = 1024;
enum SockState
{
    SockListening = 1,
    SockConnecting,
    SockConnected
};

enum SockRole
{
    SockDownStream = 1,
    SockUpStream
};

struct Buffer
{
    char buffer[BufferLen];
    int datasize;
};

struct SockEvent
{
    SockState state;
    SockRole role; 
    union 
    {
        int upstreamsock;
        int downstreamsock;
    } u;

    std::vector<Buffer *> *send_buffer;
    std::vector<Buffer *> recv_buffer; 
};
