f=open("input.txt")
f=f.read().split("\n")
li=[]
s=0
for l in f:
    if l=="":
        li.append(s)
        s=0
    else:
        s+=int(l)

print(li.sort())
print(li[-1]+li[-2]+li[-3])
