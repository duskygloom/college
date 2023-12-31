import matplotlib.pyplot as plot

import numpy, webbrowser

class Plotter:
    def __init__(self):
        self.figure, self.axis = plot.subplots()
        self.figfile = None

    def setup(
            self, 
            nsignals: int, 
            title: str, 
            xlabel: str, 
            ylabel: str,
    ):
        fig = self.figure
        axis = self.axis
        fig.set_figwidth(nsignals)
        fig.set_figheight(3)
        axis.set_title(title)
        axis.set_ylabel(ylabel)
        axis.set_yticks((-2, -1, 0, 1, 2))
        axis.set_ylim(-2.5, 2.5)
        axis.set_xlabel(xlabel)
        axis.set_xticks(numpy.arange(0, nsignals+1))
        axis.set_xlim(-0.5, nsignals+0.5)
        axis.set_xticklabels(range(0, nsignals+1))
        axis.plot([0, nsignals], [0, 0], linestyle="dashed", color="gray")

    def plot(self, datafile: str):
        f = open(datafile, "r")
        x = [float(i) for i in f.readline().split()]
        y = [float(i) for i in f.readline().split()]
        f.close()
        self.axis.plot(x, y)

    def save(self, figfile: str):
        self.figure.savefig(figfile, bbox_inches="tight", pad_inches=0.4)
        self.figfile = figfile

    def open(self):
        if self.figfile:
            webbrowser.open(self.figfile)
