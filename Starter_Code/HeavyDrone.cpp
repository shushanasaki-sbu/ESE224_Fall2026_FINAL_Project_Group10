// HeavyDrone.cpp
// ESE 224 Fall 2026 Final Project (Part II) starter code
// Team members: Katie Ni

#include "HeavyDrone.h"
#include <iostream>
using namespace std;

HeavyDrone::HeavyDrone() : DeliveryUnit() {}

HeavyDrone::HeavyDrone(const string& n, int id, const string& m, double b, double p, int x, int y, const string& s)
    : DeliveryUnit()
{
    setName(n);
    setID(id);
    setModel(m);
    setBattery(b);
    setMaxPayload(p);
    setPosition(0, x);
    setPosition(1, y);
    setStatus(s);
}

bool HeavyDrone::setModel(const string& m)
{
    if (m == "Hauler") {
        model = m;
        return true;
    }
    else
        return false;
}

double HeavyDrone::batteryNeeded(int x, int y, double weight) const
{
    return distanceTo(x, y) * HEAVY_BATTERY_PER_UNIT * (1 + HEAVY_PAYLOAD_FACTOR * weight);
}

string HeavyDrone::type() const { return "Heavy"; }
