#include <iostream>

using namespace std;

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head);


ListNode *swapPairs(ListNode *head) {
    if (head == 0)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    while (p!=0&&p->next!=0&&p->next->next!=0) {
        ListNode *s1 = p->next;
        ListNode *s2 = p->next->next;
        s1->next = s2->next;
        s2->next = s1;
        p->next = s2;
        p = p->next->next;
    }
    return dummy->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}