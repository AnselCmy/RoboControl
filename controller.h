#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <csignal>
#include <sstream>
#include "Connection.h"
#include "ACT.h"
#include <queue>
#include <vector>

using namespace std;

struct Action
{
    JointID jointID;
    float targetAng;
};

class Controller
{
public:
    Controller();
    vector<Action> actionQueue;
    void ControlInit();
    void Run();
    void ActHandle(JointID jointID, float targetAng);
    void QueueAction(JointID JointID, float targerAng);
    void ActQueue();
//    void ActAll();
    bool AllBeTarget();
};

#endif // CONTROLLER_H
