#ifndef CLIENTSERVICE_H
#define CLIENTSERVICE_H

#include "../../Header Files/Models/Client.h"

Client createClientService(Client);

Client getClientService(int);

Client getClientService(std::string);

void updateClientService(Client);

void deleteClientService(int);

void deleteClientService(std::string);

#endif