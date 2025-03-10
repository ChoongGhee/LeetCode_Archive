#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0) return false;
            
            string str = to_string(x);
            
            int lo, hi;
            lo = 0;
            hi = str.size() -1;

            while(lo <= hi){
                cout << lo << " " << str[lo] << " " << hi << " " << str[hi] << endl;
                if(str[lo++] != str[hi--]) return false;
            }

            return true;
        }
    };