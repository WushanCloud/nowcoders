题目描述
有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
测试样例：
{1,2,3},{3,2,1}
返回：{4,4,4}


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        ListNode* newhead = new ListNode(0);
        ListNode* newcur = newhead;
        int temp = 0;//表示进位
        while(a && b)
        {
            int num = a->val + b->val + temp;
            ListNode* ans = new ListNode(num%10);
            temp = num / 10;
            newcur->next = ans;
            newcur = newcur->next;
            a = a->next;
            b = b->next;
        }
        while (a)
        {
            int num = a->val + temp;
            ListNode* ans = new ListNode(num%10);
            temp = num / 10;
            newcur->next = ans;
            newcur = newcur->next;
            a = a->next;
        }
        while (b)
        {
            int num = b->val + temp;
            ListNode* ans = new ListNode(num%10);
            temp = num / 10;
            newcur->next = ans;
            newcur = newcur->next;
            b = b->next;
        }
        if (temp)
        {
            ListNode* ans = new ListNode(temp);
            newcur->next = ans;
        }
        newcur = newhead->next;
        delete newhead;
        return newcur;
    }
};

