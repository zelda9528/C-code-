all: tcp_cli process_srv
process_srv:process_srv.cpp
	g++ -std=c++11 -g $^ -o $@ -lpthread
thread_srv:thread_srv.cpp
	g++ -std=c++11 -g $^ -o $@ -lpthread
tcp_cli:tcp_cli.cpp
	g++ -std=c++11 -g $^ -o $@
tcp_srv:tcp_srv.cpp
	g++ -std=c++11 -g $^ -o $@
udp_srv:udp_srv.c
	gcc -g $^ -o $@
udp_cli:udp_cli.cpp
	g++ -g $^ -o $@
