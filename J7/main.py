from pprint import pprint
f = open("input", "r").read()
f=f.split("\n")[:-1]

class dire:
    def __init__(self, parent,n):
        self.parent=parent
        self.childs=[]
        self.name=n

    def mk(self,t):
        self.childs.append(t)

    def __repr__(self):
        return f"{self.size}:[{self.childs}]"
    
    @property
    def size(self):
        return sum([c.size for c in self.childs])

class fil:
    def __init__(self, size):
        self.size=size
        self.name=""

    def __repr__(self):
        return f"f{self.size}"

home=dire(None,"/")
cur=home

while f:
    line=f[0]
    if line.startswith("$ cd /"):
        cur=home
        f.pop(0)

    elif line.startswith("$ cd "):
        d=len("$ cd ")
        if line[d:]=="..":
            cur=cur.parent
        else:
            for c in cur.childs:
                if c.name==line[d:]:
                    cur=c
                    break
        f.pop(0)

    elif line.startswith("$ ls"):
        f.pop(0)
        line=f[0]

        while not line.startswith("$") and f:
            line=line.split(' ')
            if line[0]=="dir":
                cur.mk(dire(cur,line[1]))
            else:
                cur.mk(fil(int(line[0])))
            f.pop(0)
            try:
                line=f[0]
            except:
                line=""
                #EOF sur ls
    else:
        print(line)
        break

def p(d):
    ms = []
    if d.size >= needed:
        ms.append(d.size)
    for e in d.childs:
        if type(e)==type(d):
            ms+=p(e)
    return ms

needed=-70000000+home.size+30000000
l=p(home)

l.sort()
print(l)
print(needed)
print(l[0])


