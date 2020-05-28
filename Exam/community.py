T = int(input())
for _ in range(T):
	n, m, k = map(int, input().split())
	deg = [0]*n
	G = [[] for _ in range(n)]
	for _ in range(m):
		i, j = map(int, input().split())
		deg[i] += 1
		deg[j] += 1
		G[i].append(j)
		G[j].append(i)
	q = []
	for i in range(n):
		if deg[i] < k:
			deg[i] = -1
			q.append(i)
	while q:
		i = q.pop()
		for j in G[i]:
			if deg[j] >= 0:
				deg[j] -= 1
				if deg[j] < k:
					deg[j] = -1
					q.append(j)
	res = 0
	for i in range(n):
		if deg[i] >= 0:
			res += 1
			q = [i]
			deg[i] = -1
			while q:
				u = q.pop()
				for v in G[u]:
					if deg[v] >= 0:
						deg[v] = -1
						q.append(v)
	print(res)