#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

node *createList()
{
    int num;
    node *head = NULL, *tail = NULL;
    while (cin >> num && num != -1)
    {
        node *newNode = new node; // 创建一个新节点
        newNode->val = num;       // 设置新节点的值
        newNode->next = NULL;     // 新节点的下一个节点为空
        if (head == NULL)
        { // 如果链表为空，则新节点即为头节点
            head = newNode;
            tail = newNode; // 同时也是尾节点
        }
        else
        {                         // 否则，将新节点添加到链表的末尾
            tail->next = newNode; // 尾节点的下一个节点为新节点
            tail = newNode;       // 更新尾节点为新节点
        }
    }
    return head; // 返回链表的头节点
}

node *reverseList(node *head)
{
    node *prev = NULL;
    node *current = head;
    while (current != NULL)
    {
        node *nextTemp = current->next; // 保存当前节点的下一个节点
        current->next = prev;           // 将当前节点指向前一个节点，实现逆序
        prev = current;                 // 前一个节点向前移动
        current = nextTemp;             // 当前节点向前移动
    }
    return prev; // 当循环结束时，prev将指向新的头节点
}

int main()
{
    node *head = NULL;
    head = createList(); // 创建链表

    node *reversedHead = NULL;
    reversedHead = reverseList(head); // 逆序链表

    if (reversedHead == NULL)
    { // 如果链表为空，则直接输出-1
        cout << "-1 ";
    }
    else
    { // 否则，遍历链表并输出每个节点的值
        node *p = reversedHead;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next; // 移动到下一个节点
        }
    }

    return 0;
}