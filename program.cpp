#include <iostream>
#include <cstdlib>
#include "class.h"

using namespace std;

void Program::main_menu()
{
    for(;;)
    {
        cout << "          MAIN MENU" << endl;
        cout << "1. Table" << endl;
        cout << "2. Matches" << endl;
        cout << "3. Edit Score" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Choice: ";

        if(!(cin>>choice))
        {
            cerr << "Error";            // W starym odcinku sprawdziæ co dokladnie to robi
            exit(0);
        }

        system("cls");

        switch(choice)
        {
        case 1:
                table();
            break;
        case 2:
                matches();
            break;
        case 3:
                edit_score();
             //  count_points();
            break;
        case 4:
            cout << "Finish";
            exit(0);
            break;
        }
    }
}
