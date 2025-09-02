#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <string>

struct Client {
	int id;
	std::string clientName;
	std::string firstName;
	std::string lastName;
	int dateOfBirth[3];
	std::vector<int> orderHistory;
};

#endif