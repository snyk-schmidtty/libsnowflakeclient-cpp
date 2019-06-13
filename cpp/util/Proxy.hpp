/*
 * Copyright (c) 2018-2019 Snowflake Computing, Inc. All rights reserved.
 */

#ifndef SNOWFLAKECLIENT_PROXY_HPP
#define SNOWFLAKECLIENT_PROXY_HPP

#include <cstddef>
#include <cstdlib>
#include <string>

namespace Snowflake
{
namespace Client
{
namespace Util
{
class Proxy
{
public:
    enum Protocol {NONE, HTTP, HTTPS};

    Proxy() = default;

    Proxy(const std::string &proxy_str);

    Proxy(std::string &user, std::string &pwd, std::string &machine, unsigned port, Protocol scheme);

    ~Proxy() = default;

    inline const std::string& getUser()
    {
        return this->m_user;
    }

    inline const std::string& getPwd()
    {
        return this->m_pwd;
    }

    inline const std::string& getMachine()
    {
        return this->m_machine;
    }

    inline unsigned getPort()
    {
        return this->m_port;
    }

    inline Protocol getScheme()
    {
        return this->m_protocol;
    }

    void clearPwd();

    void setProxyFromEnv();

private:
    std::string m_user;
    std::string m_pwd;
    std::string m_machine;
    unsigned m_port = 0;
    Protocol m_protocol = Protocol::NONE;

    void stringToProxyParts(const std::string &proxy);
};
}
}
}

#endif //SNOWFLAKECLIENT_PROXY_HPP
