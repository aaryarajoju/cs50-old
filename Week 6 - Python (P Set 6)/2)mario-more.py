import cs50

height = 0

while height < 1 or height > 8:
    height = cs50.get_int("Height : ")

for i in range(1, height + 1):
    print(" " * (height - i), "#" * (i),"",  "#" * (i))
