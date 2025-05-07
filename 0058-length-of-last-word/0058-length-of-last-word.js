/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let cnt = 0;
    for(let i = s.length - 1; -1 < i; i--){
        if(cnt != 0 && s[i] == ' ') return cnt;

        if(s[i] != ' ') cnt++;
    }
    return cnt;
};