#include "tcpsocket.hpp"

int main(int argc, char *argv[])
{
    //通过程序运行参数指定服务端要绑定的地址
    // ./tcp_srv 192.168.2.2 9000
    if (argc != 3) {
        printf("usage: ./tcp_src 192.168.2.2 9000\n");
        return -1;
    }
    std::string srvip = argv[1];
    uint16_t srvport = std::stoi(argv[2]);
    TcpSocket lst_sock;//监听套接字
    //1. 创建套接字
    CHECK_RET(lst_sock.Socket());
    //2. 绑定地址信息
    CHECK_RET(lst_sock.Bind(srvip, srvport));
    //3. 开始监听
    CHECK_RET(lst_sock.Listen());
    while(1) {
        //4. 获取新建连接
        TcpSocket clisock;
        std::string cliip;
        uint16_t cliport;
        bool ret = lst_sock.Accept(&clisock, &cliip,&cliport);
        if (ret == false) {
            continue;
        }
        std::cout<<"get newconn:"<< cliip<<"-"<<cliport<<"\n";
        //5. 收发数据--使用获取的新建套接字进行通信
        int fd = clisock.GetFd();
        struct data_t tmp;
        recv(fd, &tmp, sizeof(struct data_t), 0);

        int result;
        if (tmp.op == '+'){
            result = tmp.num1 + tmp.num2;
        }else {
            result = 100;
        }
        send(fd, &result, sizeof(int), 0);
    }
    //6. 关闭套接字
    lst_sock.Close();
}
