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
