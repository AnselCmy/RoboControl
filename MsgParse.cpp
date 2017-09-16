//
// Created by robocup on 17-9-10.
//

#include "MsgParse.h"

MsgParse::MsgParse()
{
    m_sMsg = "";
    InitJoint();
}

MsgParse::~MsgParse()
{
}

void MsgParse::Parse(string sMsg)
{

    m_sMsg = sMsg;
//    cout << m_sMsg << endl;
    for(int i = 0; i < 22; i++)
    {
        ParseHJ(m_HJ[i].sPerceptorName, m_HJ[i]);
    }
}

bool MsgParse::ParseHJ(string sEff,HJInfo &HJResult)
{
    int iIndex = m_sMsg.find(sEff);
    if (iIndex<0) return false;
    iIndex = m_sMsg.find("ax",iIndex + 6);
    if (iIndex<0) return false;
    iIndex += 2;
    int iTemp;
    HJResult.fAngle = GetFloat(m_sMsg,iIndex,iTemp);
    return true;
}

double MsgParse::GetFloat(string sMsg,int &iStartPos,int &iEndPos)
{
    int iIndex = iStartPos;
    int iMsgLen = sMsg.length();
    while(iIndex < iMsgLen)
    {
        iIndex = sMsg.find(" ",iIndex);
        if (iIndex<0) break;
        iIndex++;
        if (!IsNumHead(sMsg[iIndex])) continue;
        if (sMsg[iIndex]=='-'&&!IsNum(sMsg[iIndex+1])) continue;
        iEndPos = iIndex;
        while(iEndPos+1<iMsgLen&&IsIncludeInNum(sMsg[iEndPos+1])) iEndPos++;
        if (sMsg[iEndPos+1]!=' '&&sMsg[iEndPos+1]!=')')
        {
            iIndex = iEndPos;
            continue;
        }
        iStartPos = iIndex;
        return StringToFloat(sMsg.substr(iIndex,iEndPos - iIndex + 1));
    }
    iStartPos = -1;
    return 0.0;
}

bool MsgParse::IsNumHead(char c)
{
    return ((c>='0'&&c<='9')||c=='-');
}

bool MsgParse::IsNum(char c)
{
    return (c>='0'&&c<='9');
}

bool MsgParse::IsIncludeInNum(char c)
{
    return ((c>='0'&&c<='9')||c=='.'||c=='-');
}

double MsgParse::StringToFloat(string sNum)
{
    int iStrLen = sNum.length();
    if (iStrLen<=0) return 0.0;
    int iDotPos = sNum.find(".");
    if (iDotPos<0) iDotPos = iStrLen;
    int iSign = (sNum[0]=='-'?-1:1);
    double iMultiply = 1.0;
    int iTemp = (iSign==-1?iDotPos-1:iDotPos);
    while(--iTemp) iMultiply*=10;
    double dResult = 0.0;
    int iIndex = (iSign==-1?1:0);
    while(iIndex < iStrLen)
    {
        if (sNum[iIndex]!='.')
        {
            dResult += (sNum[iIndex]-48)*iMultiply;
            iMultiply/=10.0;
        }
        iIndex++;
    }
    return dResult*iSign;
}

