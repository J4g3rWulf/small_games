def printWord(word, tag):
    '''

    :param word:
    :param tag:
    :return:
    '''
    print(f"Tag: {tag}")
    print("Word: ", end='')
    for r in range(len(word)):
        if word[r].islower() == True:
            print("_", end='')
        elif word[r].isupper() == True:
            print(word[r], end='')

def printHangMan(stage):
    '''

    :param stage:
    :return:
    '''
    print("\n")
    if stage == 0:
        print("------\n"
              "|    |\n"
              "|     \n"
              "|     \n"
              "|     \n"
              "|     \n")
    elif stage == 1:
        print("------\n"
              "|    |\n"
              "|    0\n"
              "|     \n"
              "|     \n"
              "|     \n")
    elif stage == 2:
        print("------\n"
              "|    |\n"
              "|    0\n"
              "|   /|\\ \n"
              "|     \n"
              "|     \n")

    elif stage == 3:
        print("------\n"
              "|    |\n"
              "|    0\n"
              "|   /|\\ \n"
              "|    |\n"
              "|     \n")
    elif stage == 4:
        print("------\n"
             "|     |\n"
             "|     0\n"
             "|    /|\\ \n"
             "|     |\n"
             "|     /\\ \n")

def endGame():
    '''
    
    :return:
    '''
    end = int(input("Wanna play again?\n[1 - Yes | 2 - No] -> "))
    if end == 2:
        return False
    else:
        return True