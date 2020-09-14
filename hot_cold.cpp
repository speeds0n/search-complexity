#include <iostream>
#include <ctime>

void main_menu(int *range);
void guess_the_number(int *guess);
int main(int argc, char *argv[]){

	int range{0};
	int key{0}, guess{0};/*key is random secret number, guess is the current try*/
	int typed{0}, ;/**/

	if(argc < 2){
		std::cout << "Without command line\nEnding program" << std::endl;
		return 0;
	}else{

		range = std::stoi(argv[1]);/*casting string to int*/
		main_menu(&range);
		srand(time(NULL));/*non repeat rand number*/
		key = rand() % range + 1;
		do{
			if(typed == 0){
				std::cin >> guess;
				typed++;
			}else{
				guess_the_number(&guess);
			}
			if(guess == key){
				std::cout << ">>> Yeah, correct guess!" << std::endl;
				guess = -1;
			}else{
				std::cout << ">>> Nop, try again: ";
			}
		}while(guess > 0);
	}
	return 0;
}

void guess_the_number(int *guess){
	
}

void main_menu(int *range){
	std::cout << "====================================================" << std::endl;
	std::cout << " Welcome to the Hot-Cold Guess game, copyright 2020." << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl << std::endl;
	std::cout << "This are the game rules:" << std::endl;
	std::cout << "\t* I'll choose a random number in [1," << *range << "]. Your job is to guess that number." << std::endl;
	std::cout << "\t* From second guess onward, I'll tell you if you guess" << std::endl;
	std::cout << "\t  if hot(closer than the previous guess) or cold (farther from" << std::endl;
	std::cout << "\t  the previous guess)." << std::endl;
	std::cout << "\t* If you wish to quit the game, just type in a negative number." << std::endl << std::endl << std::endl;
	std::cout << "Good luck!" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
	std::cout << "Guess the number: ";
}
