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
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode();
            int carry = 0;
            ListNode* current = result;
            ListNode* prev;

            while(l1 || l2){
                int sum = carry;

                if(l1 && l2) sum += l1->val + l2->val;
                else if(l1 && !l2) sum += l1->val;
                else sum += l2->val;
                
                // 실수 1 1의 자리만 남기려면 % 사용
                // current->val = sum - 10;
                current->val = sum % 10;
                carry = sum / 10;

                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;

                current->next = new ListNode();
                prev = current;
                current = current->next;
            }

            if(carry) current->val = carry;
            else {
                delete prev->next;
                prev->next = nullptr;
            }

            return result;
        }
    };