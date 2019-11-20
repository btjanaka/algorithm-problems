r,c=map(int,raw_input().split())
g,m,k=[raw_input() for _ in range(r)],[[0]*c for _ in range(r)],0
v=[[0]*c for _ in range(r)]
def b(w,x,e):
 s=[(w,x)]
 while len(s):
  w,x=s.pop()
  if w<0 or w>=r or x<0 or x>=c or v[w][x] or g[w][x]!=e: continue
  m[w][x]=k;v[w][x]=1;s+=[(w+1,x),(w-1,x),(w,x+1),(w,x-1)]
for i in range(r):
 for j in range(c):
  if not v[i][j]:
   k+=1;b(i,j,g[i][j])
for _ in range(input()):
 w,x,y,z=map(lambda x:int(x)-1,raw_input().split());print('neither' if m[w][x]!=m[y][z] else['binary','decimal'][int(g[w][x])])
