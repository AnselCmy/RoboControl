//
// Created by robocup on 17-9-9.
//

#include "ACT.h"

ACT::ACT()
{
    InitPIDController();
}

ACT::~ACT()
{

}

void ACT::InitPIDController()
{
    pidController[JID_HEAD_1].setParams(0.2, 0, 0);
    pidController[JID_HEAD_2].setParams(0.2, 0, 0);
    pidController[JID_LARM_1].setParams(0.2, 0, 0);
    pidController[JID_RARM_1].setParams(0.2, 0, 0);
    pidController[JID_LARM_2].setParams(0.2, 0, 0);
    pidController[JID_RARM_2].setParams(0.2, 0, 0);
    pidController[JID_LARM_3].setParams(0.2, 0, 0);
    pidController[JID_RARM_3].setParams(0.2, 0, 0);
    pidController[JID_LARM_4].setParams(0.2, 0, 0);
    pidController[JID_RARM_4].setParams(0.2, 0, 0);
    pidController[JID_LLEG_1].setParams(0.2, 0, 0);
    pidController[JID_RLEG_1].setParams(0.2, 0, 0);
    pidController[JID_LLEG_2].setParams(0.2, 0, 0);
    pidController[JID_RLEG_2].setParams(0.2, 0, 0);
    pidController[JID_LLEG_3].setParams(0.2, 0, 0);
    pidController[JID_RLEG_3].setParams(0.2, 0, 0);
    pidController[JID_LLEG_4].setParams(0.2, 0, 0);
    pidController[JID_RLEG_4].setParams(0.2, 0, 0);
    pidController[JID_LLEG_5].setParams(0.2, 0, 0);
    pidController[JID_RLEG_5].setParams(0.2, 0, 0);
    pidController[JID_LLEG_6].setParams(0.2, 0, 0);
    pidController[JID_RLEG_6].setParams(0.2, 0, 0);
}

float ACT::Handle(JointID jointID, float targetAng)
{
    string perceptorName = msgParse.m_HJ[jointID].sPerceptorName;
    float currentAng = (float)msgParse.m_HJ[jointID].fAngle;
    float offset = pidController[jointID].update(currentAng, targetAng);
    return offset;
}
