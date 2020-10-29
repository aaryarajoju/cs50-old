#CS50-WEEK1-PSET1-HELLO
#"Modify the Hello World program in such a way that it first prompts the user for their name and then prints 'hello, so-and-so', where 'so-and-so' is their actual name."

import cs50
#user input for user's name
name = cs50.get_string("What is your name? ")
#prints a personalized hello
print("Hello,",name)
