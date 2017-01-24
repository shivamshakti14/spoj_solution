ans={}
ans[0]=0
ans[1]=1
ans[2]=2
def solve(p):
	if p in ans:
		return ans[p]
	else:
		ans[p] = max(p, solve(p/2)+solve(p/3)+solve(p/4))
		return ans[p]
try:
	while True:
		p=int(raw_input())
		print solve(p)
except:
	pass