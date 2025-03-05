class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;
        
        // l1이나 l2가 있거나 carry가 있으면 계속 진행
        while(l1 || l2 || carry) {
            int sum = carry;
            
            // 조건문 단순화
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
        }
        
        // 첫 번째 더미 노드는 사용하지 않으므로
        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};