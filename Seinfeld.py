count=0
while 1:
	s=raw_input()
	if '-' in s:
		break
	t1=0
	ans=0
	count+=1
	for i in range(0,len(s)):
		if s[i]=='{':
			t1+=1
		elif s[i]=='}' and t1>0:
			t1-=1
		elif s[i]=='}' and t1==0:
			t1+=1
			ans+=1
	print str(count)+'. '+str(ans + ((t1)/2))