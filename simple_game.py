from pprint import pp

def pairStr(pair):
    return f"id={pair[3]:<5} a={pair[0]:<8} b={pair[1]:<8}"

def findNextUnused(pairs, i):
    while i < len(pairs) and pairs[i][2]:
        i += 1;
    return i

n = int(input())
aPairs = []
bPairs = []
for i in range(n):
    pair = [*map(int, input().split()), False, i]
    aPairs.append(pair)
    bPairs.append(pair)

aPairs.sort(key=lambda x: (x[0] - x[1], x[1]), reverse=False)
bPairs.sort(key=lambda x: (x[1] - x[0], x[1]), reverse=False)

pp(aPairs)
pp(bPairs)

turn = 0
ans = 0
aTop = 0
bTop = 0

while n > 0:
    print(f"turn={turn:<4} ans={ans:<8} aTop={aTop:<4} bTop={bTop:<4}  |   ", end="")
    aTopPair = aPairs[aTop]
    bTopPair = bPairs[bTop]
    if turn == 0:
        scoreFromAPairs = aTopPair[0] - bTopPair[1]
        scoreFromBPairs = bTopPair[0] - aTopPair[1]
        if (scoreFromAPairs > scoreFromBPairs) or (scoreFromAPairs == scoreFromBPairs and aTopPair[0] > bTopPair[0]):
            print(f"{pairStr(aTopPair)}, diff: {scoreFromAPairs:<4} > {scoreFromBPairs:<4}, {pairStr(bTopPair)}")
            ans += aTopPair[0]
            aTopPair[2] = True
        else:
            print(f"{pairStr(bTopPair)}, diff: {scoreFromBPairs:<4} > {scoreFromAPairs:<4}, {pairStr(aTopPair)}")
            ans += bTopPair[0]
            bTopPair[2] = True
    else:
        scoreFromAPairs = -aTopPair[1] + bTopPair[0]
        scoreFromBPairs = -bTopPair[1] + aTopPair[0]
        if (scoreFromAPairs < scoreFromBPairs)  or (scoreFromAPairs == scoreFromBPairs and aTopPair[1] > bTopPair[1]):
            print(f"{pairStr(aTopPair)}, diff: {scoreFromAPairs:<4} < {scoreFromBPairs:<4}, {pairStr(bTopPair)}")
            ans -= aTopPair[1]
            aTopPair[2] = True
        else:
            print(f"{pairStr(bTopPair)}, diff: {scoreFromBPairs:<4} < {scoreFromAPairs:<4}, {pairStr(aTopPair)}")
            ans -= bTopPair[1]
            bTopPair[2] = True
    
    aTop = findNextUnused(aPairs, aTop)
    bTop = findNextUnused(bPairs, bTop)
    n -= 1
    turn ^= 1

print(ans)
