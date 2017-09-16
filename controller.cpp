#include "controller.h"

Controller::Controller()
{

}

void Controller::ControlInit() {
    Connection::Instance().connect2Server();
    string s1 = "(scene rsg/agent/nao/nao_hetero.rsg 0)(syn)";
    Connection::Instance().sendMsg(s1);
    string msg;
    Connection::Instance().ReceiveMsg(msg);
    cout << msg << endl;

    string MsgFromServer;
//    if (!connection.ReceiveMsg(MsgFromServer)) return -1;
    string ss = "(init (unum 2)(teamname Fxxk))(syn)";
    bool r = Connection::Instance().sendMsg(ss);
    cout << r << endl;
    Connection::Instance().ReceiveMsg(ss);
    cout << ss << endl;
    ss = "(beam -5 0 0)(syn)";
    Connection::Instance().sendMsg(ss);
}

void Controller::Run() {
    string ss;
    string send2server="(he1 0)(he2 0)(lae1 0)(lae2 0)(lae3 0)(lae4 0)(rae1 0)(rae2 0)(rae3 0)(rae4 0)(lle1 0)(lle2 0)(lle3 0)(lle4 0)(lle5 0)(lle6 0)(rle1 0)(rle2 0)(rle3 0)(rle4 0)(rle5 0)(rle6 0)(syn)";
    Connection::Instance().ReceiveMsg(ss);
    ACT::Instance().msgParse.Parse(ss);
}

void Controller::ActHandle(JointID jointID, float targetAng) {
    do {
        stringstream nss;
        string ns;
        string ss;
        float offset = ACT::Instance().Handle(jointID, targetAng);
        nss << offset;
        nss >> ns;
        ss = "(" + ACT::Instance().msgParse.m_HJ[jointID].sEffectorName + " " + ns + ")(syn)";
        Connection::Instance().sendMsg(ss);
        cout << "string:  " << ss << endl;

        Connection::Instance().ReceiveMsg(ss);
        ACT::Instance().msgParse.Parse(ss);

        cout << "current: " << ACT::Instance().msgParse.m_HJ[jointID].fAngle << endl;
        cout << "offset:  " << offset << endl;
        cout << "-------------------" << endl;
    } while (ACT::Instance().msgParse.m_HJ[jointID].fAngle != targetAng);
}

void Controller::QueueAction(JointID JointID, float targerAng)
{
    Action action = {JointID, targerAng};
    actionQueue.push_back(action);
}

void Controller::ActQueue()
{
    Action tempAction;
    vector<Action>::iterator iter;
    do
    {
        string ss = "";
        for(iter=actionQueue.begin(); iter!=actionQueue.end(); iter++)
        {
            tempAction = *iter;
            stringstream nss;
            string ns;
            float offset = ACT::Instance().Handle(tempAction.jointID, tempAction.targetAng);
            nss << offset;
            nss >> ns;
            ss += "(" + ACT::Instance().msgParse.m_HJ[tempAction.jointID].sEffectorName + " " + ns + ")";
        }
        ss += "(syn)";
        Connection::Instance().sendMsg(ss);
        Connection::Instance().ReceiveMsg(ss);
        ACT::Instance().msgParse.Parse(ss);
    }while(!AllBeTarget());
    actionQueue.clear();
    vector<Action>().swap(actionQueue);
}


bool Controller::AllBeTarget()
{
    bool rst = true;
    Action tempAction;
    vector<Action>::iterator iter;
    for(iter=actionQueue.begin(); iter!=actionQueue.end(); iter++)
    {
        tempAction = *iter;
        if(ACT::Instance().msgParse.m_HJ[tempAction.jointID].fAngle
                != tempAction.targetAng)
        {
            return false;
        }
    }
    return rst;
}
