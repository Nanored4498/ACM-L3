T = int(input())
res = 0

def f(x, y, a, i, m, n):
	global res
	if i[x][y] == 0:
		res += 1
	i[x][y] = a
	if x > 0 and i[x-1][y] < a:
		if m[x-1][y] == m[x][y]:
			f(x-1, y, a, i, m, n)
		elif a == 2:
			f(x-1, y, 1, i, m, n)
	if x < n-1 and i[x+1][y] < a:
		if m[x+1][y] == m[x][y]:
			f(x+1, y, a, i, m, n)
		elif a == 2:
			f(x+1, y, 1, i, m, n)
	if y > 0 and i[x][y-1] < a:
		if m[x][y-1] == m[x][y]:
			f(x, y-1, a, i, m, n)
		elif a == 2:
			f(x, y-1, 1, i, m, n)
	if y < n-1 and i[x][y+1] < a:
		if m[x][y+1] == m[x][y]:
			f(x, y+1, a, i, m, n)
		elif a == 2:
			f(x, y+1, 1, i, m, n)

for _ in range(T):
	input()
	n, c = list(map(int, input().split()))
	x, y = list(map(int, input().split()))
	m = []
	i = [[0]*n for _ in range(n)]
	for _ in range(n):
		m.append(list(map(int, input().split())))
	res = 0
	f(x, y, 2, i, m, n)
	print(res)
	