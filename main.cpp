#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int selezione();
void inizio_gioco(int gioco);
void giocaLivello1();
void svuotaTabella();
void stampaTabella();
void sceltaCPU(char segno);

char tabella[3][3] =
{
    {'0', '0', '0'},
    {'0', '0', '0'},
    {'0', '0', '0'}
};

int main()
{
    srand(time(NULL));
    int g = selezione();
    inizio_gioco(g);
    return 0;
}


selezione()
{
    int scelta;
    cout << "Modalita\' disponibili:\n";
    cout << "1. CPUvsCPU\n";
    cout << "2. CPUvsCLIENT\n";
    cout << "3. CLIENTvsCLIENT\n\n";
    do{
        cout << "Scelta modalita\': ";
        cin >> scelta;
    }while(scelta!=1 && scelta!=2 && scelta !=3);
    return scelta;
}


void inizio_gioco(int gioco)
{
    switch(gioco)
    {
    case 1:
        giocaLivello1();
        break;

    case 2:
        //giocaLivello2();
        break;

    case 3:
        //giocaLivello3();
        break;
    }
}

void svuotaTabella()
{
    tabella[0][0] = ' ';
    tabella[0][1] = ' ';
    tabella[0][2] = ' ';
    tabella[1][0] = ' ';
    tabella[1][1] = ' ';
    tabella[1][2] = ' ';
    tabella[2][0] = ' ';
    tabella[2][1] = ' ';
    tabella[2][2] = ' ';
}

void stampaTabella()
{
    cout << " " << tabella[0][0] << " | " << tabella[0][1] << " | " << tabella[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << tabella[1][0] << " | " << tabella[1][1] << " | " << tabella[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << tabella[2][0] << " | " << tabella[2][1] << " | " << tabella[2][2] << "\n\n";
}

void sceltaCPU(char segno)
{
    bool libera = false;
    int casuale;

    do
    {
        casuale = 1 + (rand() % 9);
        if(casuale == 1)
        {
            if(tabella[0][0] == ' ')
            {
                libera = true;
                tabella[0][0] = segno;
            }
        }
        else if(casuale == 2)
        {
            if(tabella[0][1] == ' ')
            {
                libera = true;
                tabella[0][1] = segno;
            }
        }
        else if(casuale == 3)
        {
            if(tabella[0][2] == ' ')
            {
                libera = true;
                tabella[0][2] = segno;
            }
        }
        else if(casuale == 4)
        {
            if(tabella[1][0] == ' ')
            {
                libera = true;
                tabella[1][0] = segno;
            }
        }
        else if(casuale == 5)
        {
            if(tabella[1][1] == ' ')
            {
                libera = true;
                tabella[1][1] = segno;
            }
        }
        else if(casuale == 6)
        {
            if(tabella[1][2] == ' ')
            {
                libera = true;
                tabella[1][2] = segno;
            }
        }
        else if(casuale == 7)
        {
            if(tabella[2][0] == ' ')
            {
                libera = true;
                tabella[2][0] = segno;
            }
        }
        else if(casuale == 8)
        {
            if(tabella[2][1] == ' ')
            {
                libera = true;
                tabella[2][1] = segno;
            }
        }
        else
        {
            if(tabella[2][2] == ' ')
            {
                libera = true;
                tabella[2][2] = segno;
            }
        }
    }while(libera == false);
    cout <<"Scelta per giocatore " << segno <<": " << casuale << "\n";
    stampaTabella();
}


void giocaLivello1()
{
    system("cls");
    svuotaTabella();
    stampaTabella();
    for(int i=0;i<9;i++)
    {
        Sleep(1500);
        if(i%2==0)
        {
            sceltaCPU('x');
        }
        else
        {
            sceltaCPU('o');
        }
    }
}

