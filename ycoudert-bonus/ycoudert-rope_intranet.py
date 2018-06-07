T = int(input())
for t in range(T):
	N = int(input())
	w = []
	for _ in range(N):
		a, b = list(map(int, input().split()))
		w.append((a, b))
	r = 0
	for y in range(1, N):
		for x in range(y):
			if (w[x][0] < w[y][0] and w[x][1] > w[y][1]) or (w[x][0] > w[y][0] and w[x][1] < w[y][1]):
				r += 1
	print("Case #{}: {}".format(t+1, r))