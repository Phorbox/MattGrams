from cgitb import small


a = [0, 1, 2, 6, 9, 11, 15]
b = [1, 2, 3, 4, 6, 9, 11, 15]
c = [0, 1, 2, 3, 4, 5, 6]

# this is for python 3.10.5
# it only works on sorted array of non negative distinct integers
def smallest(arr):
    smaller = 0 #start with smallest possible integer
    for each in arr: #loop through each number
        if each > smaller: #find a larger number than smallest 
            return smaller #smallest new number
        smaller+=1 #else increase smallest new number
    return smaller #edge case: no missing number, return next int

print(smallest(a))
print(smallest(b))
print(smallest(c))