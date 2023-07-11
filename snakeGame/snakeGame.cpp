#include "Board.h"
#include "Fps.h"
#include "Player.h"

int main() {
	int delay = 0;
	
	Board board(30, 30);
	Fps fps;

	Player player(&board);

	
	

	auto startTime = std::chrono::high_resolution_clock::now();


	while (1) {
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

		player.move();

		board.addToMatrix(player.x, player.y, 1);
		


		board.print();
		board.cleanMatrix();

		fps.counter();

		if (deltaTime < 80) {
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