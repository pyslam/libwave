import sys
import numpy as np
import matplotlib.pylab as plt


if __name__ == "__main__":
    file = open(sys.argv[1], "r")
    X = np.loadtxt(file)
    X = np.matrix(X)
    print(X.shape)

    fig, ax = plt.subplots()
    cax = ax.matshow(X)
    ax.set_xticks(range(0, X.shape[1]))
    ax.set_yticks(range(0, X.shape[0]))
    fig.colorbar(cax)
    plt.show()
