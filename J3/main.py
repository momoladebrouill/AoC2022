f=open("input").read()
f=f.split("\n")[:-1]

def priorityof(l):
    if l.isupper():
        s=27+ord(l)-ord("A")
    if l.islower():
        s=ord(l)-ord("a")+1
    return s

s=0
for i in range(0,len(f),3):

    l=""
    for l1 in f[i]:
        if l1 in f[i+1] and l1 in f[i+2]:
            l=l1
            break
    s+=priorityof(l)

print(s)
