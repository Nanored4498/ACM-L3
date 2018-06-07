T = int(input())
for t in range(T):
	n = int(input())
	a = sorted(list(map(int, input().split())))
	b = sorted(list(map(int, input().split())))
	r = 0
	for i in range(n):
		r += a[i]*b[n-i-1]
	print("Case #{}: {}".format(t+1, r))