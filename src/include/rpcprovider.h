#pragma once
#include "google/protobuf/service.h"

// 框架提供的专门服务发布rpc服务的网络对象类
class RpcProvider
{
public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    // 用户自定义的任何一个service的基类都是google::protobuf::Service，
    // 因此我们应该使用基类指针，这样就可以接收任意的service了
    void NotifyService(google::protobuf::Service *service);

    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();
};