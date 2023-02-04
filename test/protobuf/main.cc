#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;

int main()
{
    LoginResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(1);
    rc->set_errmsg("登录处理失败了！");

    GetFriendListsResponse rsp2;
    ResultCode *rc2 = rsp2.mutable_result();
    rc2->set_errcode(0);

    User *user1 = rsp2.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp2.add_friend_list();
    user2->set_name("zhang xu");
    user2->set_age(24);
    user2->set_sex(User::MAN);

    std::cout << rsp2.friend_list_size() << std::endl;

    // 遍历列表
    for (int i = 0; i < rsp2.friend_list_size(); i++)
    {
        User cur = rsp2.friend_list(i);
        std::cout << "User " << i << " : " << cur.name() << " " << cur.age() << " " << cur.sex() << std::endl;
    }

    return 0;
}

int main1()
{
    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 -> string
    std::string send_str;
    if (req.SerializeToString(&send_str))
    {
        std::cout << send_str << std::endl;
    }

    // 从send_str反序列化出一个login请求对象
    LoginRequest reqB;
    if (reqB.ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}