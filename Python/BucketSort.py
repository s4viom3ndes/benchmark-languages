import time

# Average complexity: O(n+k)
# Worst case complexity: O(n^2)

def bucket_sort(arr):
    n = len(arr)
    if n == 0:
        return arr

    # Get the maximum value in the array
    max_value = max(arr)

    # Create n empty buckets
    buckets = [[] for _ in range(n)]

    # Put array elements in different buckets
    for i in range(n):
        index = int(arr[i] * n / (max_value + 1))
        buckets[index].append(arr[i])

    # Sort individual buckets
    for i in range(n):
        buckets[i] = sorted(buckets[i])

    # Concatenate all the buckets
    k = 0
    for i in range(n):
        for j in range(len(buckets[i])):
            arr[k] = buckets[i][j]
            k += 1

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
    arr = bucket_sort(arr)
    end_time = time.perf_counter()
    execution_time_ms = int((end_time - start_time) * 1000)
    print("Execution Time in Milliseconds:", execution_time_ms)
    print('Sorted array:', arr[:10], '...')
