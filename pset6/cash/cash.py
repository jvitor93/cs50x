from cs50 import get_float

# Getting user input correctly
while True:
    dl = int(100 * get_float("Change ($): "))
    if dl >= 0:
        break
# Initializing manipulated variables
coins = [25, 10, 5, 1]
total = dl
coin_counter = 0
# Iterating and counting coin usage
for c in coins:
    rem = total % c
    coin_counter = coin_counter + (total - rem) / c
    total = rem
# Printing Total
print(int(coin_counter))