void MsgParse::InitJoint()
{
    m_HJ[JID_HEAD_1].ID = JID_HEAD_1;
    m_HJ[JID_HEAD_2].ID = JID_HEAD_2;
    m_HJ[JID_LARM_1].ID = JID_LARM_1;
    m_HJ[JID_RARM_1].ID = JID_RARM_1;
    m_HJ[JID_LARM_2].ID = JID_LARM_2;
    m_HJ[JID_RARM_2].ID = JID_RARM_2;
    m_HJ[JID_LARM_3].ID = JID_LARM_3;
    m_HJ[JID_RARM_3].ID = JID_RARM_3;
    m_HJ[JID_LARM_4].ID = JID_LARM_4;
    m_HJ[JID_RARM_4].ID = JID_RARM_4;
    m_HJ[JID_LLEG_1].ID = JID_LLEG_1;
    m_HJ[JID_RLEG_1].ID = JID_RLEG_1;
    m_HJ[JID_LLEG_2].ID = JID_LLEG_2;
    m_HJ[JID_RLEG_2].ID = JID_RLEG_2;
    m_HJ[JID_LLEG_3].ID = JID_LLEG_3;
    m_HJ[JID_RLEG_3].ID = JID_RLEG_3;
    m_HJ[JID_LLEG_4].ID = JID_LLEG_4;
    m_HJ[JID_RLEG_4].ID = JID_RLEG_4;
    m_HJ[JID_LLEG_5].ID = JID_LLEG_5;
    m_HJ[JID_RLEG_5].ID = JID_RLEG_5;
    m_HJ[JID_LLEG_6].ID = JID_LLEG_6;
    m_HJ[JID_RLEG_6].ID = JID_RLEG_6;

    m_HJ[JID_HEAD_1].sPerceptorName = "hj1";
    m_HJ[JID_HEAD_2].sPerceptorName = "hj2";
    m_HJ[JID_LLEG_1].sPerceptorName = "llj1";
    m_HJ[JID_LLEG_2].sPerceptorName = "llj2";
    m_HJ[JID_LLEG_3].sPerceptorName = "llj3";
    m_HJ[JID_LLEG_4].sPerceptorName = "llj4";
    m_HJ[JID_LLEG_5].sPerceptorName = "llj5";
    m_HJ[JID_LLEG_6].sPerceptorName = "llj6";
    m_HJ[JID_RLEG_1].sPerceptorName = "rlj1";
    m_HJ[JID_RLEG_2].sPerceptorName = "rlj2";
    m_HJ[JID_RLEG_3].sPerceptorName = "rlj3";
    m_HJ[JID_RLEG_4].sPerceptorName = "rlj4";
    m_HJ[JID_RLEG_5].sPerceptorName = "rlj5";
    m_HJ[JID_RLEG_6].sPerceptorName = "rlj6";
    m_HJ[JID_LARM_1].sPerceptorName = "laj1";
    m_HJ[JID_LARM_2].sPerceptorName = "laj2";
    m_HJ[JID_LARM_3].sPerceptorName = "laj3";
    m_HJ[JID_LARM_4].sPerceptorName = "laj4";
    m_HJ[JID_RARM_1].sPerceptorName = "raj1";
    m_HJ[JID_RARM_2].sPerceptorName = "raj2";
    m_HJ[JID_RARM_3].sPerceptorName = "raj3";
    m_HJ[JID_RARM_4].sPerceptorName = "raj4";

    m_HJ[JID_HEAD_1].sEffectorName = "he1";
    m_HJ[JID_HEAD_2].sEffectorName = "he2";
    m_HJ[JID_LLEG_1].sEffectorName = "lle1";
    m_HJ[JID_LLEG_2].sEffectorName = "lle2";
    m_HJ[JID_LLEG_3].sEffectorName = "lle3";
    m_HJ[JID_LLEG_4].sEffectorName = "lle4";
    m_HJ[JID_LLEG_5].sEffectorName = "lle5";
    m_HJ[JID_LLEG_6].sEffectorName = "lle6";
    m_HJ[JID_RLEG_1].sEffectorName = "rle1";
    m_HJ[JID_RLEG_2].sEffectorName = "rle2";
    m_HJ[JID_RLEG_3].sEffectorName = "rle3";
    m_HJ[JID_RLEG_4].sEffectorName = "rle4";
    m_HJ[JID_RLEG_5].sEffectorName = "rle5";
    m_HJ[JID_RLEG_6].sEffectorName = "rle6";
    m_HJ[JID_LARM_1].sEffectorName = "lae1";
    m_HJ[JID_LARM_2].sEffectorName = "lae2";
    m_HJ[JID_LARM_3].sEffectorName = "lae3";
    m_HJ[JID_LARM_4].sEffectorName = "lae4";
    m_HJ[JID_RARM_1].sEffectorName = "rae1";
    m_HJ[JID_RARM_2].sEffectorName = "rae2";
    m_HJ[JID_RARM_3].sEffectorName = "rae3";
    m_HJ[JID_RARM_4].sEffectorName = "rae4";
}