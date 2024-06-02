class Solution {
public:
    int calculate(string s) {
        stack<int> sp;
        int number = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                number = number * 10 + (s[i] - '0');
            }
            else if(s[i] == '+'){
                result += (number*sign);
                number = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                result += (number*sign);
                number = 0;
                sign = -1;
            }
            else if(s[i] == '('){
                sp.push(result);
                sp.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                result += (number*sign);
                number = 0;
                int stack_sign = sp.top(); sp.pop();
                int last_res = sp.top(); sp.pop();
                result *= stack_sign;
                result += last_res;
            }
        }
        result += number*sign;
        return result;
    }
};
