while 1:
	l1=map(int,raw_input().split())
	if len(l1)==1 and l1[0]==0:
		break
	l2=map(int,raw_input().split())
	n1=l1[0]
	n2=l2[0]
	l1=l1[1:]
	l2=l2[1:]
	a1=[]
	a2=[]
	i=0
	j=0
	m1=0
	m2=0
	#print l1,l2
	while i<n1 and j<n2:
		if l1[i]==l2[j]:
			#print l1[i],l2[j]
			a1.append(sum(l1[m1:i+1]))
			a2.append(sum(l2[m2:j+1]))
			m1=i+1
			m2=j+1
			i+=1
			j+=1
		elif l1[i]<l2[j]:
			i+=1
		elif l1[i]>l2[j]:
			j+=1
	s=0
	a1.append(sum(l1[m1:]))
	a2.append(sum(l2[m2:]))
	#print a1,a2
	for i in range(0,len(a1)):
		s += max(a1[i],a2[i])
	print s