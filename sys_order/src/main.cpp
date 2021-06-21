#include"db.hpp"
#include"httplib.h"

#define WWWROOT "./wwwroot"

using namespace httplib;

order_sys::TableDish *tb_dish=NULL;
order_sys::TableOrder *tb_order=NULL;

void DishInsert(const Request &req,Response & rsp){
  //业务处理
  //  1.解析正文（json反序列化），得到菜品信息
  Json::Value dish;
  Json::Reader reader;
  bool ret=reader.parse(req.body,dish);
  if(ret==false){
    rsp.status=400;
    Json::Value reason;
    Json::FastWriter writer;
    reason["result"]=false;
    reason["reason"]="dish info parse failed!";
    rsp.body=writer.write(reason);
    rsp.set_header("Content-Type","application/json");
    std::cout<<"insert- parse dish error\n";
    return ;
  }
  //  2.将菜品信息插入数据库
  ret=tb_dish->Insert(dish);
  if(ret==false){
    Json::Value reason;
    Json::FastWriter writer;
    reason["result"]=false;
    reason["reason"]="mysql insert failed!";
    rsp.body=writer.write(reason);
    rsp.set_header("Content-Type","application/json");
    std::cout<<"mysql insert dish error\n";
    return ;
  }
  //填充响应信息
  rsp.status=200;
  return ;
}
void DishDelete(const Request &req,Response & rsp){
  //1.获取要删除的菜品id   /dish/id
  int dish_id=std::stoi(req.matches[1]);
  //2.数据库的删除操作
  bool ret=tb_dish->Delete(dish_id);
  if(ret==false){
    std::cout<<"mysql delete dish error\n";
    rsp.status=500;
    return ;
  }
  return ;
}
void DishUpdate(const Request &req,Response & rsp){
  int dish_id=std::stoi(req.matches[1]);
  Json::Value dish;
  Json::Reader reader;
  bool ret=reader.parse(req.body,dish);
  if(ret==false){
    rsp.status=400;
    std::cout<<"update- parse dish  failed!\n";
    return ;
  }
  dish["id"]=dish_id;
  ret=tb_dish->Update(dish);
  if(ret==false){
    rsp.status=500;
    std::cout<<"mysql update dish  error!\n";
    return ;
  }
  return ;
}
void DishGetAll(const Request &req,Response & rsp){
  Json::Value dishes;
  bool ret=tb_dish->SelectAll(&dishes);
  if(ret==false){
    rsp.status=500;
    std::cout<<" mysql selectall dish error!\n";
    return ;
  }
  Json::FastWriter writer;
  rsp.body=writer.write(dishes);
  return ;
}
void DishGetOne(const Request &req,Response & rsp){
  Json::Value dish;
  int dish_id=std::stoi(req.matches[1]);
  bool ret=tb_dish->SelectOne(dish_id,&dish);
  if(ret==false){
    rsp.status=500;
    std::cout<<" mysql selectone dish error!\n";
    return ;
  }
  Json::FastWriter writer;
  rsp.body=writer.write(dish);
  return ;
}

void OrderInsert(const Request &req,Response & rsp){
  Json::Value order;
  Json::Reader reader;
  bool ret=reader.parse(req.body,order);
  if(ret==false){
    std::cout<<"insert- parse order failed!\n";
    rsp.status=400;
    return ;
  }
  ret=tb_order->Insert(order);
  if(ret==false){
    rsp.status=500;
    std::cout<<"mysql insert order error!\n";
    return ;
  }
  return ;
}
void OrderDelete(const Request &req,Response & rsp){
  int order_id=std::stoi(req.matches[1]);
  bool ret=tb_order->Delete(order_id);
  if(ret==false){
    rsp.status=500;
    std::cout<<"mysql delete order error!\n";
    return ;
  }
  return ;
}
void OrderUpdate(const Request &req,Response & rsp){
  int order_id=std::stoi(req.matches[1]);
  Json::Value order;
  Json::Reader reader;
  bool ret=reader.parse(req.body,order);
  if(ret==false){
    rsp.status=400;
    std::cout<<"update- parse order  failed!\n";
    return ;
  }
  order["id"]=order_id;
  ret=tb_order->Update(order);
  if(ret==false){
    rsp.status=500;
    std::cout<<"mysql update order error!\n";
    return ;
  }
  return ;
}

void OrderGetAll(const Request &req,Response & rsp){
  Json::Value orders;
  bool ret=tb_order->SelectAll(&orders);
  if(ret==false){
    rsp.status=500;
    std::cout<<" mysql selectall order error!\n";
    return ;
  }
  Json::FastWriter writer;
  rsp.body=writer.write(orders);
  return ;

}
void OrderGetOne(const Request &req,Response & rsp){
  int order_id=std::stoi(req.matches[1]);
  Json::Value orders;
  bool ret=tb_order->SelectOne(order_id,&orders);
  if(ret==false){
    rsp.status=500;
    std::cout<<" mysql selectall order error!\n";
    return ;
  }
  Json::FastWriter writer;
  rsp.body=writer.write(orders);
  return ;
}

int main()
{
  Server server;

  server.set_base_dir(WWWROOT);
  
  tb_dish=new order_sys::TableDish();
  tb_order=new order_sys::TableOrder();

  //正则表达式：(\d+)表示匹配一个数字字符，一次或多次
  //R"()" 表示括号中的字符串去除特殊含义，即不需要转义
  server.Post("/dish",DishInsert);
  server.Delete(R"(/dish/(\d+))",DishDelete);
  server.Put(R"(/dish/(\d+))",DishUpdate);
  server.Get(R"(/dish)",DishGetAll);
  server.Get(R"(/dish/(\d+))",DishGetOne);
  
  server.Post("/order",OrderInsert);
  server.Delete(R"(/order/(\d+))",OrderDelete);
  server.Put(R"(/order/(\d+))",OrderUpdate);
  server.Get(R"(/order)",OrderGetAll);
  server.Get(R"(/order/(\d+))",OrderGetOne);

  server.listen("0.0.0.0",9000); 
  return 0;
}














void dish_test(){
  //实例化一个菜品类对象
  order_sys::TableDish dish;
  
  Json::Value val;
  val["id"]=3;
  val["name"]="宫保鸡丁";
  val["price"]=1900;

  //dish.Insert(val);
  //dish.Update(val);
  dish.Delete(3);
}
void dish_test2(){
  order_sys::TableDish dish;
  Json::Value val;
  Json::StyledWriter writer;
  //dish.SelectAll(&val);
  dish.SelectOne(2,&val);
  std::cout<<writer.write(val)<<std::endl;
}

void order_test(){
  order_sys::TableOrder order;

  Json::Value val;
  val["id"]=3;
  val["dishes"].append(1);
  val["status"]=1;
  //order.Insert(val);
  order.Update(val);
}

void order_test2(){

  order_sys::TableOrder order;

  Json::Value val;
  Json::StyledWriter writer;
  //order.SelectAll(&val);
  order.SelectOne(1,&val);
  std::cout<<writer.write(val)<<std::endl;
}

