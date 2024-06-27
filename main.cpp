#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#define TRYCOUNT 5
using namespace std;


void draw_man(int try_count) {

	cout << endl << endl;
	cout << "  _____" << endl;
	cout << "  |   |" << endl;
	cout << "  |"; if (try_count >= 1) cout << "   O   "; cout << endl;
	cout << "  |"; if (try_count >= 3) cout << "  /|\\"; cout << endl;
	cout << "  |"; if (try_count >= 5) cout << "  / \\"; cout << endl;
	cout << "  |" << endl;
	cout << "__|__" << endl;
}

int main() {
	srand(time(NULL));
	string words[5] = { "Apple","Pineapple","Banane","cherry","strawberry" };

	string word;
	string guessed;
	word = words[rand() % 5];

	int word_len = word.length();
	string display_word(word_len, '_');

	int found = 0;
	char guess =' ';

	int remain = 5;
	int flag_found = 0;

	while (remain >= 0) {
		system("cls");
		cout << "Find name of Fruit";

		for (int i = 0; i < word.length(); i++) {
			cout << " " << display_word[i] << " ";
		}
		cout << endl;
		cout << endl;
		cout<<"Right remaining:"<<remain<<" / "<<TRYCOUNT<<endl;
		cout << "Tried Letters:" << guessed << endl;

		draw_man(remain);

		if (found == word.length()) {
			cout << "**************" << endl;
			cout << "* You win :) *" << endl;
			cout << "****************" << endl;
			break;
		}

		if (remain == 0) {
			break;
		}

		cout << "Choice a letter:";
		cin >> guess;

		guessed = guessed + " " + guess;

		flag_found = 0; 

		for (int i = 0; i < word.length(); i++) {
			if (word[i] == guess && display_word[i] == '_') {
				display_word[i] = guess;
				found++;
				flag_found = 1;
			}
		}

		if (!flag_found) {
			remain--;
		}
	}

	if (!found == word.length()) {
		cout << "**************" << endl;
		cout << "* You lose :( *" << endl;
		cout << "****************" << endl;
	}

}

