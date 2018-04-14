T = int(input())
for t in range(T):
	N, K = list(map(int, input().split()))
	a = []
	for _ in range(N):
		s = input()
		l = ""
		n = 0
		for i in range(len(s)-1, -1, -1):
			if s[i] != '.':
				l += s[i]
				n += 1
		while n < N:
			l += '.'
			n += 1
		a.append(l)
	r = {'R':False, 'B':False, '.':True}
	for i in range(K-1, N):
		for j in range(N):
			c = a[i][j]
			if not(r[c]):
				if i > K-2:
					b = True
					for k in range(i-K+1, i):
						if a[k][j] != c:
							b = False
							break
					r[c] |= b
				if j > K-2:
					b = True
					for k in range(j-K+1, j):
						if a[i][k] != c:
							b = False
							break
					r[c] |= b
				if i > K-2 and j > K-2:
					b = True
					for k in range(1, K):
						if a[i-k][j-k] != c:
							b = False
							break
					r[c] |= b
				if i > K-2 and j < N-K+1:
					b = True
					for k in range(1, K):
						if a[i-k][j+k] != c:
							b = False
							break
					r[c] |= b
	if r['B']:
		if r['R']:
			print("Case #{}: Both".format(t+1))
		else:
			print("Case #{}: Blue".format(t+1))
	elif r['R']:
		print("Case #{}: Red".format(t+1))
	else:
		print("Case #{}: Neither".format(t+1))


