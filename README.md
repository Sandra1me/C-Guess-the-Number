# Guess the Number (C)

**Guess the Number** is a console-based game written in C where the player tries to guess a randomly generated secret number. It features multiple difficulty levels and a customizable range option.

## Gameplay

When you start the program, you can choose from 4 difficulty levels:

- **Easy**: Number between 1 and 10.
- **Medium**: Number between 1 and 50, with intermediate hints.
- **Hard**: Number between 1 and 100, with more precise and challenging hints.
- **Custom Range**: You define the minimum and maximum values for the guessing range.

After correctly guessing the number, the game will display how many attempts it took and ask if you'd like to play again.

## Compilation

You can compile the program using `gcc`:

```bash
gcc guess_the_number.c -o guess_the_number
```

And run it with:

```bash
./guess_the_number
```

<img width="725" height="626" alt="gameplay in hard mode" src="https://github.com/user-attachments/assets/0bcb6fd1-22bf-4459-aba5-27a41bfc6718" />


## Contributing

This is a personal learning project, but contributions, suggestions, and improvements are welcome!

## License

This project is licensed under the [MIT Licence](https://choosealicense.com/licenses/mit/).
