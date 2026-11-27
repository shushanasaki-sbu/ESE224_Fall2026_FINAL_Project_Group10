// Order.h
// By: Shushana

#ifndef ORDER_H
#define ORDER_H
#include <string>

// Incoming delivery request
struct Order {
    int orderId;
    int x;
    int y;
    double weight;
};


// Store predelivery unit state
struct DispatchRecord {
    Order order;
    int unitID;
    double oldBattery;
    int oldX;
    int oldY;
    std::string oldStatus;
};

#endif
