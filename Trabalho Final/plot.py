import matplotlib.pyplot as plt
import csv,sys

s = []
i = []
r = []
t = []
x=0
with open(sys.argv[1],'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        if x:
            s.append(float(row[0]))
            i.append(float(row[1]))
            r.append(float(row[2]))
            t.append(float(row[3]))
        else:
            x+=1

plt.plot(t,s, label='S')
plt.plot(t,i, label='I')
plt.plot(t,r, label='R')
plt.xlabel('Horas')
plt.ylabel('Pessoas')
plt.title('Grafico SIR')
plt.legend()
plt.show()
