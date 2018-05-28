from heapq import *

L, N, M = list(map(int, input().split()))

p = [0, L]
for _ in range(N):
	d = int(input())
	p.append(d)
p.sort()
d = []
for i in range(N):
	d0 = p[i+2] - p[i+1]
	d1 = p[i+1] - p[i]
	d.append((min(d0, d1), max(d0, d1), i+1))
heapify(d)
for i in range(N+2):
	p[i] = [p[i], i-1, i+1]
s = [0] * (N+2) 

c = 0
while c < M:
	_, _, i = heappop(d)
	if s[i] == 0:
		c += 1
		_, a, b = p[i]
		#on met à jour les voisins
		p[a][2] = b
		p[b][1] = a
		#on dit qu'on rajoute un a et un b
		s[a] += 1
		s[b] += 1
		#on modifie le tas
		for x in [a, b]:
			if x == 0 or x == N+1:
				continue
			po, aa, bb = p[x]
			d0 = po - p[aa][0]
			d1 = p[bb][0] - po
			heappush(d, (min(d0, d1), max(d0, d1), x))
	else:
		s[i] -= 1

while True:
	res, _, i = heappop(d)
	if s[i] == 0:
		print(res)
		break
	s[i] -= 1