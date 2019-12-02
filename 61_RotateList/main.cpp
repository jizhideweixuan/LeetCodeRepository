#include <iostream>
#include <vector>

using namespace std;

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *begin = head;
    for (int i = 0; i < k; ++i) {
        ListNode *p = head;
        //取到倒数第二个
        while (p->next->next != nullptr) {
            p = p->next;
        }
        ListNode *end = p->next;
        p->next = nullptr;
        end->next = head;
        head = end;
    }
    return head;
}

ListNode *creat_list(vector<int> v) {
    ListNode *head;
    ListNode *p = head;
    if (!v.empty()) {
        head = new ListNode(v[0]);
        p = head;
    }
    for (int i = 1; i < v.size(); ++i) {
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return head;
}

void output_list(ListNode *head) {
    while (head->next != nullptr) {
        cout << head->val << ",";
        head = head->next;
    }
    cout << head->val << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = creat_list(v);
    output_list(head);
    rotateRight(head, 2);
    output_list(head);
    return 0;
}