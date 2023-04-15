#Started on 2/6/2023
import random

random_number = random.randint(1, 100)
print("Welcome to the Guess the Number Between 1-100 Game!!!")
num_guesses = int(input("How many Guesses do you Want??: "))
user_val = int(input("Enter Guess: "))

while (random_number != user_val and num_guesses > 1):
    if(random_number > user_val):
        print("Guess is too low, Try Again...")
        user_val = int(input("Enter Guess: "))
    elif(random_number < user_val):
        print("Guess is too High, Try Again...")
        user_val = int(input("Enter Guess: "))
    num_guesses -= 1

if(random_number == user_val and num_guesses > 1):
    print("\nCongrats, You Have Won!")
else:
    print("\nYou have ran out of Guesses, You Lost!")

print("The Random Number was " + str(random_number))