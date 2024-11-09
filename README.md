# Word Game Project

This project is a word game implemented in Python and C, where the player and the computer take turns to say words. Each word must start with the last letter of the previous word said by the other player.

## Overview

In this game:
- The player enters a word, and the computer responds with a word that starts with the last character of the player's word.
- The game continues until the player makes an invalid move (the word doesn't start with the required character).
- The game ends when the computer cannot find a word starting with the required character.

The words used in the game are fetched from a web page using Python, saved into a text file, and then read by the C program to form the list of valid words.

## Requirements

- Python 3
- C compiler (e.g., GCC)
- Libraries:
    - Python: `requests`, `BeautifulSoup4`

## How It Works

### Python Part

The Python script `word_generator.py` does the following:
- Fetches a list of the top 3000 English words from a webpage.
- Extracts the words and processes them by splitting them into a dictionary based on their starting letter.
- Randomly selects words to write into a file called `data.txt`.

The Python script is run from the C program, which reads the data from the `data.txt` file for gameplay.

### C Part

The C program implements the word game logic:
- It loads the words from the `data.txt` file.
- The player and the computer take turns inputting words.
- The computer checks if a valid word starting with the required letter exists and responds with a random word from the list.

The game continues until the player makes an invalid move or the computer can't find a word.

## Setup

1. Clone this repository to your local machine:

     ```bash
     git clone https://github.com/your-username/word-game.git
     ```

2. Install the necessary Python libraries:

     ```bash
     pip install requests beautifulsoup4
     ```

3. Compile the C program:

     ```bash
     gcc -o word_game word_game.c
     ```

4. Run the program:

     ```bash
     ./word_game
     ```

## Gameplay

1. The game will prompt the player for a word.
2. The player enters a valid word (only alphabetic characters allowed).
3. The computer will respond with a word starting with the last character of the player's word.
4. The game continues in turns until the player loses or the computer can't find a word starting with the required character.

To exit the game, type `0` when prompted for a word.

## Example Gameplay

```plaintext
Welcome.
How this game works?
     In this game, the player starts by writing a word.
After that, the player writes a word that starts with the last character of the computer's last word.
Game keeps going in turns until one of the players loses.

     Write '0' (zero) to exit.

     Let's play.

Your word: apple
My word: elephant
Your word: tiger
My word: rabbit
...
You have lost. Your word 'rat' does not start with 't'.
```

## Contributing

Feel free to fork the repository, make improvements, or suggest new features. If you find any bugs or issues, please open an issue on GitHub.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
