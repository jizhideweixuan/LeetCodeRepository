#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

#include <iostream>

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n);

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    IOS;
    ///头结点
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    ListNode *d = dummy;
    ListNode *tmp = 0;
    for (int i = 0; i < n; i++)
        p = p->next;
    while (p->next != 0) {
        p = p->next;
        d = d->next;
    }
    tmp = d->next;
    d->next = d->next->next;
    delete (tmp);
    return dummy->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}