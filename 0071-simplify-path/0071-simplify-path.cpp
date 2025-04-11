class Solution {
public:
    string simplifyPath(string path) {
        string result = "/";  // 초기값 설정
        string temp;
        
        for(auto s : path){
            // result가 비어있는지 먼저 확인

            if(s == '/'){
                if(temp == "" || temp == ".") {
                    // 아무 것도 하지 않음
                }
                else if(temp == ".."){
                    if(result.size() > 1){  // 루트 디렉토리가 아닌 경우만
                        result.pop_back();
                        while(!result.empty() && result.back() != '/') result.pop_back();
                    }
                }
                else{  
                    result += temp + "/";
                }

                temp.clear();
                continue;
            }

            cout << s << " "<< result << " " << temp <<endl;
            temp.push_back(s);
        }

        // 마지막 경로 처리
        if(temp == ".."){
            if(result.size() > 1) {
                result.pop_back();
                while(!result.empty() && result.back() != '/') result.pop_back();
            }
        }
        else if(temp != "." && !temp.empty()){
            result += temp + "/";  // 마지막에 /를 추가
        }

        // 루트 디렉토리가 아니고 /로 끝나는 경우 제거
        if(result.size() > 1 && result.back() == '/') result.pop_back();
        
        return result;
    }
};