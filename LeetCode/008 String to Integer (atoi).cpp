#include <string>
#include <climits>

using namespace std;

class Solution {
 public:
   int myAtoi(string str) {
     long long result = 0;
     bool minus = false;
     int i;
     for (i = 0; str[i] && str[i] == ' '; ++i);

     if (str[i] == '+' || str[i] == '-') {
       minus = str[i] == '-';
       ++i;
     }

     for (; str[i]; ++i) {
       if (str[i] >= '0' && str[i] <= '9') {
         result = result * 10 + str[i] - '0';
         if (result * (minus ? -1 : 1) > INT_MAX) {
           return INT_MAX;
         }
         if (result * (minus ? -1 : 1) < INT_MIN) {
           return INT_MIN;
         }
       } else {
         break;
       }
     }

     return result * (minus ? -1 : 1);
   }
};

int main() {
  return 0;
}
