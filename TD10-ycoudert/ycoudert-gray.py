r = ["0"]
v = "0"
for i in range(9999):
	n = len(v)
	if i % 2 == 0:
		v = v[:n-1] + (chr(ord('1')-ord(v[n-1])+ord('0')))
	else:
		for j in range(n-1, -1, -1):
			if v[j] == '1':
				if j == 0:
					v = "1"+v
				else:
					v = v[:j-1] + (chr(ord('1')-ord(v[j-1])+ord('0'))) + v[j:]
				break
	r.append(v)

T = int(input())
for _ in range(T):
	print(r[int(input())])