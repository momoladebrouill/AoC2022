from pprint import pprint

f = open("input", "r").read()
"""f=noop
addx 3
addx -5
"""
f = f.split("\n")[:-1]

l = [l.split(" ") + [0] for l in f]

for i in range(len(l)):
    if l[i][0] == "noop":
        l[i][-1] = 1
    elif l[i][0] == "addx":
        l[i][-1] = 2
        l[i][1] = int(l[i][1])
    else:
        print("arra")

X = 1


def isallpos(l):
    for e in l:
        if e[-1] >= 0:
            return True
    return False


loop = 1
posx = 0
s = 0
while loop <= 260:
    i = 0
    posx += 1
    if (posx) % 40 == 0:
        posx = 0

    if abs(posx - 1 - X) < 2:
        print("#", end="")
    else:
        print(".", end="")
    if posx == 0:
        print()
    # print("%3d" % loop,end='')
    # print(loop,':')

    while i < len(l):
        l[i][-1] -= 1
        if l[i][-1] == 0:
            if l[i][0] == "addx":
                X += l[i][1]
            # print("end of",l[i][0])
            l.pop(i)
        i = len(l) + 1
        i += 1
    loop += 1

print()
