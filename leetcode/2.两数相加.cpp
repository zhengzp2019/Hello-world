/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l, *last;
        bool flag = false; //标记是否有进位
        ListNode *p1 = l1, *p2 = l2, *p;
        int ans = 0;
        bool first = true;
        do
        {
            ans = flag == true ? p1->val + p2->val + 1 : p1->val + p2->val;
            if (ans >= 10)
            {
                flag = true;
                ans -= 10;
            }
            else
                flag = false;
            p = new ListNode(ans);
            p1 = p1->next;
            p2 = p2->next;
            if (first)
            {
                first = !first;
                l = p;
                last = p;
            }
            else
            {
                last->next = p;
                last = p;
            }
        } while (p1 && p2);
        if (p1)
            last->next = p1;
        if (p2)
            last->next = p2;
        p = last->next;
        while (flag && p)
        {
            ans = p->val + 1;
            if (ans >= 10)
            {
                ans -= 10;
                flag = true;
            }
            else
                flag = false;
            p->val = ans;
            last = last->next;
            p = last->next;
        }
        if (flag)
            last->next = new ListNode(1);
        return l;
    }
};
// @lc code=end
