n = int(raw_input())
a = []
for i in range(0,n):
    s,kor,eng,math = raw_input().split()
    a.append([s,kor,eng,math])
a = sorted(a,key = lambda e: (-int(e[1]),int(e[2]),-int(e[3]),e[0]))
for i in range(0,n):
    print(a[i][0]) 
