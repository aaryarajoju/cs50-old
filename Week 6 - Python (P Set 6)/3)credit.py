import cs50

card = cs50.get_int("Enter card number: ")

num = card
digits = 0
name = 4

while num > 0:
    digits = digits + 1
    num = int(num/10)

if digits == 13 or digits == 15 or digits == 16:

    isCardValid = False
    checkSum = 0
    tempCard = card
    last = tempCard%10

    while tempCard > 0:
        checkSum = checkSum + tempCard % 10
        tempCard = int(tempCard / 10)

        if tempCard % 10 < 5:
            checkSum = checkSum + (2*(tempCard % 10))
            tempCard = int(tempCard/10)
        else :
            checkSum = checkSum + (((2 * (tempCard % 10)) % 10) + 1)
            tempCard = int(tempCard / 10)

    if checkSum%10 == 0 :
        isCardValid = True

    if isCardValid == True :

        first = card
        while first > 10 :
            first = int(first/10)

        firstTwo = card
        while firstTwo>100 :
            firstTwo = int(firstTwo/10)

        if digits == 15 and (firstTwo == 34 or firstTwo == 37):
            name = 1
        elif digits == 16 and (firstTwo == 51 or firstTwo == 52 or firstTwo == 53 or firstTwo == 54 or firstTwo == 55):
            name = 2
        elif (digits == 13 or digits == 16) and first == 4:
            name = 3
        else :
            name = 4

    else :
        name = 4

else :
    name = 4

if name == 1 :
    print("AMEX")
elif name == 2:
    print("MASTERCARD")
elif name == 3:
    print("VISA")
elif name == 4 :
    print("INVALID")
