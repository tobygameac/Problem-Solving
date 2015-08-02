class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        char_stack = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                char_stack.append(c)
            else:
                if len(char_stack) == 0:
                    return False
                if c == ')':
                    if char_stack[-1] == '(':
                        char_stack.pop()
                    else:
                        return False
                if c == ']':
                    if char_stack[-1] == '[':
                        char_stack.pop()
                    else:
                        return False
                if c == '}':
                    if char_stack[-1] == '{':
                        char_stack.pop()
                    else:
                        return False
        return len(char_stack) == 0
