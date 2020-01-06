#include <iostream>

using namespace std;

class Team
{
public:
    string name;
    string pause;
    int points;
    int goals_scored;
    int goals_lost;

    Team( string="---", string="   ", int=0, int=0, int=0);
    void load();
};


class Program :protected Team
{
    int goals[12];                  // zmienne do edytowania wyniku
    int sum_goals_scored[3];       // zmienne do sumowania goli zdobytych
    int sum_goals_lost[3];        // zmienne do sumowania goli straconych
    int pnt[12];                 // zmienna do liczenia punktow pojedynczych spotkan
    int sum_points[3];          // zmienne do liczenia punktow

public:
    Program();

    void main_menu();
    void table();
    void quick_sort(int *tab, int lewy, int prawy);
    void matches();
    void edit_score();
    void count_points();
    void count_goals();
};

