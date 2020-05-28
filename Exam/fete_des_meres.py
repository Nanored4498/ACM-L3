T = int(input())
for _ in range(T):
	N = int(input())
	G = [[] for _ in range(N)]
	for i in range(N):
		l = list(map(int, input().split()))
		for j in range(N):
			if l[j] == 1:
				G[i].append(j)
	seen = [-1]*N
	pred = [-1]*N
	ok = True
	def augment(i, s):
		seen[i] = s
		for j in G[i]:
			if pred[j] == -1 or (seen[pred[j]] != s and augment(pred[j], s)):
				pred[j] = i
				return True
		return False
	for i in range(N):
		if not augment(i, i):
			ok = False
			break
	if ok: print("Yes we can")
	else: print("Pas possible")