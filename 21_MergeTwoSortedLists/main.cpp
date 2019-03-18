#include <iostream>
#include <vector>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

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


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == 0 && l2 == 0)
        return 0;
    if (l1 != 0 && l2 == 0)
        return l1;
    if (l1 == 0 && l2 != 0)
        return l2;
    ListNode *res = new ListNode(0);
    ListNode *p = new ListNode(0);
    res->next = p;
    while (l1 != 0 && l2 != 0) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    while (l1 != 0) {
        p->next = l1;
        p = p->next;
        l1 = l1->next;
    }
    while (l2 != 0) {
        p->next = l2;
        p = p->next;
        l2 = l2->next;
    }
    return res->next->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}