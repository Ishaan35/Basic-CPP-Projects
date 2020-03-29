#include <iostream>
#include <vector>
#include <ctime>
#include "stdlib.h"
#include <string>
#include "windows.h"
using namespace std;


//Function Prototypes
void Sort_Selection(int size, vector <int> &num_list, vector <string> &sort_visual);
void draw(vector <string> &sort_visual);
void Randomize_Setup(vector <int> &num_list, vector <string> &sort_visual, int size);

void bubble_sort(vector <string> &sort_visual);
void Selection_Sort(vector <string> &sort_visual);
void Insertion_Sort(vector <string> &sort_visual);
void Shell_Sort(vector<string> &sort_visual);



int main()
{
    vector <string> sort_visual;
    vector <int> num_list;
    srand(time(NULL));

    //instructions
    cout << "USE FULLSCREEN FOR BEST VIEW" << endl;
    cout << "Enter the amount of numbers to sort (maximum should be amount of lines that can fit on a single screen without scrolling for best visibility): " << endl;
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
        cout << "2. Selection" << endl;
        cout << "3. Insertion" << endl;
        cout << "4. Shell" << endl;
        cin>>sort_selection;

        //If statements of what to do
        if(sort_selection == 1)
        {
            Randomize_Setup(num_list, sort_visual, size);
            draw(sort_visual);

            //Ready to start
            system("pause");

            bubble_sort(sort_visual);
            break;
        }
        else if (sort_selection == 2)
        {
            Randomize_Setup(num_list, sort_visual, size);
            draw(sort_visual);

            //Ready to start
            system("pause");

            Selection_Sort(sort_visual);
            break;
        }
        else if (sort_selection == 3)
        {
            Randomize_Setup(num_list, sort_visual, size);
            draw(sort_visual);

            //Ready to start
            system("pause");

            Insertion_Sort(sort_visual);
            break;
        }
        else if (sort_selection == 4)
        {
            Randomize_Setup(num_list, sort_visual, size);
            draw(sort_visual);

            //Ready to start
            system("pause");

            Shell_Sort(sort_visual);
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

//SORTING ALGORITHMS-----------------------------------------------------------------------------------

void bubble_sort(vector <string> &sort_visual)
{
    //bubble sort
    for (int j = 0; j < sort_visual.size(); j++)
    {
        for (int i = 0; i < sort_visual.size()-1; i++)
        {
            //try to change colour of two strings being compared
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
    system("COLOR A");
}
void Selection_Sort(vector <string> &sort_visual)
{

    for (int i = 0; i < sort_visual.size(); i++)
    {
        //smallest string will initially be set to first string, to start process
        string smallest_string = sort_visual.at(i);
        //since smallest string is first one, also on index i currently, the index of smallest string will also be i
        int smallest_string_index = i;

        //comparing should start from the last sorted string ie, if sortvisual.at(i) is guaranteed smallest, start comparing next round from that index instead of 0
        for (int j = i; j < sort_visual.size(); j++)
        {
            //if smaller string found, set smallest string to that, and change the smallest string index to the index of new smallest string
            if(sort_visual.at(j).length() < smallest_string.length())
            {
                smallest_string = sort_visual.at(j);
                smallest_string_index = j;


            }
        }
        //swap the element at index i with the current smallest number
        string temp = sort_visual.at(i);
        sort_visual.at(i) = sort_visual.at(smallest_string_index);
        sort_visual.at(smallest_string_index) = temp;


        system("CLS");
        draw(sort_visual);


    }
    system("COLOR A");
}
void Insertion_Sort(vector <string> &sort_visual)
{
    //Will hold the value the loop is on
    string value;
    //If loop finds a small string, (value) the index will hold its location in vector. Int i will be for the loop
    int i, index;
    //start at 1 because the first element in vector will initially be 'sorted'
    for (i = 1; i < sort_visual.size(); i++)
    {
        //hold this value
        value = sort_visual.at(i);
        index = i;
        //as long as the loop is not on the first element of the entire vector, and the element before the element held in value has a smaller length, do this loop
        while(index > 0 && sort_visual.at(index-1).length() > value.length())
        {
            //Essentially what we are doing after this line of code is swapping values

            //put the previous element in the portion of the array we are on right now (index)
            sort_visual.at(index) = sort_visual.at(index-1);
            //subtract index value to go back 1 element
            index--;
        }
        //now we put the value variable in the index position we were just on before. What we did was swap the values
        sort_visual.at(index) = value;
        system("CLS");
        draw(sort_visual);

    }
    system("COLOR A");
}

void Shell_Sort(vector <string> &sort_visual)
{
    int i, j, k;
    string temp;

    for(i = sort_visual.size()-2; i>0; i/=2)
    {
        for(j = i; j < sort_visual.size(); j++)
        {
            for(k = j-i; k >=0; k-=i)
            {
                if(sort_visual[k+i].length() >= sort_visual[k].length())
                {
                    break;
                }
                else
                {
                    temp = sort_visual[k];
                    sort_visual[k] = sort_visual[k+i];
                    sort_visual[k+i] = temp;




                }
                system("CLS");
                    draw(sort_visual);
            }

        }

    }
    system("COLOR A");

}

