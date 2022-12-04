f = open("input", "r").read()
f = f.split("\n")[:-1]

p1 = 0
p2 = 0
for ligne in f:
    (a1, a2), (b1, b2) = ((int(n) for n in e.split("-")) for e in ligne.split(","))
    p1 += (a1 <= b1 and b2 <= a2) or (b1 <= a1 and a2 <= b2)
    p2 += (
        (a1 <= b1 and b1 <= a2)
        or (a1 <= b2 and b2 <= a2)
        or (b1 <= a1 and a1 <= b2)
        or (b1 <= a2 and a2 <= b2)
    )

print(p1, p2)
