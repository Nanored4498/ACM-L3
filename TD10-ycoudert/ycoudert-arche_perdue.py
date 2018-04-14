T = int(input())
for t in range(1, T+1):
	N, D  = list(map(int, input().split()))
	p = []
	for _ in range(N):
		l = input()
		p.append((int(l[2:]), l[0]))
	p.sort()
	i = 0 #l'index de la plance actuelle
	s = 0 #0 si on prend la prochaine plance S à l'aller et 1 sinon
	r = 0 #résultat
	po = 0 #position
	while i < len(p):
		w, x = p[i]
		if x == 'S':
			if s == 0:
				r = max(w-po, r)
				po = w
				del p[i]
				i -= 1
			s = (s+1)%2
		else:
			r = max(w-po, r)
			po = w
		i += 1
	r = max(D-po, r)
	#le retour
	po = D
	for j in range(len(p)-1, -1, -1):
		w, x = p[j]
		r = max(po-w, r)
		po = w
	print("Case {}: {}".format(t, max(r, po))) #le max vient du dernier saut