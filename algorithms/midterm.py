# Python program for implementation of MergeSort
def mergeSort(arr):
    inversioners = 0 # start inversion counter
    if len(arr) > 1:
        # split array
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        # run merge sort on them, but retain their inversion counts
        inversioners += mergeSort(L)
        inversioners += mergeSort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            # pull from left side (no inversions)
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            #pull from the right side (Increase inversions) 
            else:
                arr[k] = R[j]
                j += 1
                # the increase in inversions is the length 
                # of the left array minus current index 
                # (number of remaining values in the array)
                inversioners += len(L)-i
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    # print(f"inv:{inversioners} arr:{arr}")
    return inversioners

# Code to print the list

def mine(arr):
    inversioner = 0
    for each in range(0, len(arr)):  # loop through set
        for rest in range(each, len(arr)):  # look through rest of the set
            if(arr[each] > arr[rest]):  # check invertedness
                inversioner += 1  # increment inversions in case of inversion
                # print(f"\t\t{a[each]} and {a[rest]}")
    return inversioner


a = [51, 57, 60, 17, 38, 88, 28, 9, 59, 40, 5, 37,
     8, 91, 63, 90, 96, 76, 3, 53, 14, 35, 41, 15, 86,
     42, 85, 7, 43, 47, 62, 1, 69, 77, 12, 13, 74, 33,
     24, 98, 4, 52, 67, 20, 80, 93, 70, 71, 50, 87]
b = [1,3,5,2,4,6]

print(f"inversions:\t{mine(b)} set")
print(f"merge inv\t{mergeSort(b)}")
print(f"inversions:\t{mine(a)}")
print(f"merge inv\t{mergeSort(a)}")

