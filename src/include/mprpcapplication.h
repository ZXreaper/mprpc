#pragma once

#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

// mprpc框架的基础类,负责框架的一些初始化操作  设计成单例模式
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication &GetInstance();
    static MprpcConfig &GetConfig();

private:
    static MprpcConfig m_config;

    MprpcApplication() {}
    MprpcApplication(const MprpcApplication &) = delete; // 设计成单例模式，因此和拷贝相关的函数都删掉
    MprpcApplication(MprpcApplication &&) = delete;      // 设计成单例模式，因此和拷贝相关的函数都删掉
};