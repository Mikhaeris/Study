#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "../../Header Files/Models/Order.h"

Order saveOrder(Order);

Order getOrderById(int);

void updateOrder(Order);

void deleteOrderById(int);

bool checkByIdOrderInDataBase(int);

int getLastOrderId();

#endif