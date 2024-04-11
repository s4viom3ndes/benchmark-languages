import time

# Average complexity: O(n^2)
# Worst case complexity: O(n^2)

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# numbers are separated by spaces
def read_dataset():
    file = '../Dataset/decreasing_1M.txt'
    with open(file, 'r') as f:
        data = f.read().split()
    return list(map(int, data))

def main():
    arr = read_dataset()
    print('Unsorted array:', arr[:10], '...')
    start_time = time.perf_counter()
    arr = insertion_sort(arr)
    end_time = time.perf_counter()
    execution_time_ms = int((end_time - start_time) * 1000)
    print("Execution Time in Milliseconds:", execution_time_ms)
    print('Sorted array:', arr[:10], '...')