def gen_mat(N):
    from random import randint
    mat = list(list(str(randint(-1, 9)) for _ in range(N + 1)) for __ in range(N + 1))
    return "\n".join(list(",".join(row) for row in mat))


def gen_matricies(lower_bound,upper_bound,step=1):
    folder_name = "matricies/"
    file_name_format = folder_name+"matrix[%dx%d].txt"
    import os
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    for N in range(lower_bound,upper_bound,step):
        with open(file_name_format % (N, N), 'w') as _f:
            mat_str = gen_mat(N)
            print(mat_str)
            _f.write(gen_mat(N))
            _f.write("\n0,0\n36,26\nend\n")
            _f.close()


if __name__ == '__main__':
    gen_matricies(5,6)
