from functions import printWord, printHangMan, endGame
from random import randint

vehicles = ["Vehicles", "car", "bicycle", "plane", "helicopter", "skateboard", "jetski", "boat", "ship"]
pets = ["Pets", "dog", "cat", "bird", "fish", "spider", "lizzard", "snake", "turtle"]

packs = [vehicles, pets]

while True:
    chosen_pack = packs[randint(0, len(packs)-1)]
    chosen_word = chosen_pack[randint(1, len(chosen_pack)-1)]
    tag = chosen_pack[0]
    word =[]


    for letter in chosen_word:
        word.append(letter)

    stage = 0
    score = 0

    letters = []

    while stage <= 4:

        if score == len(word):
            printHangMan(stage)
            printWord(word, tag)
            print(f"You guessed it! The word was: {chosen_word}!")

            reset = endGame()
            if reset == True:
                break
            else:
                quit()

        printHangMan(stage)
        printWord(word, tag)

        if stage >= 4:
            print(f"\nThe word was: {chosen_word}!")
            print("Game Over!")
            reset = endGame()
            if reset == True:
                break
            else:
                quit()

        print("Letters Guessed: ", end='')
        for r in range(len(letters)):
            if r == 0:
                print(letters[0], end='')
            else:
                print("-", end='')
                print(letters[r], end='')
        print("\n\n")

        letter_guess = str(input("Which letter do you wanna guess?\n-> "))

        r_flag = 0

        for r in range(len(letters)):
            if letter_guess == letters[r]:
                r_flag = 1
            else:
                r_flag = r_flag

        if r_flag == 0:
            letters.append(letter_guess)
            flag = 0

            for r in range(len(word)):
                if letter_guess == word[r]:
                    flag = 1
                    break
                else:
                    flag = 0

            if flag == 0:
                stage += 1
            elif flag == 1:
                for r in range(len(word)):
                    if letter_guess == word[r]:
                        word[r] = word[r].capitalize()
                        score += 1
                    else:
                        continue
        else:
            print("This letter has already been guessed!")