# CS50-WEEK6-PSET6-READABILITY
# CS50-WEEK6-PSET6-READABILITY
# "Implement a program that computes the approximate grade level needed to comprehend some text."

import cs50

# gets the text for users to be analyzed
text = cs50.get_string("Text: ")

# initializing the variables
numOfLetters: int = 0
numOfWords: int = 0
numOfSentences: int = 0

# for loop to count the numbers of letters, words and sentences
for i in range(len(text)):
    letter: str = text[i]
    prevLetter: str = text[i-1]

    # counts the number of aphabets
    if (letter.isalpha()):
        numOfLetters = numOfLetters + 1

    # counts the number of words
    elif (letter == ' ' and prevLetter != '.' and prevLetter != '!' and prevLetter != '?'):
        numOfWords = numOfWords + 1

    # counts the number of sentences
    elif (letter == '.' or letter == '!' or letter == '?'):
        numOfSentences = numOfSentences + 1

# total number of words
numOfWords = numOfWords + numOfSentences

# calculating the values of L and S
L = (numOfLetters / numOfWords) * 100
S = (numOfSentences / numOfWords) * 100

# calculating the index
index: int = round((0.0588 * L) - (0.296 * S) - 15.8)

# printing the class
if (index < 1):
    print("Before Grade 1")
elif (index >= 16):
    print("Grade 16+")
else:
    print('Grade', int(index))

