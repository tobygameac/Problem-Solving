import math

def DigitSum(n):
    digit_sum = 0
    while n:
        digit_sum = digit_sum + (n % 10)
        n = n / 10
    return digit_sum

a = []
for n in range(2, 100):
    for exp in range(1, 100):
        num = n ** exp
        if num >= 10 and DigitSum(num) == n:
            a.append(num)

a = sorted(a)

print a[29]
