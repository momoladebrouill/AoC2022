from pprint import pprint

f = open("input", "r").read()
f = f.split("\n")[:-1]


class Monkey:
    def __init__(self, lines):
        self.number = int(lines[0].split()[1][:-1])
        self.items = [
            int(e[: e.index(",")] if "," in e else e)
            for e in lines[1][lines[1].index(":") :].split()[1:]
        ]
        self.oper = lines[2][19:]
        self.operlist=self.oper.split()
        print(self.operlist)
        self.test = int(lines[3].split()[-1])
        self.istrue = int(lines[4].split()[-1])
        self.isfalse = int(lines[5].split()[-1])
        self.salary = 0

    def work(self, coworkers,mo):
        for item in self.items:
            old = item
            item = eval(self.oper)%mo
            coworkers[
                self.istrue if item % self.test == 0 else self.isfalse
            ].items.append(item)
            self.salary += 1
        self.items = []

    def __repr__(self):
        return str(
            [self.number, self.items, self.oper, self.test, self.istrue, self.isfalse]
        )


monkeys = []
mo=1
for i in range(0, len(f), 7):
    m=Monkey(f[i : i + 7])
    monkeys.append(m)
    mo*=m.test
print(mo)
for i in range(10000):
    for monk in monkeys:
        monk.work(monkeys,mo)

l = []
for monk in monkeys:
    l.append(monk.salary)
l.sort()
print(l[-1] * l[-2])
