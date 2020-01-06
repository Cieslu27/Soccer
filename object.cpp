#include <iostream>
#include <cstdlib>
#include "class.h"

using namespace std;

Team::Team(string n, string pa, int p, int gs, int gl)
{
    name=n;
    pause=pa;
    points=p;
    goals_scored=gs;
    goals_lost=gl;
}

Program::Program()
{
    for(int i=0; i<13; i++)
        {
            goals[i]=0;
            pnt[i]=0;
        }
    for(int i=0; i<4; i++)
    {
        sum_goals_scored[i]=0;
        sum_goals_lost[i]=0;
        sum_points[i]=0;
    }
}

void Team::load()
{
    cout << name << pause << "   " << points << "   " << goals_scored << ":" << goals_lost <<endl;
}

void Program::table()
{
    int *tab, n;
    Team A1("Benfica Lisbon","       ");
    Team A2("Olimpique Lyon","       ");
    Team A3("RB Leipzig","           ");
    Team A4("Zenit Sankt Peterburg","");

    count_points();
    count_goals();

    A1.points=sum_points[0]; //przepisujemy policzone punkty do odpowiednich zmiennych obiektow
    A2.points=sum_points[1];
    A3.points=sum_points[2];
    A4.points=sum_points[3];

    A1.goals_scored=sum_goals_scored[0]; //przepisujemy policzone zdobyte bramki do odpowiednich zmiennych obiektow
    A2.goals_scored=sum_goals_scored[1];
    A3.goals_scored=sum_goals_scored[2];
    A4.goals_scored=sum_goals_scored[3];

    A1.goals_lost=sum_goals_lost[0]; //przepisujemy policzone stracone bramki do odpowiednich zmiennych obiektow
    A2.goals_lost=sum_goals_lost[1];
    A3.goals_lost=sum_goals_lost[2];
    A4.goals_lost=sum_goals_lost[3];



    n=4;
    tab = new int [n];
    tab[0]=A1.points;
    tab[1]=A2.points;
    tab[2]=A3.points;
    tab[3]=A4.points;

    Program::quick_sort(tab, 0, n-1);

   for(int i=0; i<n; i++)
    {
   if(A1.points==tab[i])
        {
            A1.load();
            A1.points=-1;   //Zmieniamy liczbę punktów, aby w przypadku takiej samej liczby punktów program nie wyświetlał tylko jednej druzyny
        }
   else if(A2.points==tab[i])
        {   A2.load();
            A2.points=-1;
        }
   else if(A3.points==tab[i])
        {    A3.load();
             A3.points=-1;
        }
   else if(A4.points==tab[i])    A4.load();  //W ostatnim przypadku już nie musimy zmieniać wartości
    }

    cout << endl;

    delete [] tab;
}

void Program::quick_sort(int *tab, int lewy, int prawy)
{
        if(prawy <= lewy)
        return;

    int i = lewy - 1, j = prawy + 1,
        pivot = tab[(lewy+prawy)/2];

    while(1)
    {
        while(pivot<tab[++i]);
        while(pivot>tab[--j]);
        if( i <= j)
            swap(tab[i],tab[j]);
        else
            break;
    }

    if(j > lewy)
        quick_sort(tab, lewy, j);
    if(i < prawy)
        quick_sort(tab, i, prawy);
}

void Program::matches()
{

    Team A1("Benfica Lisbon");
    Team A2("Olimpique Lyon");
    Team A3("RB Leipzig");
    Team A4("Zenit Sankt Peterburg");
    cout << endl <<"Matches: " << endl;
    cout << "1. " << A1.name << " - " << A2.name << "          ";
    if(goals[0]<0 && goals[3]<0) cout << "0:0" << endl;
    else cout << goals[0] << ":" << goals[3] << endl;

    cout << "2. " << A3.name << " - " << A4.name << "       ";
    if(goals[6]<0 && goals[9]<0) cout << "0:0" << endl;
    else cout << goals[6] << ":" << goals[9] << endl;

    cout << "3. " << A1.name << " - " << A3.name << "              ";
    if(goals[1]<0 && goals[7]<0) cout << "0:0" << endl;
    else cout << goals[1] << ":" << goals[7] << endl;

    cout << "4. " << A2.name << " - " << A4.name << "   ";
    if(goals[4]<0 && goals[10]<0) cout << "0:0" << endl;
    else cout << goals[4] << ":" << goals[10] << endl;

    cout << "5. " << A1.name << " - " << A4.name << "   ";
    if(goals[2]<0 && goals[11]<0) cout << "0:0" << endl;
    else cout << goals[2] << ":" << goals[11] << endl;

    cout << "6. " << A2.name << " - " << A3.name << "              ";
    if(goals[5]<0 && goals[8]<0) cout << "0:0" << endl << endl;
    else cout << goals[5] << ":" << goals[8] << endl<< endl;
}

