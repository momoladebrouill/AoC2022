f=open("input").read()
f=f.split("\n")[:-1]
same={"A":"X","B":"Y","C":"Z"}
score=0
lose={"A":3,"B":1,"C":2}
draw={"A":1,"B":2,"C":3}
win={"A":2,"B":3,"C":1}

for ligne in f:
    adv=ligne[0]
    moa=ligne[2]
    if moa=="X":
        score+=lose[adv]
    elif moa=="Y":
        score+=draw[adv]+3
    elif moa=="Z":
        score+=win[adv]+6
  
print(score)
