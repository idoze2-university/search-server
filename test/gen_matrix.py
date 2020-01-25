def gen_mat(N):
    from random import randint
    mat = list(list(str(randint(-1, 9)) for cell in range(N + 1)) for row in range(N + 1))
    out = "\n".join(list(",".join(row) for row in mat))
    out += "\n0,0\n"+("%d,%d" % (N-1, N-1))+"\nend\n"
    return out


def gen_matricies(lower_bound, upper_bound, step=1):
    folder_name = "matricies/"
    file_name_format = folder_name+"matrix[%dx%d].txt"
    import os
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    for N in range(lower_bound, upper_bound, step):
        with open(file_name_format % (N, N), 'w') as _f:
            _f.write(gen_mat(N))
            _f.close()


if __name__ == '__main__':
    gen_matricies(10, 51, 10)
