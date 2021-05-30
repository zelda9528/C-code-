#include "tcpsocket.hpp"
#include <signal.h>
#include <sys/wait.h>

void sigcb(int no)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

void worker(TcpSocket &clisock)
{  //child process
    bool ret;
    while(1) {
        //5. 收发数据--使用获取的新建套接字进行通信
        std::string buf;
        ret = clisock.Recv(&buf);
        if (ret == false) {
            clisock.Close();
            exit(0);
        }
        std::cout <<"client say: "<<buf<<std::endl;
        buf.clear();
        std::cout << "server say: ";
        std::cin >> buf;
        ret = clisock.Send(buf);
        if (ret == false) {
            clisock.Close();
            exit(0);
        }
    }
    clisock.Close();//释放的是子进程的clisock
    exit(0);

    return;
}
int main(int argc, char *argv[])
{
    //通过程序运行参数指定服务端要绑定的地址
    // ./tcp_srv 192.168.2.2 9000
    if (argc != 3) {
        printf("usage: ./tcp_src 192.168.2.2 9000\n");
        return -1;
    }
    signal(SIGCHLD, SIG_IGN);
    //signal(SIGCHLD, sigcb);
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
        pid_t pid = fork();
        if (pid < 0) {
            clisock.Close();
            continue;
        }else if (pid == 0) {
            worker(clisock);
        }
        //父子进程数据独有，父进程关闭不会对子进程造成影响
        clisock.Close();//释放的是父进程中的clisock
    }
    //6. 关闭套接字
    lst_sock.Close();
}
