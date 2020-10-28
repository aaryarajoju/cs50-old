import cs50

change = cs50.get_float("Change owed : ")

while change < 0:
    change = cs50.get_float("Change owed : ")

cents = round(change * 100)

coins = 0

while cents > 0:
    if cents >=25:
        cents = cents - 25
        coins = coins + 1
    elif cents >= 10:
        cents = cents - 10
        coins = coins + 1
    elif cents >= 5:
        cents = cents - 5
        coins = coins + 1
    else :
        cents = cents - 1
        coins = coins + 1

print (coins)
