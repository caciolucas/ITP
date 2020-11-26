import numpy as np
import csv
import subprocess
def import_or_install(package):
    try:
        __import__(package)
    except ImportError:
        print("Instalando {}...".format(package))
        print("Não se preocupe, só sera instalada uma vez ;)")
        subprocess.call("python -m pip install {} -q".format(package))
        print("{} instalada".format(package))

import_or_install('matplotlib')
import_or_install('itertools')
import matplotlib.pyplot as plt
from matplotlib.widgets import Button
import itertools

s0 = []
i0 = []
r0 = []
d0 = []
c0=[s0,i0,r0,d0]
s1 = []
i1 = []
r1 = []
d1 = []
c1=[s1,i1,r1,d1]
s2 = []
i2 = []
r2 = []
d2 = []
c2=[s2,i2,r2,d2]
t = []
x = 0


with open("output2.csv", 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        if x:
            s0.append(float(row[0]))
            i0.append(float(row[1]))
            r0.append(float(row[2]))
            d0.append(float(row[3]))
            s1.append(float(row[4]))
            i1.append(float(row[5]))
            r1.append(float(row[6]))
            d1.append(float(row[7]))
            s2.append(float(row[8]))
            i2.append(float(row[9]))
            r2.append(float(row[10]))
            d2.append(float(row[11]))
            t.append(float(row[12]))      
        else:
            x += 1

fig, (a0,a1,a2) = plt.subplots(1, 3)
fig.suptitle('Gráficos S.I.R.M.')

for linha0 in c0:
    a0.plot(t,linha0)

for linha1 in c1:
    a1.plot(t,linha1)
    
for linha2 in c2:
    a2.plot(t,linha2)

plt.show()