#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

#include <iostream>

using namespace std;

ListNode *swapPairs(ListNode *head);

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
    IOS;
    if (head == 0)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = head;
    ListNode *d = dummy;
    while (p->next != 0) {

    }
    return dummy->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}