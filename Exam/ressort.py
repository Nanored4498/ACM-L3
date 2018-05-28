T = int(input())

inf = 2000000

for _ in range(T):
	line = input().split()
	while line == []:
		line = input().split()
	N, R = list(map(int, line))
	r = [[] for _ in range(1001)] #on regroupe par intervals de 1000 les ressorts
	for _ in range(N):
		e, p = list(map(int, input().split()))
		r[e // 1000].append((p, e))
	for l in r:
		l.sort()
	res = 0
	for _ in range(R):
		a, b = list(map(int, input().split()))
		lp, li = inf, 0
		aa, bb = a // 1000, b // 1000
		for x in {aa, bb}:
			for p, e in r[x]:
				if a <= e <= b:
					if p < lp:
						lp, li = p, x
					break
		for x in range(aa+1, bb):
			if len(r[x]) > 0:
				p = r[x][0][0]
				if p < lp:
					lp, li = p, x
		if lp != inf:
			res += lp
			if li == aa or li == bb:
				for i in range(len(r[li])):
					p, e = r[li][i]
					if a <= e <= b:
						del r[li][i]
						break
			else:
				del r[li][0]
	print(res)