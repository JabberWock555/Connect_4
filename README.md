# Connect_4
 # Text-Based Connect-4 Game

![https---image roku com-developer_channels-prod-3c3c8027910a2d232d52ac704f08175b4d18479b205eb57c3289caa7c6719332](https://github.com/JabberWock555/Connect_4/assets/97807224/a7e29ffd-bd8c-48ae-93f0-ea59a374c4ad)


This repository contains a text-based implementation of the classic board game Connect-4, written in C++. The game is designed to be played by two players who take turns inserting their colored coins into the game board in an attempt to align four of their coins in a row, either vertically, horizontally, or diagonally.

## How to Play

1. Clone the repository to your local machine using the following command:

   ```bash
   git clone https://github.com/JabberWock555/Connect_4.git
   ```

2. Navigate to the project directory:

   ```bash
   cd connect-4
   ```

3. Compile the game by running the following command:

   ```bash
   g++ connect4.cpp -o connect4
   ```

4. Run the game:

   ```bash
   ./connect4
   ```

5. The game will prompt the players to enter their moves. Each player should input the column number (ranging from 1 to 7) where they want to drop their coin.

6. The game board will be displayed after each move, showing the current state of the game. Red coins are represented by 'R', blue coins by 'B', and empty positions by spaces (' ').

7. The game will continue until one player successfully aligns four of their coins in a row, or until the entire game board is filled with no winner.

8. If a player wins, the game will display a congratulatory message. If the game ends in a draw, it will be declared as such.

9. To play again, simply run the game again.

## Requirements

- C++ compiler (supporting C++11 or later)

## Contributing

Contributions are welcome! If you have any ideas or suggestions to improve the game, feel free to open an issue or submit a pull request. Make sure to follow the existing coding style and include appropriate tests for new features.

## License

This project is licensed under the [MIT License](LICENSE).

Enjoy the game! May the best strategist win!
