#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

void Intro();
void Setup();
void randomWord();
void DrawLayout();
void input();
void drawHangMan();


//Variables
string ChosenWord; // Word chosen by computer for player to guess
string GuessingWord; // Word that the player inputs letters in to guess
vector <string> wordsList;
string usedLetters;
bool WonGame = false;
int Chances = 8;

//Strings for the drawing
string line1;
string line2;
string line3;
string line4;
string line5;
string line6;
string line7;
string line8;
string line9;

//Strings for winning text and losing text (depends)

string you_win1;
string you_win2;
string you_win3;
string you_win4;
string you_win5;
string you_win6;

//String for stating the correct word if you lose
string correct_word_Lose;


int main()
{
    Intro();
    Setup();
    randomWord();
    DrawLayout();

    while(Chances > 0 && WonGame == false)
    {

        input();

    }

}

void Intro()
{
    char input;
    cout << "===================================================================================" << endl;
    cout << "[]    []       []     [][]    []     [][][]      []    []         []     [][]    []" << endl;
    cout << "[]    []      [][]    [] []   []   []           [][]  [][]       [][]    [] []   []" << endl;
    cout << "[][][][]     []  []   []  []  []  []    [][]   []  [][]  []     []  []   []  []  []" << endl;
    cout << "[]    []    [][][][]  []   [] []   []     []  []    []    []   [][][][]  []   [] []" << endl;
    cout << "[]    []   []      [] []    [][]     [][]][] []            [] []      [] []    [][]" << endl;
    cout << "===================================================================================" << endl << endl << endl;
    cout << "******RULES******:" << endl <<endl<<endl;
    cout << "You have 8 chances" << endl << endl;
    cout << "Use each letter only once - You have a tracker on the right to tell you which letters you have used already!" << endl << endl;
    cout << "ENTER ONLY LOWERCASE LETTERS WHILE GUESSING THE WORDS!!!!!" << endl << endl;
    cout << "Press S to start!" << endl;

    cin >> input;

}


