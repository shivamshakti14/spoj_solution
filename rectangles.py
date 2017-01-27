import math
def f(p,i,n):
	if i*i==n:
		return 1
	else:
		return (n/i)- (i-1)

n=int(raw_input())
count=n
p=int(math.sqrt(n))
if n==0 or n==1 or n==2 or n==3:
	print n
else:
	for i in range(2,p+1):
		count+=(f(p,i,n))
	print count