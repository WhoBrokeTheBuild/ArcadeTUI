#include "ArcadeServer.hpp"

ArcadeServer::ArcadeServer(Args args)
{

}

ArcadeServer::~ArcadeServer()
{
    for (auto it : m_Servers) {
        delete it.second;
    }
}

void ArcadeServer::Run()
{

}

void ArcadeServer::AddGameServer(const string& name, GameServer* srv)
{
    m_Servers.emplace(name, srv);
}
