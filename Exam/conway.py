T = int(input())
for t in range(1, T+1):
	u, n = map(int, input().split())
	l = []
	while u > 0:
		l.append(u % 10)
		u //= 10
	l = list(reversed(l))
	for _ in range(n):
		l2 = []
		i, j = 0, 1
		while i < len(l):
			while j < len(l) and l[j] == l[i]:
				j += 1
			l2.append(j-i)
			l2.append(l[i])
			i = j
		l = l2
	res = "".join(str(a) for a in l)
	print("Cas #{}: {}".format(t, res))