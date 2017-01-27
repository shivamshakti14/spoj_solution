n,k,s=map(int,raw_input().split())
l=map(int,raw_input().split())
l.sort()
l.reverse()
tot = k*s
count=0
for i in range(0,n):
	tot -= l[i]
	count+=1
	if tot<=0:
		break
print count