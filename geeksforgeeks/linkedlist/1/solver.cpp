#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class ListNode
{
    public:
        int value;
        ListNode *prev,*next;
        ListNode() {}
};

ListNode *result;

void printList(ListNode *node)
{
    while(node!=NULL)
    {
        cout<<node->value<<" ";
        node = node->next;
    }
}

void inputList(ListNode *first)
{
    int N;
    cin>>N;
    ListNode *nxt, *prv;
    for(int i=1; i <= N; i++)
    {
        ListNode *lst = new ListNode();
        int x;
        if( i == 1 )
        {
            cin>>x;
            first->value = x;
            first->prev = NULL;
        }
        else
        {
            cin>>x;
            lst->value = x;
        }
        if( i == 2 )
        {
            lst ->prev = first;
            first ->next = lst;
        }
        else if( i != 1)
        {
            lst->prev = nxt;
            nxt->next = lst;
        }
        if(i == N)
            lst->next = NULL;
        nxt = lst;
    }
    if(N == 1)
        first = NULL;
}

void mergeLists(ListNode *first, ListNode *second)
{
    ListNode *lFirst, *lSecond, *node, *nxt;
    node = first;
    result = NULL;
    while(node != NULL)
    {
        if(node->next==NULL)
            lFirst = node;
        node = node->next;
    }
    node = second;
    while(node != NULL)
    {
        if(node->next==NULL)
            lSecond = node;
        node = node->next;
    }
    nxt = new ListNode();
    while(lFirst != NULL || lSecond != NULL)
    {
        if(lFirst == NULL)
        {
            while(lSecond != NULL)
            {
                if(result == NULL)
                {
                    result = new ListNode();
                    result->value = lSecond->value;
                    result->prev = NULL;
                    nxt = result;
                }
                else
                {
                    ListNode *lst = new ListNode();
                    lst->value = lSecond->value;
                    nxt->next = lst;
                    lst->prev = nxt;
                    nxt = lst;
                }
                lSecond = lSecond->prev;
            }
            break;
        }
        else if(lSecond == NULL)
        {
            while(lFirst != NULL)
            {
                if(result == NULL)
                {
                    result = new ListNode();
                    result->value = lFirst->value;
                    result->prev = NULL;
                    nxt = result;
                }
                else
                {
                    ListNode *lst = new ListNode();
                    lst->value = lFirst->value;
                    nxt->next = lst;
                    lst->prev = nxt;
                    nxt = lst;
                }
                lFirst = lFirst->prev;
            }
            break;
        }
        else
        {
            if(lFirst->value < lSecond->value)
            {
                if(result == NULL)
                {
                    result = new ListNode();
                    result->value = lSecond->value;
                    result->prev = NULL;
                    nxt = result;
                }
                else
                {
                    ListNode *lst = new ListNode();
                    lst->value = lSecond->value;
                    lst->prev = nxt;
                    nxt->next = lst;
                    nxt = lst;
                }
                lSecond = lSecond->prev;
            }
            else
            {
                if(result == NULL)
                {
                    result = new ListNode();
                    result->value = lFirst->value;
                    result->prev = NULL;
                    nxt = result;
                }
                else
                {
                    ListNode *lst = new ListNode();
                    lst->value = lFirst->value;
                    lst->prev = nxt;
                    nxt->next = lst;
                    nxt = lst;
                }
                lFirst = lFirst->prev;
            }
        }
    }
    nxt->next = NULL;
}
