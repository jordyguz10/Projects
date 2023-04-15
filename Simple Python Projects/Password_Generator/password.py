#https://www.101computing.net/random-password-generator/

#For this challenge, we will use a Python script to generate a 
#random password of 8 characters. Each time the program is run, a 
#new password will be generated randomly. The passwords generated 
#will be 8 characters long and will have to include the following 
#characters in any order:

    #2 uppercase letters from A to Z,
    #2 lowercase letters from a to z,
    #2 digits from 0 to 9,
    #2 punctuation signs such as !, ?, “, # etc

#Started on 2/6/2023

import random

print("Creating Random Password of 8 Characters.......")

Uppercase1 = chr(random.randint(65,90))
Uppercase2 = chr(random.randint(65,90))
Lowercase1 = chr(random.randint(97,122))
Lowercase2 = chr(random.randint(97,122))
Dig1 = chr(random.randint(48,57))
Dig2 = chr(random.randint(48,57))
Special1 = chr(random.randint(33,47))
Special2 = chr(random.randint(33,47))

temp = list(Uppercase1 + Uppercase2 + Lowercase1 + Lowercase2\
                + Dig1 + Dig2 + Special1 + Special2)
random.shuffle(temp)
randomPassword = ''.join(temp)
print("Your Random Password is: " + randomPassword)