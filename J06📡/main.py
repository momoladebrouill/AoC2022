from pprint import pprint

f = open("input", "r").read()
pswrd = ""
i = 0
for e in f:
    pswrd += e
    if len(pswrd) > 14:
        pswrd = pswrd[1:]
    if len(set(pswrd)) == 14:
        print("diff :", pswrd)
        break

    i += 1
    print(pswrd, len(set(pswrd)))
print(i, pswrd)
