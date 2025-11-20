import threading
 
A = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

B = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

n = 3   
 
C = [[0] * n for _ in range(n)]
 
def compute_row(row):
    for j in range(n):
        total = 0
        for k in range(n):
            total += A[row][k] * B[k][j]
        C[row][j] = total

 
if __name__ == "__main__":
    print("Matrix A:")
    for r in A:
        print(r)

    print("\nMatrix B:")
    for r in B:
        print(r)

    threads = []
 
    for i in range(n):
        t = threading.Thread(target=compute_row, args=(i,))
        threads.append(t)
        t.start()
 
    for t in threads:
        t.join()

    print("\nResult Matrix (A x B):")
    for r in C:
        print(r)
