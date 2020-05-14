d = {} #dico des voisins
s = input()
while s != "*":
	p = []
	s = s.replace(' ', '')
	n = len(s)
	if n > 4:
		s = input()
		continue
	for a in d:
		if len(a) == n:
			b = True
			c = False
			for i in range(n):
				if s[i] != a[i]:
					if b:
						b = False
					else:
						c = True
						break
			if c: continue
			p.append(a)
			d[a].append(s)
	d[s] = p
	s = input()

v = set() #vues

#parcours en largeur
def f(l, g):
	if l == []:
		return float("inf")
	if g in l:
		return 1
	r = []
	for a in l:
		for b in d[a]:
			if not(b in v):
				v.add(b)
				r.append(b)
	return f(r, g) + 1

#puis on répond aux requêtes
s = input().split()
while s != []:
	v = set([s[0]])
	r = f([s[0]], s[1])
	if r == float("inf"):
		print(s[0], s[1], "impossible")
	else:
		print(s[0], s[1], r)
	try:
		s = input().split()
	except EOFError:
		break