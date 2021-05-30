#include "tcpsocket.hpp"

int main(int argc, char *argv[])
{
    //通过参数传入要连接的服务端的地址信息
    if (argc != 3) {
        printf("usage: ./tcp_cli srvip srvport\n");
        return -1;
    }
    std::string srvip = argv[1];
    uint16_t srvport = std::stoi(argv[2]);

    TcpSocket cli_sock;
    //1. 创建套接字
    CHECK_RET(cli_sock.Socket());
    //2. 绑定地址信息（不推荐）
    //3. 向服务端发起连接
    CHECK_RET(cli_sock.Connect(srvip, srvport));
    while(1) {
        //4. 收发数据
        std::string buf;
        std::cout << "client say: ";
        std::cin >> buf;
        CHECK_RET(cli_sock.Send(buf));

        buf.clear();
        CHECK_RET(cli_sock.Recv(&buf));
        std::cout << "server say: " << buf << std::endl;
    }
    //5. 关闭套接字
    CHECK_RET(cli_sock.Close());
    return 0;
}
