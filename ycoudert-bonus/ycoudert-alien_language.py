(L, D, N) = list(map(int, input().split()))
w = {}
for _ in range(D):
	s = input()
	x = w
	for c in s:
		if not(c in x):
			x[c] = {}
		x = x[c]

def f(p, x, d):
	if x == L:
		return 1
	res = 0
	for c in p[x]:
		if c in d:
			res += f(p, x+1, d[c])
	return res

for n in range(N):
	s = input()
	i = 0
	p = []
	for _ in range(L):
		if s[i] == '(':
			i += 1
			l = []
			while s[i] != ')':
				l.append(s[i])
				i += 1
			p.append(l)
		else:
			p.append(s[i])
		i += 1
	print("Case #{}: {}".format(n+1, f(p, 0, w)))