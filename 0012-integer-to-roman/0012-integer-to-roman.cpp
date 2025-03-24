class Solution {
public:
    string intToRoman(int num) {
    vector<pair<int, string>> valueSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result = "";
    
    // Iterate through each symbol pair
    for (auto &pair : valueSymbols) {
        // While num is greater than or equal to the current value
        while (num >= pair.first) {
            // Subtract the value and add the symbol
            num -= pair.first;
            result += pair.second;
        }
    }
    
    return result;
}
};