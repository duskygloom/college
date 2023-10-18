import sys, os, webbrowser
import utils, plotter, config
from matplotlib import pyplot as plot

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("No file provided.")
        sys.exit()
    elif not os.path.isfile(sys.argv[1]):
        print(f"Invalid file: {os.path.abspath(sys.argv[1])}")
        sys.exit()
    filename = sys.argv[1]
    signals = utils.get_signals(filename)
    # graph
    fig, axis = plot.subplots()
    plotter.setup_graph(fig, axis, len(signals))
    plotter.plot_nrzl_graph(axis, signals)
    plotter.save_graph(fig, len(signals))
    webbrowser.open(config.figfile)
