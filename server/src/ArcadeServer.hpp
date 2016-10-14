#ifndef ARCADE_SERVER_HPP
#define ARCADE_SERVER_HPP

#include <unordered_map>
#include <cstdio>

#include <ArcadeTUI/Types.hpp>
#include <ArcadeTUI/GameServer.hpp>
#include "Args.hpp"

class ArcadeServer
{
public:

    ArcadeServer(Args args);
    ~ArcadeServer();

    void Run();
    void AddGameServer(const string& name, GameServer* srv);

protected:

    std::unordered_map<string, GameServer*> m_Servers;

};

#endif // ARCADE_SERVER_HPP
