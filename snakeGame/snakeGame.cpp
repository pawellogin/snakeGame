#include "Board.h"
#include "Fps.h"
#include "Player.h"
#include "Fruit.h"

int main() {
	int delay = 0;
	int points = 0;

	Board board(20, 20);
	Fps fps;
	Player player(&board);
	Fruit* fruit = new Fruit(&board);

	auto startTime = std::chrono::high_resolution_clock::now();

	while (1) {
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

		player.move();

		board.addToBoard(player.getX(), player.getY(), 43);
		board.addTailToBoard(player.getTail());

		if (player.getX() == fruit->getX() && player.getY() == fruit->getY()) {
			points += fruit->getPoint();
			player.growTail();

			do {
				delete fruit;
				fruit = new Fruit(&board);
			} while (board.display->buffer[fruit->getY()][fruit->getX() * 2] != 0);
		}

		if (board.display->buffer[fruit->getY()][fruit->getX() * 2] != 0) {
			exit(4);
		}

		board.addToBoard(fruit->getX(), fruit->getY(), fruit->getColor());

		std::cout << "\033[40m" << "Points : " << points << "\n";

		board.print();
		board.cleanBoard();

		fps.counter();

		if (deltaTime < 120) {
			delay++;
			std::chrono::milliseconds duration(delay);
			std::this_thread::sleep_for(duration);
		}
		else {
			std::chrono::milliseconds duration(delay);
			std::this_thread::sleep_for(duration);
		}
		startTime = currentTime;
	}

	return 0;
}