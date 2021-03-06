import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import numpy as np
from tkinter import *
from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
# Implement the default Matplotlib key bindings.
from matplotlib.backend_bases import key_press_handler
import subprocess
import csv


def config_plot():
    fig, ax = plt.subplots()
    ax.set(xlabel='Tempo (h)', ylabel='Pessoas',
           title='Cenário 0 (Padrão)')
    return (fig, ax)


class matplotlibSwitchGraphs:
    def __init__(self, master):
        self.master = master
        self.master.protocol("WM_DELETE_WINDOW", sys.exit)
        self.frame = Frame(self.master)
        self.fig, self.ax = config_plot()
        self.graphIndex = 0
        self.canvas = FigureCanvasTkAgg(self.fig, self.master)
        self.config_window()
        self.draw_graph_one()
        self.frame.pack(expand=YES, fill=BOTH)
        master.bind('<Escape>', sys.exit)

    def config_window(self):
        self.canvas.mpl_connect("key_press_event", self.on_key_press)
        toolbar = NavigationToolbar2Tk(self.canvas, self.master)
        toolbar.update()
        self.canvas.get_tk_widget().pack(side=TOP, fill=BOTH, expand=1)
        self.buttonFrame = Frame(self.master,relief="ridge")        
        self.buttonFrame.pack(side=BOTTOM)
        self.button_switch = Button(
            self.buttonFrame, text="Proximo Cenário", command=self.next_graph)
        self.button_switch.pack(side=RIGHT)
        self.button_switch_before = Button(
            self.buttonFrame, text="Cenário Anterior", command=self.previous_graph)
        self.button_switch_before.pack(side=LEFT)


    def draw_graph_one(self):
        self.ax.clear() 
        self.master.title("Cenario 0")
        global c0, t, styles
        max_y = 0
        for linha in c0:
            index = c0.index(linha)
            max_y = max(linha) if max(linha) > max_y else max_y
            self.ax.plot(t, linha,
                         linestyle=styles[index]['linestyle'],
                         label=styles[index]['label'],
                         markerfacecolor=styles[index]['facecolor'],
                         )
        self.ax.grid()
        self.ax.legend()
        plt.xlim([0, t[-1]])
        plt.ylim([0, max_y+10])

        self.ax.set(xlabel='Tempo (h)', ylabel='Pessoas',
                    title='Cenário 0 (Padrão)')
        self.canvas.draw()

    def draw_graph_two(self):
        self.ax.clear()
        self.master.title("Cenario 1")
        
        global c1, t, styles
        max_y = 0
        for linha in c1:
            index = c1.index(linha)
            max_y = max(linha) if max(linha) > max_y else max_y
            self.ax.plot(t, linha,
                         linestyle=styles[index]['linestyle'],
                         label=styles[index]['label'],
                         markerfacecolor=styles[index]['facecolor'],
                         )
        self.ax.grid()
        self.ax.legend()
        plt.xlim([0, t[-1]])
        plt.ylim([0, max_y+10])

        self.ax.set(xlabel='Tempo (h)', ylabel='Pessoas',
                    title="Cenário 1 (Maior Tempo de Contaminação 'T_b')")
        self.canvas.draw()

    def draw_graph_three(self):
        self.ax.clear() 
        self.master.title("Cenario 2")

        global c2, t, styles
        max_y = 0

        for linha in c2:
            index = c2.index(linha)
            max_y = max(linha) if max(linha) > max_y else max_y
            self.ax.plot(t, linha,
                         linestyle=styles[index]['linestyle'],
                         label=styles[index]['label'],
                         markerfacecolor=styles[index]['facecolor'],
                         )

        self.ax.grid()
        self.ax.legend()
        plt.xlim([0, t[-1]])
        plt.ylim([0, max_y+10])

        self.ax.set(xlabel='Tempo (h)', ylabel='Pessoas',
                    title="Cenário 2 (Menor Tempo de Recuperação 'T_k)")
        self.canvas.draw()

    def on_key_press(self, event):
        key_press_handler(event, self.canvas)

    def _quit(self):
        self.master.quit()  # stops mainloop

    def next_graph(self):
        self.graphIndex = (self.graphIndex + 1) % 3
        if self.graphIndex == 0:
            self.draw_graph_one()
        elif self.graphIndex == 1:
            self.draw_graph_two()
        else:
            self.draw_graph_three()

    def previous_graph(self):
        self.graphIndex = (self.graphIndex + 1) % 3
        if self.graphIndex == 0:
            self.draw_graph_one()
        elif self.graphIndex == 1:
            self.draw_graph_three()
        else:
            self.draw_graph_two()

def main():

    global styles
    styles = [
        {'label': 'Sucetiveis', 'facecolor': 'g', 'linestyle': '-'},
        {'label': 'Infectados', 'facecolor': '#FF8C00', 'linestyle': '-.'},
        {'label': 'Removidos', 'facecolor': 'r', 'linestyle': ':'},
        {'label': 'Mortos', 'facecolor': 'k', 'linestyle': '--'}
    ]

    s0 = []
    i0 = []
    r0 = []
    d0 = []
    s1 = []
    i1 = []
    r1 = []
    d1 = []
    s2 = []
    i2 = []
    r2 = []
    d2 = []
    global t
    t = []
    x = 0

    with open(sys.argv[1], 'r') as csvfile:
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

    global c0
    c0 = [s0, i0, r0, d0]
    global c1
    c1 = [s1, i1, r1, d1]
    global c2
    c2 = [s2, i2, r2, d2]
    root = Tk()
    root.resizable(False,False)
    matplotlibSwitchGraphs(root)
    root.mainloop()


if __name__ == '__main__':
    main()
