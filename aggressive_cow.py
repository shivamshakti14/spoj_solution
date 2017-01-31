t=int(raw_input())
while t:
	n,c=map(int,raw_input().split())
	l=[]
	#l = map(int,raw_input().split())
	for _ in range(0,n):
		l.append(int(raw_input()))
	l.sort()
	low=0
	high=l[n-1]+1#-l[0]
	#print l
	low_prev=0
	while low<=high:
		mid = low + (high - low)/2
		count=0
		f=l[0]
		for i in range(1,n):
			if l[i]-f>=mid:
				count+=1
				f=l[i]
		#print low,mid,high,count	
		if count>=c-1:
			low_prev=mid
			low = mid+1
		else:
			#low_prev=mid
			high = mid-1

	#if low<high:
	#	low_prev=low
	print low_prev
	t-=1