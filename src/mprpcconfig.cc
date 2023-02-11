#include "mprpcconfig.h"

#include <iostream>
#include <string>

// 负责解析加载配置文件
void MprpcConfig::LoadConfigFile(const char *config_file)
{
    FILE *pf = fopen(config_file, "r");
    if (pf == nullptr)
    {
        std::cout << config_file << " is not exist!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 需要处理 1.注释  2.正确的配置项 =  3.去掉开头的多余的空格
    while (!feof(pf))
    {
        char buf[512] = {0};
        fgets(buf, 512, pf);

        std::string read_buf(buf);
        // 去掉字符串前后多余的空格
        Trim(read_buf);

        // 判断#的注释
        if (read_buf[0] == '#' || read_buf.empty())
        {
            continue;
        }

        // 解析配置项
        int idx = read_buf.find('=');
        if (idx == -1)
        {
            // 配置项不合法
            continue;
        }

        std::string key;
        std::string value;
        key = read_buf.substr(0, idx);
        Trim(key);

        // 因为每一行的末尾可能存在回车到有效字符之前有很多的空格，回车后面是/000填充的，我们不需要，因此我们先找到回车的位置
        int endidx = read_buf.find('\n', idx);
        if (endidx != -1)
        {
            value = read_buf.substr(idx + 1, endidx - idx - 1);
        }
        else
        {
            value = read_buf.substr(idx + 1, read_buf.size() - idx);
        }
        Trim(value);
        m_configMap.insert({key, value});
    }
}

// 查询配置项信息
std::string MprpcConfig::Load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it == m_configMap.end())
    {
        return "";
    }
    return it->second;
}

// 去掉字符串前后的空格
void MprpcConfig::Trim(std::string &src_buf)
{
    int idx = src_buf.find_first_not_of(' ');
    if (idx != -1)
    {
        // 说明字符串前面有空格
        src_buf = src_buf.substr(idx, src_buf.size() - idx);
    }
    // 去掉字符串后面多余的空格
    idx = src_buf.find_last_not_of(' ');
    if (idx != -1)
    {
        // 说明字符串后面有空格
        src_buf = src_buf.substr(0, idx + 1);
    }
}