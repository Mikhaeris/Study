#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "../../Header Files/Models/Order.h"

Order createOrderService(Order);

Order getOrderByIdService(int);

void updateOrderService(Order);

void deleteOrderService(int);

#endif