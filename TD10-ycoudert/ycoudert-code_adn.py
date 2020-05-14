N = int(input())
for t in range(N):
	s = input()
	r = ""
	i = 0
	n = 0
	c = s[0]
	for d in s[1:]:
		if d >= '0' and d <= '9':
			n = 10 * n + ord(d) - 48
		elif n == 0:
			r += c
			c = d
		else:
			r += c*n
			n = 0
			c = d
	if n == 0:
		r += c
	else:
		r += c*n
	print("Cas {}: {}".format(t+1, r))