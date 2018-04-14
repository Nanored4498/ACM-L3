T = int(input())

def f(p, a):
	ds = a[1:].split("/")
	res = 0
	for d in ds:
		if not(d in p):
			p[d] = {}
			res += 1
		p = p[d]
	return res

for t in range(T):
	N, M = list(map(int, input().split()))
	p = {}
	for _ in range(N):
		f(p, input())
	res = 0
	for _ in range(M):
		res += f(p, input())
	print("Case #{}: {}".format(t+1, res))