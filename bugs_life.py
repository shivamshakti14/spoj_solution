#This code is correct but shows TLE

def bfs(d,vis,p,l):
	flag=1
	if vis[p-1]==0:
		color=1
	else:
		color=vis[p-1]
	vis[p-1]=color
	try:
		n1=len(d[p])
	except KeyError :
		n1=0
		pass
	for i in range(0,n1):
		try:
			if vis[d[p][i]-1]==0 and color==1:
				l.append(d[p][i])
				vis[d[p][i]-1]=2
			elif vis[d[p][i]-1]==0 and color==2:
				l.append(d[p][i])
				vis[d[p][i]-1]=1
			elif vis[d[p][i]-1]==color:
				flag=0
		except IndexError:
			pass
		#print l,vis,flag
		if flag==0:
			break
	return vis,l,flag

def bipartite(d,v,e,c):
	vis=[0]*(v)
	l=[1]
	flag=1
	while len(l)!=0:
		p=l[0]
		l.remove(l[0])
		vis,l,flag = bfs(d,vis,p,l)
		if flag==0:
			break
	if flag==0:
		print 'Scenario #'+str(c)+':'
		print 'Suspicious bugs found!'
		return
	for i in range(0,v):
		if vis[i]==0:
			l=[i+1]
			color=1
			flag=1
			while len(l)!=0:
				p=l[0]
				l.remove(l[0])
				#if vis[p-1]==0:
				vis,l,flag = bfs(d,vis,p,l)
				if flag==0:
					break
			if flag==0:
				break			
		if flag==0:
			break
	print 'Scenario #'+str(c)+':'
	if flag==0:
		print 'Suspicious bugs found!'
	else:
		print 'No suspicious bugs found!'
	return
t=int(raw_input())
c=0
while t:
	v,e = map(int,raw_input().split())
	d=dict()
	for _ in range(0,e):
		u,v1 = map(int,raw_input().split())
		if u not in d:
			d[u] = [v1]
		else:
			d[u].append(v1)
		if v1 not in d:
			d[v1] = [u]
		else:
			d[v1].append(u)
	bipartite(d,v,e,c+1)
	c+=1
	t-=1
		#else:
		#	if c1==color:
		#		flag=0
		#		break
		#else:
		#	if c1==1:
		#		color=2
		#	else:
		#		color=1
		#	vis,l,flag = bfs(d,vis,p,l,color)