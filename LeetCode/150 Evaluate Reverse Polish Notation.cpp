class Solution {
 
 public:
  
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> s;
    for (const std::string &token : tokens) {
      if (!token[1] && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (token[0] == '+') {
          s.push(b + a);
        } else if (token[0] == '-') {
          s.push(b - a);
        } else if (token[0] == '*') {
          s.push(b * a);
        } else if (token[0] == '/') {
          s.push(b / a);
        }
      } else {
        s.push(atoi(token.c_str()));
      }
    }
    return s.top();
  }

};
