// Drone.cpp
// ESE 224 Fall 2026 Final Project (Part II) starter code
// Team members: Katie Ni

#include "Drone.h"
#include <iostream>
using namespace std;

Drone::Drone() : DeliveryUnit() {}

Drone::Drone(const string& n, int id, const string& m, double b, double p, int x, int y, const string& s)
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

bool Drone::setModel(const string& m)
{
    // TODO: valid when m is Kestrel, Falcon, or Condor
    if (m == "Kestrel" || m == "Falcon" || m == "Condor") {
        model = m;
        return true;
    }
    else
        return false;
}

double Drone::batteryNeeded(int x, int y, double weight) const
{
    return distanceTo(x, y) * BATTERY_PER_UNIT * (1 + PAYLOAD_FACTOR * weight);
}

string Drone::type() const { return "Drone"; }
