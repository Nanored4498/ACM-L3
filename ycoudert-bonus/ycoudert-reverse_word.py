N = int(input())
for i in range(N):
	l = input().split()
	l.reverse()
	print("Case #{}:".format(i+1), end='')
	for w in l:
		print(" "+w, end='')
	print()