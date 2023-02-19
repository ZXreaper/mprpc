#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"
#include "mprpcchannel.h"

int main(int argc, char **argv)
{
    // 整个程序启动以后，想使用mprpc框架来享受rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
    MprpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
    fixbug::GetFriendListRequest request;
    // rpc请求参数
    request.set_userid(1000);
    // rpc方法的响应
    fixbug::GetFriendListResponse response;
    // 发起rpc方法的调用   同步的rpc调用过程  MprpcChannel::callmethod
    stub.GetFriendList(nullptr, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送

    // 一次rpc调用完成，读调用的结果
    if (response.result().errcode() == 0)
    {
        std::cout << "rpc getfriendlist response success : " << std::endl;
        int size = response.friends_size();
        for (int i = 0; i < size; i++)
        {
            std::cout << "index : " << (i + 1) << " name : " << response.friends(i) << std::endl;
        }
    }
    else
    {
        std::cout << "rpc getfriendlist response error : " << response.result().errmsg() << std::endl;
    }

    return 0;
}