class Solution {
public:
    string addBinary(string a, string b) {
        int size = a.size() < b.size() ? b.size() : a.size();

        string result(size, '0');
        int a_idx = a.size() - 1;  // 인덱스는 0부터 시작하므로 size-1
        int b_idx = b.size() - 1;
        int result_idx = size - 1; // 결과 인덱스도 size-1부터 시작

        bool carry = false;
        while(a_idx >= 0 || b_idx >= 0){
            bool cur_a, cur_b;

            if(a_idx < 0) cur_a = false;
            else {
                if(a[a_idx] == '0') cur_a = false;
                else cur_a = true;
            }

            if(b_idx < 0) cur_b = false;
            else {
                if(b[b_idx] == '0') cur_b = false;
                else cur_b = true;
            }

            // 현재 비트 계산
            bool current = cur_a ^ cur_b ^ carry;
            // 다음 carry 계산
            carry = (cur_a && cur_b) || (cur_a && carry) || (cur_b && carry);
            
            result[result_idx] = current ? '1' : '0';
            
            a_idx--;
            b_idx--;
            result_idx--;
        }
        
        // carry가 남아있다면 맨 앞에 1 추가
        if(carry) {
            result = "1" + result;
        }
        
        return result;
    }
};