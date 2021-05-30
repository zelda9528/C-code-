#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define CHECK_RET(q) if((q)==false){return -1;}
#define LISTEN_BACKLOG 5

struct data_t{
    int num1;
    int num2;
    char op;
};
class TcpSocket{
    private:
        int _sockfd;
    public:
        TcpSocket():_sockfd(-1){}
        int GetFd() {
            return _sockfd;
        }
        void SetFd(int fd){
            _sockfd = fd;
        }
        bool Socket() {
            _sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
            if (_sockfd < 0) {
                perror("socket error");
                return false;
            }
            return true;
        }
        bool Bind(const std::string &ip, const uint16_t port){
            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(&ip[0]);
            socklen_t len = sizeof(sockaddr_in);
            int ret = bind(_sockfd, (sockaddr*)&addr, len);
            if (ret < 0) {
                perror("bind error");
                return false;
            }
            return true;
        }
        bool Listen(int backlog = LISTEN_BACKLOG) {
            //listen(描述符，同一时间连接数)
            int ret = listen(_sockfd, backlog);
            if (ret < 0) {
                perror("listen error");
                return false;
            }
            return true;
        }
        bool Connect(const std::string &ip,const int port) {
            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(&ip[0]);
            socklen_t len = sizeof(sockaddr_in);
            //connect(描述符，服务端地址， 地址长度)
            int ret = connect(_sockfd, (sockaddr*)&addr, len);
            if (ret < 0) {
                perror("connect error");
                return false;
            }
            return true;
        }
        bool Accept(TcpSocket *sock, std::string *ip = NULL, 
                uint16_t *port = NULL) {
            //int accept(监听套接字， 回去客户端地址， 长度)
            sockaddr_in addr;
            socklen_t len = sizeof(sockaddr_in);
            int newfd = accept(_sockfd,(sockaddr*)&addr,&len);
            if (newfd < 0) {
                perror("accept error");
                return false;
            }
            sock->_sockfd = newfd;
            if (ip != NULL) {
                *ip = inet_ntoa(addr.sin_addr);
            }
            if (port != NULL) {
                *port = ntohs(addr.sin_port);
            }
            return true;
        }
        bool Recv(std::string *buf) {
            //int recv(描述符，空间，数据长度，标志位)
            //返回值：实际获取大小， 0-连接断开； -1-出错了
            char tmp[4096] = {0};
            int ret = recv(_sockfd, tmp, 4096, 0);
            if (ret < 0) {
                perror("recv error");
                return false;
            }else if (ret == 0) {
                printf("peer shutdown");
                return false;
            }
            buf->assign(tmp, ret);
            return true;
        }
        bool Send(const std::string &data) {
            //int send(描述符，数据，长度，标志位)
            int total = 0;
            while(total < data.size()) {
                int ret = send(_sockfd, &data[0] + total, 
                        data.size() - total, 0);
                if (ret < 0) {
                    perror("send error");
                    return false;
                }
                total += ret;
            }
            return true;
        }
        bool Close() {
            if (_sockfd != -1) {
                close(_sockfd);
            }
            return true;
        }
};
