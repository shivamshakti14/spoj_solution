#correct but giving TLE

t=int(raw_input())
while t:
	s=raw_input()
	s1=s[::-1]
	n=len(s)
	l=[[0]*(n+1)]*(n+1)
	#print s,s1
	for i in range(0,n+1):
		for j in range(0,n+1):
			if i==0 or j==0:
				l[i][j]=0
			elif s[i-1]==s1[j-1]:
				l[i][j] = l[i-1][j-1]+1
			else:
				l[i][j] = max(l[i-1][j], l[i][j-1])
	#print l
	print n-l[n][n]
	t-=1