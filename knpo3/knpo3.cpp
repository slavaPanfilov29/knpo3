#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
enum Direction
{
	RIGHT = 1,
	LEFT = 2
};



struct Word
{
	string symbol;
	Word* R;
	Word* L;

};

string trunSymbol(string symbol)
{	map <string, string> alphabet;
	alphabet = { {"A","А"}, {"R", "Р"},{"B", "Б"},{"S", "С"},{"V", "В"},{"T", "Т"},{"G", "Г"},{"U", "У"},{"D", "Д"},{"F", "Ф"},{"E", "Е"},{"H", "Х"},{"E", "Ё"},{"C", "Ц"},{"ZH", "Ж"},{"CH", "Ч"},{"Z", "З"},{"SH", "Ш"},{"I", "И"},{"W", "Щ"},{"I", "Й"},{"Y", "Ы"},{"K", "К"},{"‘", "Ь"},{"L", "Л"}, {"‘’", "Ъ"},{"M", "М"},{"IE", "Э"},{"N", "Н"}, {"IU", "Ю"},{"O", "О"}, {"IA", "Я"},{"P", "П"}};
	return alphabet[symbol];
	
}

void addWord(string symbol, Word*& parent)
{
	if (!parent)
	{
		parent = new Word;
		parent->symbol = symbol;
		parent->R = 0;
		parent->L = 0;
	}
	else
	{
		if ((!parent->R) && (!parent->L))
		{
			addWord(trunSymbol(symbol), parent->R);
			if (symbol.length() == 2)
			{
				string sumSymbol = symbol.substr(0, 1) + symbol.substr(1, 1);
				addWord(trunSymbol(symbol.substr(0, 1))+trunSymbol(symbol.substr(1, 1)), parent->L);
			}
			
		}
		else
		{
			addWord(symbol, parent->R);
			if (parent->L)
			{
				addWord(symbol, parent->L);
			}
		}
	}
}

void printW(Word* tree)
{
	if (!tree)
	{
		return;
	}
	else
	{
		printW(tree->R);
		printW(tree->L);
		cout << tree->symbol<<endl;
		return;
	}
}

void getWord(vector <string>& words, string word, Word* tree)
{
	word.append(tree->symbol);
	if ((!tree->R) && (!tree->L))
	{
		words.push_back(word);
	}
	else
	{
		getWord(words, word, tree->R);
		if (tree->L != 0)
		{
			getWord(words, word, tree->L);
		}
	}
}




int main()
{
	setlocale(LC_ALL, "Russian");
	string h = "ACHACHA";
	Word* root = NULL;
	addWord(h.substr(0, 1), root);
	addWord(h.substr(1, 2), root);
	addWord(h.substr(3, 1), root);
	addWord(h.substr(4, 2), root);
	addWord(h.substr(6, 1), root);
	vector <string >word;
	string wor;
	getWord(word, wor, root);
	
	for (int i = 0; i<word.size();i++)
		cout << word.at(i)<<endl;
	string sum = word.at(0) + word.at(1);
	cout << sum<<endl;

}


