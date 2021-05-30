#include "udpsocket.hpp"

#define CHECK_RET(q) if((q)==false){return -1;}
int main()
{
    UdpSocket sock;
    //1. 创建套接字
    CHECK_RET(sock.Socket());
    //2. 绑定地址信息（不推荐）
    while(1) {
        //3. 发送数据
        std::cout << "client say: ";
        std::string buf;
        std::cin >> buf;
        CHECK_RET(sock.Send(buf, "172.17.0.3", 9000));
        //4. 接收数据
        buf.clear();
        CHECK_RET(sock.Recv(&buf));
        std::cout << "server say: " << buf << "\n";
    }
    //5. 关闭套接字
    sock.Close();
    return 0;
}
