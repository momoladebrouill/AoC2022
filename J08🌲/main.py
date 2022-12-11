from pprint import pprint

f = open("input", "r").read()
f = f.split("\n")[:-1]

w = len(f[0])
h = len(f)

s = 0


def is_visible(xt, yt):
    vx1, vx2, vy1, vy2 = 0, 0, 0, 0

    ct = 0
    for x in range(xt - 1, -1, -1):
        ct += 1
        if x != xt and f[x][yt] >= f[xt][yt]:
            break

    vx1 = ct
    ct = 0
    for x in range(xt + 1, w, 1):
        ct += 1
        if x != xt and f[x][yt] >= f[xt][yt]:
            break

    vx2 = ct
    ct = 0
    for y in range(yt - 1, -1, -1):
        ct += 1
        if y != yt and f[xt][y] >= f[xt][yt]:
            break

    vy1 = ct
    ct = 0
    for y in range(yt + 1, h, 1):
        ct += 1
        if y != yt and f[xt][y] >= f[xt][yt]:
            break
    vy2 = ct
    #    print(vx1,vx2,vy1,vy2,'|',xt,yt,'|',vx1*vx2*vy1*vy2)
    return vx1 * vy1 * vx2 * vy2


l = []
for x in range(w):
    for y in range(h):
        l.append(is_visible(x, y))

print(max(l))
