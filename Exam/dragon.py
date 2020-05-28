MAX = 10**15
p2 = [(0, 1)]
while 2 ** len(p2) <= MAX:
	x, y = p2[-1]
	p2.append((x+y, y-x))

def f(n):
	if n == 0: return (0, 0)
	n2, p = n, -1
	while n2 > 0:
		p += 1
		n2 //= 2
	x, y = p2[p]
	if n == (1 << p): return x, y
	n = (1 << (p+1)) - n
	x2, y2 = f(n)
	return x-y2+y, y+x2-x

while True:
	try:
		n = int(input())
		print(*f(n))
	except EOFError:
		exit(0)
