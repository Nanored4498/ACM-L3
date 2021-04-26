while True:
	try:
		n = int(input())
	except EOFError:
		exit(0)
	root = [True] * n
	G = []
	for _ in range(n):
		g = list(map(int, input().split()))[1:]
		G.append(g)
		for i in g: root[i] = False
	r = 0
	while not root[r]: r += 1
	def f(i):
		s = 0
		add = [j for j in range(len(G[i])+3)]
		for j in G[i]:
			fj = f(j)
			s += fj[1]
			if fj[0] < len(add): add[fj[0]] += fj[2]
		best, val = min((add[j], j) for j in range(1, len(add)))
		sec = min(add[j] for j in range(1, len(add)) if j != val)
		return val, s+best, sec-best
	print(f(r)[1])
	try:
		input()
	except EOFError:
		exit(0)