#!/usr/bin/env python
import socket, time
from threading import Thread
import argparse,os

DEFAULT_ALGORITHM_USED = 'BEST'
DEFAULT_TARGET_IP = 'localhost'
DEFAULT_TARGET_PORT = 5600
MATRIX_FOLDER_NAME = 'data/matricies/'
SOLUTION_FOLDER_NAME = ''
DEFAULT_BUFFER_SIZE = 2**14
DEFAULT_SLEEP_TIME = 0.1


class Matrix:
    @property
    def name(self):
        return "matrix_%d" % self._id

    @property
    def full_name(self):
        return "matrix[%dx%d]_%d" % (self._dim, self._dim, self._id)

    @property
    def file_name(self):
        folder_name = MATRIX_FOLDER_NAME + '/' + str(self._dim) + '/'
        if not os.path.exists(folder_name):
            os.makedirs(folder_name)
        return folder_name + self.name + ".txt"

    def __init__(self, dim, id):
        self._dim = dim
        self._id = id

    def __str__(self):
        with open(self.file_name, 'r') as _f:
            return '\n'.join(_f.readlines())


class RandomMatrix(Matrix):

    def __init__(self, dim, id):
        super().__init__(dim, id)
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
        client.connect((DEFAULT_TARGET_IP, args.target_port))
        mat_string = str(matrix)
        for line in mat_string.split('\n'):
            client.send(line.encode('ASCII'))
            time.sleep(DEFAULT_SLEEP_TIME)
        self._solution = client.recv(DEFAULT_BUFFER_SIZE).decode('ASCII')
        client.close()

    def __str__(self):
        return self._solution

    @property
    def count(self):
        return len(str(self).split(','))

    @property
    def file_name(self):
        return SOLUTION_FOLDER_NAME + '/' + self._matrix.full_name + '.txt'


def get_matrices():
    import glob, re
    mats = []
    files = glob.glob(MATRIX_FOLDER_NAME + "/*/*.txt")
    for file_name in files:
        dim, id = re.findall('\\d+', file_name)
        mats.append(Matrix(int(dim), int(id)))
    return mats


def generate_matrices(lower_bound, upper_bound, step=1):
    """

    :type lower_bound: int
    :type upper_bound: int
    :type step: int

    """
    out_list = []
    for N in range(lower_bound, upper_bound, step):
        out_list.extend(list(RandomMatrix(N, id) for id in range(1, 10)))
    return out_list


def generate_data():
    if not os.path.exists('data'):
        os.makedirs('data')
    global SOLUTION_FOLDER_NAME
    SOLUTION_FOLDER_NAME = 'data/%s_solutions/' % args.algorithm
    if os.path.exists(MATRIX_FOLDER_NAME) and not args.force_gen:
        mats = get_matrices()
    else:
        os.makedirs(MATRIX_FOLDER_NAME)
        mats = generate_matrices(10, 51, 10)
        for m in mats:
            m.write()

    threads = []
    solutions = []
    for m in mats:
        solve_thread = Thread(target=lambda l, mat: l.append(MatrixSolution(mat)), args=(solutions, m),
                              name=m.full_name)
        threads.append(solve_thread)
        solve_thread.start()

    for t in threads:
        t.join()

    if not os.path.exists(SOLUTION_FOLDER_NAME):
        os.makedirs(SOLUTION_FOLDER_NAME)
    for sol in solutions:
        with open(sol.file_name, 'w') as f:
            f.write(str(sol))
            f.close()
    return solutions


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--algorithm', '-a', default=DEFAULT_ALGORITHM_USED, )
    parser.add_argument('--force-gen', '-f', default=False, )
    parser.add_argument('--target-port', '-p', default=DEFAULT_TARGET_PORT, type=int)
    args = parser.parse_args()
    generate_data()
