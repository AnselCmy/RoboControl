//
// Created by robocup on 17-9-9.
//
#include <string>
#include "MsgParse.h"
#include "PIDController.h"
using namespace std;

#ifndef NEWROBOTS_ACT_H
#define NEWROBOTS_ACT_H


class ACT {
public:
    static ACT& Instance() {
        if (instance_ == NULL) {
            instance_ = new ACT;
        }
        return *instance_;
    }
    MsgParse msgParse;
    PIDController pidController[22];
    void InitPIDController();
    float Handle(JointID jointID, float targetAng);

private:
    ACT();
    ~ACT();
    static ACT* instance_;
};


#endif //NEWROBOTS_ACT_H
