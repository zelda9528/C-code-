#include<iostream>
#include<jsoncpp/json/json.h>
#include<string>

std::string seria()
{
  const char* name="张三";
  int id=10001;
  const char* sex="男";
  int score[3]={88,77,99};

  Json::Value val;
  val["姓名"]=name;
  val["学号"]=id;
  val["性别"]=sex;
  for(int i=0;i<3;i++){
    val["成绩"].append(score[i]);
  }

  
  Json::FastWriter writer;
  std::string str=writer.write(val);
  std::cout<<str<<std::endl;
  return str;
}

void unsreia(std::string &str)
{
  Json::Value val;
  Json::Reader reader;
  bool ret=reader.parse(str,val);
  if(ret==false){
    std::cout<<"parse json failed!\n";
    return ;
  }
  std::cout<<val["姓名"].asString()<<std::endl;
  std::cout<<val["性别"].asString()<<std::endl;
  std::cout<<val["学号"].asInt()<<std::endl;
  int num=val["成绩"].size();
  for(int i=0;i<num;i++){
    std::cout<<val["成绩"][i].asInt()<<std::endl;
  }

  return;

}
int main()
{
  std::string str=seria();
  unsreia(str);

  std::cout<<str<<std::endl;
  return 0;
}

