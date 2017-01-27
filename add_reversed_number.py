t=int(raw_input())
while t:
	m,n=map(str,raw_input().split())
	m=m[::-1]
	n=n[::-1]
	s=str(int(m)+int(n))
	print int(s[::-1])
	t-=1