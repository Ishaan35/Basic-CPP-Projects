#include <iostream>
#include <vector>
#include <ctime>
#include "stdlib.h"
#include <string>
using namespace std;


//Function Prototypes
void Sort_Selection(int size, vector <int> &num_list, vector <string> &sort_visual);
void draw(vector <string> &sort_visual);
void Randomize_Setup(vector <int> &num_list, vector <string> &sort_visual, int size);
void bubble_sort(vector <string> &sort_visual);

int main()
{
    vector <string> sort_visual;
    vector <int> num_list;
    srand(time(NULL));

    //instructions
    cout << "USE FULLSCREEN FOR BEST VIEW" << endl;
    cout << "Enter the amount of numbers to sort (max 40 for best visibility): " << endl;
    int size;
    cin >> size;

    //sort selection
    Sort_Selection(size, num_list, sort_visual);

}






//FUNCTIONS*****************************************************************************


void Sort_Selection(int size, vector <int> &num_list, vector <string> &sort_visual)
{
    int sort_selection;
    //User Sort Selection
    while(sort_selection != 1)
    {
        //User Input and Options
        cout << "What type of sort would you like to use? Enter number" << endl;
        cout << "1. Bubble" << endl;
        cin>>sort_selection;

        //If statements of what to do
        if(sort_selection == 1)
        {
            Randomize_Setup(num_list, sort_visual, size);
            draw(sort_visual);

            //Ready to start
            char letter;
            cout << "Enter any letter to start sorting" << endl;
            cin >> letter;

            bubble_sort(sort_visual);
            break;
        }

    }
}

void Randomize_Setup(vector <int> &num_list, vector <string> &sort_visual, int size)
{
    //fill the number list with random numbers
    for (int i = 0; i < size; i++)
    {
        num_list.push_back(rand() % size);
    }

    //Fill the visualizer strings which will be bars with #'s
    for (int i = 0; i < num_list.size(); i++)
    {
        sort_visual.push_back("");
        string temp;
        for (int j = 0; j < num_list.at(i); j++)
        {

            temp.push_back('#');
        }
        sort_visual.at(i) = temp;
    }
}


void draw(vector <string> &sort_visual)
{
    for (int i = 0; i < sort_visual.size(); i++)
    {
        cout << sort_visual.at(i) << endl;
    }
}



void bubble_sort(vector <string> &sort_visual)
{
    //bubble sort
    for (int j = 0; j < sort_visual.size(); j++)
    {
        for (int i = 0; i < sort_visual.size()-1; i++)
        {
            if (sort_visual.at(i).length() > sort_visual.at(i+1).length())
            {
                string temp = sort_visual.at(i);
                sort_visual.at(i) = sort_visual.at(i+1);
                sort_visual.at(i+1) = temp;
                system("CLS");
                draw(sort_visual);
            }
        }
    }
}

