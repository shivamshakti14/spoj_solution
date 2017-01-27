def merge(a,f,mid,l):
	count=0
	n1=mid-f+1
	n2=l-mid
	L=[0]*(n1+1)
	R=[0]*(n2+1)
	for i in range(0,n1):
		L[i]=a[f+i]
	for i in range(0,n2):
		R[i]=a[mid+i+1]
	L[n1]=10000000
	R[n2]=10000000
	i=0
	j=0
	#print L,R
	for k in range(f,l+1):
		if i<n1 and L[i]<=R[j]:
			a[k]=L[i]
			i+=1
		elif j<n2 and R[j]<L[i]:
			count+=(mid-(i+f)+1)
			a[k]=R[j]
			j+=1
	return count

def merge_sort(a,f,l):
	if f<l:
		mid  = (f+l)/2
		l1 = merge_sort(a,f,mid)
		l2 = merge_sort(a,mid+1,l)
		l3 = merge(a,f,mid,l)
		return l1+l2+l3
	else:
		return 0

t=int(raw_input())
while t:
	raw_input()
	n=int(raw_input())
	count=0
	l=[]
	for i in range(0,n):
		l.append(int(raw_input()))
	print merge_sort(l,0,n-1)
	
	t-=1