#python me crache dessus pour le input() : je ne comprends pas !!!!!

n = int(input())
for _ in range(n):
	s = input()
	r = 1
	p = [1]
	for i in range(1, len(s)):
		p = [a+2 for a in p if a < i and s[i] == s[i-1-a]]
		if s[i] == s[i-1]:
			p.append(2)
		p.append(1)
		r = max(r, p[0])
	print(r)