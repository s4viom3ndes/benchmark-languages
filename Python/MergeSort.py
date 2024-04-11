import time

# Average complexity: O(nlog(n))
# Worst complexity: O(nlog(n))

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
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
    arr = merge_sort(arr)
    end_time = time.perf_counter()
    execution_time_ms = int((end_time - start_time) * 1000)
    print("Execution Time in Milliseconds:", execution_time_ms)
    print('Sorted array:', arr[:10], '...')