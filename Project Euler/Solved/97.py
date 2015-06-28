def power(base, e, mod):
  if e == 0:
      return 1
  if e == 1:
      return base
  return (power(base, e / 2 + (e & 1), mod) * power(base, e / 2, mod)) % mod

MOD = 1e10
print (28433 * power(2, 7830457, MOD) + 1) % MOD
