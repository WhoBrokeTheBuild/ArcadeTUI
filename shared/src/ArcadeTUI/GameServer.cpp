#include "GameServer.hpp"

GameServer::~GameServer()
{
    for (socket_t s : m_Clients) {
        close(s);
    }
}

void GameServer::AddClient(socket_t client)
{
    m_Clients.push_back(client);
}

