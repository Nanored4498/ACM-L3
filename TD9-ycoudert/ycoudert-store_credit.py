N = int(input())
for i in range(N):
	C = int(input())
	I = int(input())
	P = list(map(int, input().split()))
	r = None
	for y in range(1, I):
		for x in range(y):
			if P[x]+P[y] == C:
				r = (x, y)
				break
		if r != None:
			break
	print("Case #{}: {} {}".format(i+1, r[0]+1, r[1]+1))