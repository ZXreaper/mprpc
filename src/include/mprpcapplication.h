#pragma once

// mprpc框架的基础类,负责框架的一些初始化操作  设计成单例模式
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication &GetInstance();

private:
    MprpcApplication() {}
    MprpcApplication(const MprpcApplication &) = delete; // 设计成单例模式，因此和拷贝相关的函数都删掉
    MprpcApplication(MprpcApplication &&) = delete;      // 设计成单例模式，因此和拷贝相关的函数都删掉
};