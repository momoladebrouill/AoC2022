from pprint import pprint

f = open("test", "r").read()
f = f.split("\n")[:-1]
moves = []
dico = {"R": (1, 0), "L": (-1, 0), "U": (0, 1), "D": (0, -1), "N": (0, 0)}


for line in f:
    d, nb = line.split(" ")
    nb = int(nb)

    moves.append((d, nb))

xh, yh = 0, 0
tails = [[0, 0] for i in range(10)]
tailsh = []
nb = 0

for d, nb in moves:
    x = dico[d][0]
    y = dico[d][1]
    for i in range(nb):
        tails[0][0] += x
        tails[0][1] += y
        for an in range(1, 10):
            if (
                abs(tails[an - 1][0] - tails[an][0]) >= 2
                and abs(tails[an - 1][1] - tails[an][1]) >= 2
            ):

                tails[an][1] = (tails[an - 1][1] + tails[an][1]) // 2
                tails[an][0] = (tails[an - 1][0] + tails[an][0]) // 2
            elif abs(tails[an - 1][0] - tails[an][0]) >= 2:
                tails[an][0] = (tails[an - 1][0] + tails[an][0]) // 2
                tails[an][1] = tails[an - 1][1]

            elif abs(tails[an - 1][1] - tails[an][1]) >= 2:
                tails[an][1] = (tails[an - 1][1] + tails[an][1]) // 2
                tails[an][0] = tails[an - 1][0]

            if an == 9:
                tailsh.append((tails[an][0], tails[an][1]))

tailsh = set(tailsh)
print(len(tailsh))
