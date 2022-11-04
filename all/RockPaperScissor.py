import os
import re
import random

os.system('cls' if os.name == 'nt' else 'clear')

while (1<2):
    print("RockPaperScissors Game")
    player = input("Your chance, [R]ock,[P]aper,[S]cissor:")

    if not re.match('[RrPpSs]',player):continue

    choices = ['R','P','S']
    opponent = random.choice(choices)
    print('You choose:' + player)
    print('I choose:' + opponent)

    if opponent == str.upper(player):
        print('Its Tie')
        continue

    if opponent == 'R' and player.upper() == 'S':
        print('Rock beats Paper, I Won')
        continue

    if opponent == 'S' and player.upper() == 'P':
        print('Scissor beats Paper, I Won')
        continue

    if opponent == 'P' and player.upper() == 'R':
        print('Paper beats Rock, I Won')
        continue

    else:
        print('You Won')
        continue