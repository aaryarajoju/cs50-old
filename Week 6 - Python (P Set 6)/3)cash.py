#CS50-WEEK1-PSET1-CASH
#"When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!).
# Fortunately, computer science has given cashiers everywhere ways to minimize numbers of coins due: greedy algorithms."
#"Suppose that a cashier owes a customer some change and in that cashier’s drawer are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
# The problem to be solved is to decide which coins and how many of each to hand to the customer.
# Think of a “greedy” cashier as one who wants to take the biggest bite out of this problem as possible with each coin they take out of the drawer."

#program to find the lowest number of coins required to cover an amount of change (using the lowest number quarters, dimes, nickles and pennies)

import cs50

change = cs50.get_float("Change owed : ")

#user input for the amount of change in dollars
#while loop checks that the amount entered is non-negative
while change < 0:
    change = cs50.get_float("Change owed : ")

#converting the user input of change in dollars to change in cents
cents = round(change * 100)

coins = 0

#while loop will run till the all of the change is covered
while cents > 0:
    
    #checks if there is a possibility to cover the change with a quarter($0.25)
    #then checks how many quarters would be needed
    if cents >=25:
        cents = cents - 25
        coins = coins + 1
        
    #checks if there is a possibility to cover the change with a dime($0.10)
    #then checks how many dimes would be needed
    elif cents >= 10:
        cents = cents - 10
        coins = coins + 1
        
    #checks if there is a possibility to cover the change with a nickle($0.05)
    #then checks how many nickles would be needed
    elif cents >= 5:
        cents = cents - 5
        coins = coins + 1
        
    #checks how many pennies($0.01) are required to cover the rest of the change
    else :
        cents = cents - 1
        coins = coins + 1

#prints the total number of coins required
print (coins)
