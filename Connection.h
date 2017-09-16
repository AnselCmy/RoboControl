//
// Created by robocup on 17-9-8.
//

#ifndef NEWROBOTS_CONNECTION_H
#define NEWROBOTS_CONNECTION_H


#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
using namespace std;

class Connection {
public:
    static Connection& Instance() {
        if (instance_ == NULL) {
            instance_ = new Connection;
        }
        return *instance_;
    }
    bool connect2Server();
    bool sendMsg(string& s);
    bool ReceiveMsg();
    bool ReceiveMsg(string &sMsg);
    bool SelectInput();

private:
    Connection();
    virtual ~Connection();
    int socket_fd;
    sockaddr_in sock_addr;
    string HostIp;
    uint16_t HostPort;
    char mBuffer [16 * 1024];
    static Connection* instance_;
};


#endif //NEWROBOTS_CONNECTION_H
