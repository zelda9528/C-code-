LFAG=-L/usr/lib64/mysql -lmysqlclient -ljsoncpp -lpthread
main:main.cpp db.hpp
	g++ -std=c++11 -g $^ -o $@ $(LFAG)
