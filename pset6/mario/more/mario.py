from cs50 import get_int

# Check input and reprompt if not in range
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Initialize list to iterate over
hlist = [i for i in range(1, height + 1)]

# printing hashes and spaces
for i in hlist:
    print(" " * (height - i), end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)
