from dataclasses import dataclass

@dataclass
class Pair:
    a: int
    b: int
    used: bool
    diff: int
    
    def __str__(self):
        return f"({self.a}, {self.b}) - used={self.used}, diff={self.diff}"

n = int(input())
pairs = []
for i in range(n):
    a, b = map(int, input().split())
    pairs.append(Pair(a, b, False, a+b))

ans = 0
turn = 0
while n > 0:
    if (turn == 0):
        pair = max(filter(lambda x: not x.used, pairs), key=lambda x: x.diff)
        # print(f"P1 {pair}")
        pair.used = True
        ans += pair.a
    else:
        pair = max(filter(lambda x: not x.used, pairs), key=lambda x: x.diff)
        # print(f"P2 {pair}")
        pair.used = True
        ans -= pair.b

    n -= 1
    turn ^= 1

print(ans)
