
def solve(p):
	n=len(p)
	if '00' in p or p[0]=='0':
		return 0
	l = [0]*5010
	l[0]=1
	for i in range(1,n):
		m = int(int(p[i-1:i+1]))
		if int(p[i])>0:
			l[i]=l[i-1]
		if m>9 and m<=26:
			if i-2<0:
				l[i]+=l[0]
			else:
				l[i]+=l[i-2]
	return l[n-1]


try:
	while True:
		p=raw_input()
		if p=='0':
			break
		print solve(p)
except:
	pass
