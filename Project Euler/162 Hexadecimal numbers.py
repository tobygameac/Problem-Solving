count = [0, 0, 0]
for digit in range(3, 17):
  count.append(0)
  count[digit] = 15 * 16 ** (digit - 1);
  count[digit] = count[digit] - 15 ** digit - 2 * 14 * 15 ** (digit - 1);
  count[digit] = count[digit] + 13 * 14 ** (digit - 1) + 2 * 14 ** digit;
  count[digit] = count[digit] - 13 ** digit
  print count[digit]

print hex(sum(count)).upper()
