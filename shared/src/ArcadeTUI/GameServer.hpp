#ifndef GAME_SERVER_HPP
#define GAME_SERVER_HPP

#include "Types.hpp"
#include <cstdio>
#include <unistd.h>
#include <vector>

class GameServer
{
public:

    GameServer() = default;
    virtual ~GameServer();

    virtual void Run() = 0;
    virtual void AddClient(socket_t client);

protected:

    std::vector<socket_t> m_Clients;

};

#endif // GAME_SERVER_HPP
