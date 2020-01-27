#!/usr/bin/env python
import socket, time
from threading import Thread
import logging

MATRIX_FOLDER_NAME = 'matricies/'
SOLUTION_FOLDER_NAME = 'ASTAR_solutions/'
DEFAULT_TARGET_IP = 'localhost'
DEFAULT_TARGET_PORT = 5600
DEFAULT_MAX_BACKLOG_SIZE = 5
DEFAULT_BUFFER_SIZE = 1024
DEFAULT_SLEEP_TIME = 0.1


class Matrix:
    @property
    def name(self):
        return "matrix[%dx%d]" % (self._dim, self._dim)

    @property
    def file_name(self):
        return MATRIX_FOLDER_NAME + self.name + ".txt"

    def __init__(self, dim):
        self._dim = dim

    def __str__(self):
        with open(self.file_name, 'r') as _f:
            return '\n'.join(_f.readlines())


class RandomMatrix(Matrix):

    def __init__(self, dim):
        super().__init__(dim)
        from random import randint
        self._mat = list(list(str(randint(-1, 9)) for cell in range(dim)) for row in range(dim))
        for pt in [0, dim - 1]:
            while self._mat[pt][pt] == '-1':
                self._mat[pt][pt] = str(randint(-1, 9))

    def __str__(self):
        out = "\n".join(list(",".join(row) for row in self._mat))
        out += "\n0,0\n" + ("%d,%d" % (self._dim - 1, self._dim - 1)) + "\nend\n"
        return str(out)

    def write(self):
        with open(self.file_name, 'w') as _f:
            _f.write(str(self))
            _f.close()


class MatrixSolution:
    def __init__(self, matrix):
        """
        :type matrix: Matrix
        """
        self._matrix = matrix
        self.name = matrix.name + '_solution'
        client = socket.socket()
        client.connect((DEFAULT_TARGET_IP, DEFAULT_TARGET_PORT))
        mat_string = str(matrix)
        for line in mat_string.split('\n'):
            client.send(line.encode('ASCII'))
            time.sleep(DEFAULT_SLEEP_TIME)
        self._solution = client.recv(DEFAULT_BUFFER_SIZE).decode('ASCII')
        client.close()

    def __str__(self):
        return self._solution

    @property
    def file_name(self):
        return SOLUTION_FOLDER_NAME + '/' + self.name + '.txt'


def get_matrices():
    import glob, re
    mats = []
    files = glob.glob(MATRIX_FOLDER_NAME + "/*.txt")
    for file_name in files:
        dim = int(re.search('\\d\\d', file_name).group(0))
        mats.append(Matrix(dim))
    return mats


def generate_matrices(lower_bound, upper_bound, step=1):
    """

    :type lower_bound: int
    :type upper_bound: int
    :type step: int

    """
    return list(RandomMatrix(N) for N in range(lower_bound, upper_bound, step))


def main():
    import os
    if os.path.exists(MATRIX_FOLDER_NAME):
        mats = get_matrices()
    else:
        os.makedirs(MATRIX_FOLDER_NAME)
        mats = generate_matrices(10, 51, 10)
        for m in mats:
            m.write()

    threads = []
    solutions = []
    for m in mats:
        solve_thread = Thread(target=lambda l, mat: l.append(MatrixSolution(mat)), args=(solutions, m))
        threads.append(solve_thread)
        solve_thread.start()

    for t in threads:
        t.join()

    if not os.path.exists(SOLUTION_FOLDER_NAME):
        os.makedirs(SOLUTION_FOLDER_NAME)
    for sol in solutions:
        with open(sol.file_name, 'w') as f:
            f.write(str(sol))


if __name__ == '__main__':
    main()
