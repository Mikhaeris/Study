#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include "../../Header Files/Models/Client.h"

Client saveClient(Client);

Client getClientById(int);

Client getClientByClientName(std::string);

void updateClient(Client);

void deleteClientById(int);

bool checkByIdClientInDataBase(int);

void deleteClientByClientName(std::string);

bool checkByClientNameClientInDataBase(std::string);

int getLastClientId();

#endif