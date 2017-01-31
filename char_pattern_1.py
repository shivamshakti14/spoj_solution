t=int(raw_input())
while t:
	l,c = map(int,raw_input().split())
	s1=''
	s2=''
	for i in range(0,c):
		if i%2==0:
			s1+='*'
			s2+='.'
		else:
			s1+='.'
			s2+='*'
	for i in range(0,l):
		if i%2==0:
			print s1
		else:
			print s2
	print ''
	t-=1