void Setup()
{
    ifstream fin;
    fin.open("Words.txt");

    while(getline(fin, ChosenWord)) //Reads file and acts as a condition true or false if there is something to read in file.
    {
        wordsList.push_back(ChosenWord);
    }

}
void randomWord()
{
    //Random number for choosing random string
    int randNum;
    srand(time(0));
    randNum = (rand () % wordsList.size());
    ChosenWord = wordsList.at(randNum);

    //Setting up blank word
    for (int i = 0; i < ChosenWord.size(); i++) // Making blank spaces in the guessing word string depending on chosen word length
    {
        GuessingWord.push_back(i);
        GuessingWord.at(i) = '-';
    }

}
void DrawLayout()
{

    /*line1 = "    __________    ";
    line2 = "    |        |    ";
    line3 = "    |        |    ";
    line4 = "    |       _O_   ";
    line5 = "    |        |    ";
    line6 = "  __|____   / \\  ";
    line7 = " /  |   /|        ";
    line8 = "/______/ /        ";
    line9 = "|______|/         ";*/


    cout <<"===============================================" << endl;
    cout <<"|                Guess the Word!              |   CHANCES: " << Chances << endl;
    cout <<"===============================================" << endl;
    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;
    cout << line4 << endl;
    cout << line5 << endl;
    cout << line6 << endl; // 26 lines in total for drawing
    cout << line7 << endl;
    cout << line8 << endl;
    cout << line9 << endl;
    cout << endl<<endl<<endl << endl << "                  " << GuessingWord << "      " << correct_word_Lose <<endl<< endl <<you_win1 << "\n"<<you_win2<< "\n"<<you_win3<< "\n"<<you_win4<< "\n"<<you_win5<< "\n"<<you_win6<< "\n"<<" ";
    cout <<"=================================================================" << " USED LETTERS: " <<usedLetters <<endl;
}
void input()
{
    char letter;
    cin >> letter;
    int count = 0;
    for (int i = 0; i < ChosenWord.size(); i++)
    {
        if (letter == ChosenWord.at(i)) //If it is equal to the chosen word letters
        {
            GuessingWord.at(i) = letter;
        }
        else
        {
            count++;
        }
    }

    usedLetters.push_back(letter);

    if (count == ChosenWord.size()) //If no letter is matched, count should be the length of the word, and if so, try again.
    {
        Chances--;
        drawHangMan();
    }

    DrawLayout();
    if (count == ChosenWord.size()) //If no letter is matched, count should be the length of the word, and if so, try again.
    {
        cout << "try again" << endl;
    }

    int word_letter_count = 0;
    for (int i = 0; i < ChosenWord.size(); i++)
    {
        if (GuessingWord.at(i) == ChosenWord.at(i))
        {
            word_letter_count++;
        }
    }
    if (word_letter_count == ChosenWord.size())
    {
        WonGame = true;
    }
    if (WonGame)  // Prints You Won! in big letters made up of slashes, line, underscore, and parenthesis characters
    {
        you_win1 = " _     _                   _            _                    _ ";
        you_win2 = "| |   | |                 | |          | |                  | |";
        you_win3 =" \\\\\_/ / ____    _    _   | |    __    | |  ____   |--___   | |";
        you_win4 = "   | |  / __ \\  | |  | |  | |   /  \\   | | / __ \\  |  __ \\  |_|";
        you_win5 = "   | | | (__) | | |__| |   \\ \\\_/ /\\ \\\_/ / | (__) | | |  | |  _ ";
        you_win6 = "   |_|  \\____/   \\____/     \\___/  \\___/   \\____/  |_|  | | |_|";
        DrawLayout();
    }
    if (Chances < 1)
    {
        //Just using the strings to print winning game message and modifying them to make a You Lose Message.
        you_win1 = "O    O                           O                         O O O O   OO   ";
        you_win2 = "O    O                           O                  O O O  O         OO   ";
        you_win3 = " O  O      OOO     O     O       O          OOO     O      O         OO   ";
        you_win4 = "  O      O     O   O     O       O        O     O   O O O  O O O     OO   ";
        you_win5 = "  O      O     O   O     O       O        O     O       O  O             ";
        you_win6 = "  O        OOO       O O         O O O O    OOO     O O O  O O O O   OO   ";
    }
    DrawLayout();


}
void drawHangMan()
{
    if (Chances == 7)
    {
        line6 = "  _______         ";
        line7 = " /      /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if(Chances == 6)
    {
        line2 = "    |             ";
        line3 = "    |             ";
        line4 = "    |             ";
        line5 = "    |             ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if(Chances == 5)
    {
        line1 = "    __________    ";
        line2 = "    |             ";
        line3 = "    |             ";
        line4 = "    |             ";
        line5 = "    |             ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if(Chances == 4)
    {
        line1 = "    __________    ";
        line2 = "    |        |    ";
        line3 = "    |        |    ";
        line4 = "    |             ";
        line5 = "    |             ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if(Chances == 3)
    {
        line1 = "    __________    ";
        line2 = "    |        |    ";
        line3 = "    |        |    ";
        line4 = "    |        O    ";
        line5 = "    |             ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if (Chances == 2)
    {
        line1 = "    __________    ";
        line2 = "    |        |    ";
        line3 = "    |        |    ";
        line4 = "    |        O    ";
        line5 = "    |        |    ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if (Chances == 1)
    {
        line1 = "    __________    ";
        line2 = "    |        |    ";
        line3 = "    |        |    ";
        line4 = "    |       _O_   ";
        line5 = "    |        |    ";
        line6 = "  __|____         ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
    }
    else if(Chances == 0)
    {
        line1 = "    __________    ";
        line2 = "    |        |    ";
        line3 = "    |        |    ";
        line4 = "    |       _O_   ";
        line5 = "    |        |    ";
        line6 = "  __|____   / \\  ";
        line7 = " /  |   /|        ";
        line8 = "/______/ /        ";
        line9 = "|______|/         ";
        correct_word_Lose = "The correct word was: " + ChosenWord;


    }

}




// If i used a wrong letter again, improve the program so it does not take out chances for entering a wrong letter after it has already been used.
