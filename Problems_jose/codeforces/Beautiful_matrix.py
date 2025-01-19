if __name__ == "__main__":
    mat = [[int(i) for i in input().split(" ")]for k in range(5)]
    for file in range(5):
        for row in range(5):
            if(mat[file][row]==1):
                print(abs(file-2) + abs(row-2))
                