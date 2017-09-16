//
// Created by robocup on 17-9-10.
//

#ifndef NEWROBOTS_MSGPARSE_H
#define NEWROBOTS_MSGPARSE_H

#include <iostream>
#include <string>

using namespace std;

enum JointID
{
    JID_HEAD_1 = 0,
    JID_HEAD_2 = 1,

    JID_LARM_1 = 2,
    JID_RARM_1 = 3,
    JID_LARM_2 = 4,
    JID_RARM_2 = 5,
    JID_LARM_3 = 6,
    JID_RARM_3 = 7,
    JID_LARM_4 = 8,
    JID_RARM_4 = 9,

    JID_LLEG_1 = 10,
    JID_RLEG_1 = 11,
    JID_LLEG_2 = 12,
    JID_RLEG_2 = 13,
    JID_LLEG_3 = 14,
    JID_RLEG_3 = 15,
    JID_LLEG_4 = 16,
    JID_RLEG_4 = 17,
    JID_LLEG_5 = 18,
    JID_RLEG_5 = 19,
    JID_LLEG_6 = 20,
    JID_RLEG_6 = 21,
    JID_ROOT = 22,
    JID_NULL = 23,
    JID_UNKNOW = 24
};

struct HJInfo
{
    int ID;
    string sPerceptorName;
    string sEffectorName;
    double fAngle;
    double fAngleRate;
    double dTime;
    HJInfo() : ID(JID_UNKNOW), sPerceptorName(""), sEffectorName(""), fAngle(0), fAngleRate(0), dTime(0) {}
};

class MsgParse {
public:
    MsgParse();
    ~MsgParse();
    void Parse(string sMsg);
    string m_sMsg;
    HJInfo m_HJ[22];

private:
    void InitJoint();
    bool IsIncludeInNum(char c);
    bool IsNum(char c);
    bool IsNumHead(char c);
    double StringToFloat(string sNum);
    bool ParseHJ(string sEff,HJInfo &HJResult);
    double GetFloat(string sMsg,int &iStartPos,int &iEndPos);
};


#endif //NEWROBOTS_MSGPARSE_H
