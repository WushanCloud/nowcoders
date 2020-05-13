题目描述
请实现接口：

unsigned int  AddCandidate (char* pCandidateName);
功能：设置候选人姓名
输入： char* pCandidateName 候选人姓名
输出：无
返回：输入值非法返回0，已经添加过返回0 ，添加成功返回1

 

Void Vote(char* pCandidateName);
功能：投票
输入： char* pCandidateName 候选人姓名
输出：无
返回：无


unsigned int  GetVoteResult (char* pCandidateName);

功能：获取候选人的票数。如果传入为空指针，返回无效的票数，同时说明本次投票活动结束，释放资源
输入： char* pCandidateName 候选人姓名。当输入一个空指针时，返回无效的票数

输出：无
返回：该候选人获取的票数

 

void Clear()

// 功能：清除投票结果，释放所有资源
// 输入：
// 输出：无
// 返回
 

输入描述:
输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票。

输出描述:
每行输出候选人的名字和得票数量。

示例1
输入
复制
4
A B C D
8
A B C D E F G H
输出
复制
A : 1
B : 1
C : 1
D : 1
Invalid : 4


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<string> names;
vector<int> votes;
int temp = 0;
unsigned int  AddCandidate(char* pCandidateName);
//功能：设置候选人姓名
//输入： char* pCandidateName 候选人姓名
//输出：无
//返回：输入值非法返回0，已经添加过返回0 ，添加成功返回1

void Vote(char* pCandidateName);
//功能：投票
//输入： char* pCandidateName 候选人姓名
//输出：无
//返回：无

unsigned int  GetVoteResult(char* pCandidateName);
//功能：获取候选人的票数。如果传入为空指针，返回无效的票数，同时说明本次投票活动结束，释放资源
//输入： char* pCandidateName 候选人姓名。当输入一个空指针时，返回无效的票数
//输出：无
//返回：该候选人获取的票数

void Clear();
// 功能：清除投票结果，释放所有资源
// 输入：
// 输出：无
// 返回

int main()
{
    int n = 0, m = 0;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            char name[100] = { 0 };
            cin >> name;
            AddCandidate(name);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            char name[100] = { 0 };
            cin >> name;
            Vote(name);
        }
        for (size_t i = 0; i < names.size(); i++)
        {
            char name[100] = { 0 };
            strcpy(name, names[i].c_str());
            cout << names[i] << " : " << GetVoteResult(name) << endl;
        }
        cout << "Invalid : " << m - temp << endl;
        Clear();
    }
    
    return 0;
}
unsigned int  AddCandidate(char* pCandidateName)
{
    if (pCandidateName == nullptr)
    {
        return 0;
    }
    for (int i = 0; i < names.size(); i++)
    {
        if (strcmp(pCandidateName, names[i].c_str())== 0)
        {
            return 0;
        }
    }
    names.push_back(pCandidateName);
    votes.push_back(0);
    return 1;
}
void Vote(char* pCandidateName)
{
    for (int i = 0; i < names.size(); i++)
    {
        if (strcmp(pCandidateName, names[i].c_str()) == 0)
        {
            votes[i]++;
            temp++;
            return;
        }
    }
}
unsigned int  GetVoteResult(char* pCandidateName)
{
    if (pCandidateName == nullptr)
    {
        Clear();
        return -1;
    }
    for (int i = 0; i < names.size(); i++)
    {
        if (strcmp(pCandidateName, names[i].c_str()) == 0)
        {
            return votes[i];
        }
    }
}
void Clear()
{
    names.clear();
    votes.clear();
    temp = 0;
}