void Program::edit_score()
{
    matches();

    int number;
    cout << "Choice number: ";
    cin >> number;

    switch(number)
    {
    case 1:
        cout << "Hosts goals: ";
        cin >> goals[0];
        cout << "Guests goals: ";
        cin >> goals[3];
        break;

    case 2:
        cout << "Hosts goals: ";
        cin >> goals[6];
        cout << "Guests goals: ";
        cin >> goals[9];
        break;

    case 3:
        cout << "Hosts goals: ";
        cin >> goals[1];
        cout << "Guests goals: ";
        cin >> goals[7];
        break;

    case 4:
        cout << "Hosts goals: ";
        cin >> goals[4];
        cout << "Guests goals: ";
        cin >> goals[10];
        break;

    case 5:
        cout << "Hosts goals: ";
        cin >> goals[2];
        cout << "Guests goals: ";
        cin >> goals[11];
        break;

    case 6:
        cout << "Hosts goals: ";
        cin >> goals[5];
        cout << "Guests goals: ";
        cin >> goals[8];
        break;
    }
    system("cls");
    Program::matches();
}

void Program::count_points()
{

        if      (goals[0] > goals[3])                                { pnt[0]=3; pnt[3]=0; }  // policzone punkty za pierwszy mecz
        else if (goals[0] < goals[3])                                { pnt[0]=0; pnt[3]=3; }
        else if (goals[0] == goals[3] && goals[0]>0 && goals[3]>0)   { pnt[0]=1; pnt[3]=1; }
        else                                                         { pnt[0]=0; pnt[3]=0; }

        if      (goals[6] > goals[9])                                { pnt[6]=3; pnt[9]=0; }  // policzone punkty za drugi mecz
        else if (goals[6] < goals[9])                                { pnt[6]=0; pnt[9]=3; }
        else if (goals[6] == goals[9] && goals[6]>0 && goals[9]>0)   { pnt[6]=1; pnt[9]=1; }
        else                                                         { pnt[6]=0; pnt[9]=0; }

        if      (goals[1] > goals[7])                                { pnt[1]=3; pnt[7]=0; }  // policzone punkty za trzeci mecz
        else if (goals[1] < goals[7])                                { pnt[1]=0; pnt[7]=3; }
        else if (goals[1] == goals[7] && goals[1]>0 && goals[7]>0)   { pnt[1]=1; pnt[7]=1; }
        else                                                         { pnt[1]=0; pnt[7]=0; }

        if      (goals[4] > goals[10])                               { pnt[4]=3; pnt[10]=0; }  // policzone punkty za czwarty mecz
        else if (goals[4] < goals[10])                               { pnt[4]=0; pnt[10]=3; }
        else if (goals[4] == goals[10] && goals[4]>0 && goals[10]>0) { pnt[4]=1; pnt[10]=1; }
        else                                                         { pnt[4]=0; pnt[10]=0; }

        if      (goals[2] > goals[11])                               { pnt[2]=3; pnt[11]=0; }  // policzone punkty za piaty mecz
        else if (goals[2] < goals[11])                               { pnt[2]=0; pnt[11]=3; }
        else if (goals[2] == goals[11] && goals[2]>0 && goals[11]>0) { pnt[2]=1; pnt[11]=1; }
        else                                                         { pnt[2]=0; pnt[11]=0; }

        if      (goals[5] > goals[8])                                { pnt[5]=3; pnt[8]=0; }  // policzone punkty za szosty mecz
        else if (goals[5] < goals[8])                                { pnt[5]=0; pnt[8]=3; }
        else if (goals[5] == goals[8] && goals[5]>0 && goals[8]>0)   { pnt[5]=1; pnt[8]=1; }
        else                                                         { pnt[5]=0; pnt[8]=0; }

        int *p[12];
        for(int i=0; i<12; i++) p[i]=&pnt[i]; //przepisujemy wskazniki do zmiennych, aby sumowac punkty kazdej druzyny

        sum_points[0]=*p[0]+*p[1]+*p[2];             // sumowanie punktow
        sum_points[1]=*p[3]+*p[4]+*p[5];
        sum_points[2]=*p[6]+*p[7]+*p[8];
        sum_points[3]=*p[9]+*p[10]+*p[11];
}

void Program::count_goals()
{


        int *w[12];
        for(int i=0; i<13; i++)
        {
            w[i]=&goals[i];      // przepisujemy wskazniki do zmiennych, ktore licza bramki strzelone w kazdym meczu
        }


        sum_goals_scored[0]=*w[0]+*w[1]+*w[2];       // sumowanie bramek zdobytych
        sum_goals_scored[1]=*w[3]+*w[4]+*w[5];
        sum_goals_scored[2]=*w[6]+*w[7]+*w[8];
        sum_goals_scored[3]=*w[9]+*w[10]+*w[11];

        sum_goals_lost[0]=*w[3]+*w[7]+*w[11];        // sumowanie bramek straconych
        sum_goals_lost[1]=*w[0]+*w[10]+*w[8];
        sum_goals_lost[2]=*w[9]+*w[2]+*w[5];
        sum_goals_lost[3]=*w[6]+*w[4]+*w[2];
}









