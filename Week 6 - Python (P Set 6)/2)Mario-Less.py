# CS50-WEEK6-PSET6-MARIO-LESS
# "Let’s recreate that pyramid (Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks) in C, albeit in text, using hashes (#) for bricks."

import cs50

height = 0

# user input for the height for the pyramid
# while loop checks if the user input is between 1 and 8 (both inclusive)
while height < 1 or height > 8:
    height = cs50.get_int("Height : ")

# prints the pyramid
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * i)