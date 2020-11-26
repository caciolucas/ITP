import csv,sys
import subprocess
import pip

def import_or_install(package):
    try:
        __import__(package)
    except ImportError:
        print("Instalando a matplotlib...")
        print("Não se preocupe, só sera instalada uma vez ;)")    
        subprocess.call("python -m pip install {} -q".format(package))
        print("Matplotlib instalada")  

import_or_install('matplotlib')

import matplotlib.pyplot as plt
s = []
i = []
r = []
d = []
t = []
x=0
with open(sys.argv[1],'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        if x:
            s.append(float(row[0]))
            i.append(float(row[1]))
            r.append(float(row[2]))
            d.append(float(row[3]))
            t.append(float(row[4]))
        else:
            x+=1

plt.plot(t,s, linestyle='-', markerfacecolor='g', label='Sucetíveis')
plt.plot(t,i, linestyle='-.', markerfacecolor='#FF8C00', label='Infectados')
plt.plot(t,r, linestyle=':', markerfacecolor='r', label='Removidos')
plt.plot(t,d, linestyle='--', markerfacecolor='k', label='Mortos')

plt.xlabel('Horas')
plt.ylabel('Pessoas')
plt.title('Grafico SIR')
plt.legend()
plt.show()

# s2 = [-1*i for i in s]
# i2 = [-1*i for i in i]
# r2 = [-1*i for i in r]

# fig, (ax1, ax2) = plt.subplots(1, 2)
# fig.suptitle('Horizontally stacked subplots')
# ax1.plot(t,s, label='S')
# ax1.plot(t,i, label='I')
# ax1.plot(t,r, label='R')
# ax1.set_title('Grafico SIR')
# ax1.set_xlabel('Horas')
# ax1.set_ylabel('Pessoas')

# ax2.plot(t,s2, label='S2')
# ax2.plot(t,i2, label='I2')
# ax2.plot(t,r2, label='R2')
# ax2.set_title('Grafico SIR invertido')
# ax2.set_xlabel('Horas')
# ax2.set_ylabel('Pessoas')


# ax1.legend()
# ax2.legend()
# plt.show()
