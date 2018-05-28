F = int(input())

for _ in range(F):
	N, M, W = list(map(int, input().split()))
	c = []
	for _ in range(M):
		S, E, T = list(map(int, input().split()))
		c.append((S-1, E-1, T))
		c.append((E-1, S-1, T))
	for _ in range(W):
		S, E, T = list(map(int, input().split()))
		c.append((S-1, E-1, -T))
	# Je sais plus comment s'appelle cet algo mais ça marche x)
	bo = False
	s = [False] * N # est ce qu'on a déjà vu le sommet
	for i in range(N):
		if s[i]: #si on a déjà vu le sommet, pas le peine de refaire l'algo à partir de lui
			continue
		d = [float("inf")] * N # d[j] = distance de i à j
		d[i] = 0
		for j in range(N):
			bo = False # est ce qu'on a mis à jour la distance d'un sommet ?
			for S, E, T in c: # on met à jour les disantces avec chaque arrête
				de = d[S] + T
				if de < d[E]:
					bo = True
					d[E] = de
			if not(bo): # si aucun sommet n'a été mis à jour, on arrête
				break
		if bo: #si à la dernière étape un sommet a été mis à jour alors il y a un cycle de poids négatif
			break
		for j in range(N): # On met à jour les sommets rencontrés
			s[j] = True
	if bo:
		print("OUI")
	else:
		print("NON")