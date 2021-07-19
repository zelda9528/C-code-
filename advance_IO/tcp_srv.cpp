#include "tcpsocket.hpp"
#include "select.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: ./tcp_src 192.168.2.2 9000\n");
        return -1;
    }
    bool ret;
    std::string srvip = argv[1];
    uint16_t srvport = std::stoi(argv[2]);
    TcpSocket lst_sock;//监听套接字
    CHECK_RET(lst_sock.Socket());
    lst_sock.SetSocketOpt();
    CHECK_RET(lst_sock.Bind(srvip, srvport));
    CHECK_RET(lst_sock.Listen());
    Select s;
    s.Add(lst_sock);
    while(1) {
        std::vector<TcpSocket> arry;
        ret = s.Wait(&arry);
        if (ret == false) {
            return false;
        }
        for (int i = 0; i < arry.size(); i++) {
            if (arry[i].GetFd() == lst_sock.GetFd()){
                TcpSocket clisock;
                std::string ip;
                uint16_t port;
                ret=lst_sock.Accept(&clisock,&ip,&port);
                if (ret == false) {
                    continue;
                }
                std::cout<<"conn:"<<ip<<"-"<<port<<"\n";
                s.Add(clisock);
            }else {
                std::string buf;
                ret = arry[i].Recv(&buf);
                if (ret == false) {
                    s.Del(arry[i]);
                    arry[i].Close();
                    continue;
                }
                std::cout<<"client say: "<<buf<<std::endl;
                buf.clear();
                std::cout << "server say: ";
                std::cin >> buf;
                ret = arry[i].Send(buf);
                if (ret == false) {
                    s.Del(arry[i]);
                    arry[i].Close();
                }
            }
        }
    }
    lst_sock.Close();
}
