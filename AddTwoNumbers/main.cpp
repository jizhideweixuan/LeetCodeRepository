#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int main() {
    ListNode *l1= new ListNode(0);
    ListNode *l2= new ListNode(0);
    ListNode *temp;
    temp = l1;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(3);

    temp = l2;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(6);
    temp = temp->next;
    temp->next = new ListNode(4);

    temp = addTwoNumbers(l1,l2);
    while(temp!=NULL){
        cout<<temp->val;
        temp=temp->next;
    }
    return 0;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *c1 = l1;
    ListNode *c2 = l2;
    ListNode *pre = new ListNode(0);
    ListNode *now = pre;
    int sum = 0;
    while (c1 != NULL || c2 != NULL) {
        if (c1 != NULL) {
            sum += c1->val;
            c1 = c1->next;
        }
        if (c2 != NULL) {
            sum += c2->val;
            c2 = c2->next;
        }
        now->next = new ListNode(sum % 10);
        sum /= 10;
        now = now->next;
    }
    if (sum == 1)
        now->next = new ListNode(1);
    return pre->next;
}

