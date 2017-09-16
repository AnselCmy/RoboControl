//
// Created by robocup on 17-9-8.
//

#include <cstring>
#include <zconf.h>
#include "Connection.h"


Connection::Connection() {
    HostIp = "127.0.0.1";
    HostPort = 3100;

}

Connection::~Connection() {

}

bool Connection::connect2Server() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        return false;
    }
    sock_addr.sin_addr.s_addr = inet_addr((const char*) HostIp.c_str());
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(HostPort);
    int connectResult = connect(socket_fd, (sockaddr*)&sock_addr, sizeof(sockaddr_in));
    if (connectResult < 0) {
        cout << "connect failed" <<endl;
        return false;
    }
    cout << "connected" <<endl;
    return true;
}

bool Connection::sendMsg(string &msg) {
    ssize_t iSendResult = -1;
    unsigned long len = htonl(msg.size());
    string prefix((const char*)&len,sizeof(unsigned int));
    string str = prefix + msg;

    iSendResult = send(socket_fd ,str.data() ,str.size() , 0);
    if (iSendResult <= 0)
    {
        cout<<"sendMessage failed"<<endl;
        return false;
    }
    return true;

}

bool Connection::ReceiveMsg ()
{
    unsigned int bytesRead = 0;
    ssize_t readResult = -1;
    // get the msg 's length
    memset(mBuffer, '\0', sizeof(mBuffer));
    unsigned int iLen = sizeof(unsigned int);
    while(bytesRead < iLen)
    {
        if (!SelectInput())
        {
            return false;
        }
        readResult = read(socket_fd, mBuffer + bytesRead, iLen - bytesRead);
        if(readResult <= 0)
        {
            cout <<" ReadCError! "<<endl;
            return false;
        }        // by this way ,it can not exit normally when the server shutdown first.
        bytesRead += readResult;
    }
    // msg is prefixed with it's total length
    unsigned int iMsgLen = ntohl(*(unsigned int*)mBuffer);
    if(iLen + iMsgLen > sizeof(mBuffer))
    {
        cout << "too long message; aborting" << endl;
        return false;
    }
    unsigned int msgRead = bytesRead - iLen;
    char *offset = mBuffer + bytesRead;
    readResult = -1;
    int readLen = 0;
    while (msgRead < iMsgLen)
    {
        if (!SelectInput())
        {
            return false;
        }
        readLen = sizeof(mBuffer) - msgRead;
        if(readLen > iMsgLen - msgRead)
            readLen = iMsgLen - msgRead;
        readResult = read(socket_fd, offset, readLen);
        if(readResult < 0)
        {
            cout <<" ReadError! "<<endl;
            return false;
        }
        msgRead += readResult;
        offset += readResult;
    }
    (*offset) = '\0';
    return true;
}



bool Connection::ReceiveMsg(string &sMsg)
{
    bool r = ReceiveMsg();
    if (r)
    {
        sMsg = string(mBuffer + sizeof(unsigned int));
    }
    return r;
}

bool Connection::SelectInput ()
{
    fd_set readfds;
    struct timeval tv = {10,0};
    FD_ZERO(&readfds);
    FD_SET(socket_fd,&readfds);

    while(1)
    {
        switch(select(socket_fd+1,&readfds, 0, 0, &tv)) {
            case 1:
                return true;
            case 0:
                cout << "(SelectInput) select failed " << strerror(errno) << endl;
                return false;
            default:
                if(errno == EINTR)
                    continue;
                cout << "(SelectInput) select failed " << strerror(errno) << endl;
                return false;
        }
    }
}