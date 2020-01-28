import matplotlib.pyplot as plt
import numpy as np
import os

ALGORITHMS = [
    'BEST',
    'DFS',
    'BFS',
    'ASTAR'
]
SOLUTION_FOLDER_NAME_FORMAT = 'data/%s_solutions'
ERR_NO_DATA_FORMAT = 'Please generate some data for %s before running this app!'


class MatrixSolution:
    def __init__(self, file_name):
        self.file_name = file_name
        with open(self.file_name, 'r') as f:
            try:
                self._solution = f.readlines()[0]
            except:
                self._solution = 'NONE'
            f.close()

    def __str__(self):
        return self._solution

    @property
    def count(self):
        return len(str(self).split(','))


def create_graph():
    linestyles = {
        'BEST': '-',
        'DFS': '--',
        'BFS': '.-',
        'ASTAR': '--'
    }
    fig = plt.figure()
    for algorithm in ALGORITHMS:
        algorithm_solutions_folder = SOLUTION_FOLDER_NAME_FORMAT % algorithm
        if not os.path.exists(algorithm_solutions_folder) or not os.listdir(algorithm_solutions_folder):
            print(ERR_NO_DATA_FORMAT % algorithm)
            exit(1)

        import glob, re
        solution_data = dict()
        files = glob.glob(algorithm_solutions_folder + "/matrix*.txt")
        for file_name in files:
            dim = re.search('\\d+', file_name).group(0)
            solution_data.setdefault(str(dim), []).append(MatrixSolution(file_name))
        x, solutions = zip(*sorted(solution_data.items()))
        y = list(np.average(list(res.count for res in results)) for results in solutions)
        plt.plot(x, y, linestyles[algorithm], label=algorithm, linewidth=4.0);
    plt.title("Benchmark results")
    plt.xlabel("N")
    plt.ylabel("avg. Nodes in solution");
    plt.legend()
    plt.savefig('result1.png')


if __name__ == '__main__':
    create_graph()
