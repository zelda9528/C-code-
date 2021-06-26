#include"httplib.h"
void hello(const httplib::Request &req,httplib::Response &rsp){
  std::cout<<req.method<<std::endl;
  std::cout<<req.path<<std::endl;
  std::cout<<req.body<<std::endl;
  auto it=req.headers.begin();

  while(it!=req.headers.end()){
    std::cout<< it->first<<"="<<it->second<<std::endl;
    it++;
  }
  it=req.params.begin();
  while(it!=req.params.end()){
    std::cout<< it->first<<"="<<it->second<<std::endl;
    it++;
  }
  rsp.status=200;
  rsp.body="<html><body><h1>hello world</h1></body></html>";
  rsp.set_header("Content-Type","text/html");
  return ;
}

int main(){
  
  httplib::Server srv;
  
  srv.Get("/hello",hello);
  srv.set_base_dir("./wwwroot");
  srv.listen("0.0.0.0",9000);
  return 0;
}
