import sys
input = sys.stdin.readline
out = sys.stdout.write
n = int(input())
v = list(map(int, input().split()))
s = {0};
ans = 1
for x in v:
    if x-1 not in s:
        ans+=1
    s.add(x)
out(f"{ans}")
