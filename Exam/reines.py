#marche pas

def f(m, n, k):
	if k == 0:
		return 1
	res = 0
	for i in range(n):
		for j in range(n):
			if m[i][j]:
				m2 = [([False] * n if a == i else [m[a][b] and b != i and a-b != i-j and a+b != i+j for b in range(n)]) for a in range(n)]
				m[i][j] = False
				res += f(m2, n, k-1)
	return res

line = input()
while len(line) > 0:
	n = int(line)
	m = []
	for _ in range(n):
		m.append([c == '.' for c in input()])
	print(f(m, n, n))