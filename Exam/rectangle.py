n = int(input())
for t in range(1, n+1):
	m = int(input())
	a, b, y, z = -10000, -10000, 10000, 10000
	for _ in range(m):
		x1, y1, x2, y2 = map(int, input().split())
		a = max(a, x1)
		b = max(b, y1)
		y = min(y, x2)
		z = min(z, y2)
	s = max(0, y-a) * max(0, z-b)
	print("Cas {}: {}".format(t, s))