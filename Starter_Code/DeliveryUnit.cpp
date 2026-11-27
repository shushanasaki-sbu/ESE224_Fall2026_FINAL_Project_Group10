// DeliveryUnit.cpp
// ESE 224 Fall 2026 Final Project (Part II) starter code
// Team members: Katie Ni
//
// Much of this is your Part I Drone code, moved into the base class (Section 3.2).

#include "DeliveryUnit.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

DeliveryUnit::DeliveryUnit()
{
    name = "";
    ID = -1;
    model = "";
    battery = 100.0;
    maxPayload = 0.0;
    position[0] = 0;
    position[1] = 0;
    status = "IDLE";
    deliveriesCompleted = 0;
}

DeliveryUnit::~DeliveryUnit() {}

// ---------- Accessors ----------
string DeliveryUnit::getName() const { return name; }
int DeliveryUnit::getID() const { return ID; }
string DeliveryUnit::getModel() const { return model; }
double DeliveryUnit::getBattery() const { return battery; }
double DeliveryUnit::getMaxPayload() const { return maxPayload; }
string DeliveryUnit::getStatus() const { return status; }
int DeliveryUnit::getDeliveriesCompleted() const { return deliveriesCompleted; }

int DeliveryUnit::getPosition(int index) const
{
    //valid only if index is 0 or 1, otherwise return -1
    if (index == 0 || index == 1)
        return position[index];
    else
        return -1;
}

// ---------- Mutators (validate as in Part I; setMaxPayload: 0 < p <= MAX_PAYLOAD_LIMIT) ----------
void DeliveryUnit::setName(const string& n) { 
    name = n; 
}
bool DeliveryUnit::setID(int id) { 
    if (id > 0) {
        ID = id;
        return true;
    }
    else
        return false; 
}
bool DeliveryUnit::setBattery(double b) { 
    if (b >= 0 && b<= 100) {
        battery = b;
        return true;
    }
    else
        return false; 
}
bool DeliveryUnit::setMaxPayload(double p) { 
    if (p > 0 && p <= MAX_PAYLOAD_LIMIT) {
        maxPayload = p;
        return true;
    }
    else
        return false; 
}
bool DeliveryUnit::setPosition(int index, int value) { 
    if ((index == 0 || index == 1) && value >= 0) {
        position[index] = value;
        return true;
    }
    else
        return false; 
}
bool DeliveryUnit::setStatus(const string& s) { 
     if (s == "IDLE" || s == "CHARGING" || s == "MAINTENANCE") {
        status = s;
        return true;
    }
    else
        return false; 
}

// ---------- Shared behaviour ----------
double DeliveryUnit::distanceTo(int x, int y) const
{
    return sqrt(pow(x - position[0], 2) + pow(y - position[1], 2));
}

bool DeliveryUnit::canDeliver(int x, int y, double weight) const
{
    return (status == "IDLE" && weight <= maxPayload && (battery - batteryNeeded(x, y, weight)) >= SAFETY_RESERVE);
}

void DeliveryUnit::completeDelivery(int x, int y, double weight)
{
    battery -= batteryNeeded(x, y, weight);
    setPosition(0, x);
    setPosition(1, y);
    deliveriesCompleted++;
    if (battery < LOW_BATTERY)
        status = "CHARGING";
}

void DeliveryUnit::undoDelivery(double oldBattery, int oldX, int oldY, const string& oldStatus)
{
    battery = oldBattery;
    setPosition(0, oldX);
    setPosition(1, oldY);
    status = oldStatus;
    if (deliveriesCompleted > 0)
        deliveriesCompleted--;
}

void DeliveryUnit::display() const
{
    cout << "[Type] " << type() << endl;
    cout << "[Name] " << name << endl;
    cout << "[ID] " << ID << endl;
    cout << "[Model] " << model << endl;
    cout << "[Battery] " << battery << endl;
    cout << "[Max Payload] " << maxPayload << endl;
    cout << "[Position] (" << position[0] << ", " << position[1] << ")" << endl;
    cout << "[Status] " << status << endl;
    cout << "[Deliveries Completed] " << deliveriesCompleted << endl;
}
