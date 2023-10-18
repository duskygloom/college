from matplotlib.figure import Figure
from matplotlib.axes import Axes
import config, numpy, math

def setup_graph(fig: Figure, axis: Axes, n_signals: int):
    fig.set_figwidth(n_signals)
    fig.set_figheight(config.amplitude*2 + 1)
    axis.set_title("NRZ-L")
    axis.set_ylabel("Signal")
    axis.set_yticks(numpy.arange(-config.amplitude, config.amplitude+1, 1))
    axis.set_ylim(-config.amplitude-0.5, config.amplitude+0.5)
    axis.set_xlabel("Time")
    axis.set_xticks(numpy.arange(0, n_signals+1))
    axis.set_xlim(-0.5, n_signals+0.5)
    tick_spacing = config.bit_duration / config.samples_per_bit_duration
    axis.set_xticklabels([round(i, 2) for i in numpy.arange(0, tick_spacing*(n_signals+1), tick_spacing)])
    axis.plot([0, n_signals], [0, 0], linestyle="dashed", color="gray")

def plot_nrzl_graph(axis: Axes, signals: list[int]):
    x_values, y_values = [], []
    for i in range(len(signals)):
        y_values.append(signals[i])
        x_values.append(i)
        y_values.append(signals[i])
        x_values.append(i+1)
    axis.plot(x_values, y_values)

def save_graph(fig: Figure, n_signals: int):
    fig.savefig(config.figfile, bbox_inches="tight", pad_inches=0.4)
