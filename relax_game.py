from math import factorial
while 1:
	n1,n2=map(int,raw_input().split())
	if n1==-1:
		break
	s1 = n1+n2
	s2 = (factorial(n1+n2))/(factorial(n1)*factorial(n2))
	if s1==s2:
		print str(n1)+'+'+str(n2)+'='+str(s1)
	else:
		print str(n1)+'+'+str(n2)+'!='+str(s1)