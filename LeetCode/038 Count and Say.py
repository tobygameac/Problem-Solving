class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        value = 1
        for i in range(1, n):
            value = self.countAndSayValue(value)
        return str(value)

    def countAndSayValue(self, n):
        s = str(n)
        ans = ""
        last_digit = s[0]
        digit_count = 1
        for i in range(1, len(s) + 1):
            if i == len(s):
                if digit_count > 0:
                    ans += str(digit_count) + str(last_digit)
                break
            if s[i] != last_digit:
                    ans += str(digit_count) + str(last_digit)
                    digit_count = 0
            last_digit = s[i]
            digit_count = digit_count + 1
        return int(ans)
