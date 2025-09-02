#ifndef DRIVERREPOSITORY_H
#define DRIVERREPOSITORY_H

Driver saveDriver(Driver);

Driver getDriverById(int);

Driver getDriverByDriverName(std::string);

void updateDriver(Driver);

void deleteDriverById(int);

bool checkByIdDriverInDataBase(int);

bool checkByDriverNameInDataBase(std::string);

int getLastDriverId();

#endif