from pprint import pprint
f = open("input", "r").read()
f = f.split("\n")[:-1]
stacks=[[i] for i in range(8)]
i=0
for ligne in range(8):
    s=input()
    for char in range(0,35,4):
        stacks[i].append(s[char:char+3])
    i+=1
ss=[[i] for i in range(10)]
for i in range(10):
    for j in range(8):
        ss[i].append(stacks[j][i])
ss=ss[1:]
for e in ss : 
    e.pop(0)
    e.reverse()
    e.append("   ")
sss=[]
for e in ss : sss.append(e[:e.index("   ")])
input()
input()
for _ in range(501):
    s=input()
    # "move %s from %s to %s"
    s=s.split()
    qqty=int(s[1])
    orig=int(s[3])-1
    dest=int(s[5])-1
    sss[dest]=sss[dest]+sss[orig][-qqty:]
    sss[orig]=sss[orig][:-qqty]

pprint(sss)
for e in sss:
    print(e[-1][1] if e else '//',end='')
