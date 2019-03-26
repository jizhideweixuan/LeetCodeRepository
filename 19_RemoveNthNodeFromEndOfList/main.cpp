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

ListNode *removeNthFromEnd(ListNode *head, int n);

ListNode *removeNthFromEnd(ListNode *head, int n) {
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