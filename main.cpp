#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int selezione();
void inizio_gioco(int gioco);
void giocaLivello1();
void giocaLivello2();
void giocaLivello3();
void svuotaTabella();
void stampaTabella();
void sceltaCPU(char segno);
void sceltaClient(char segno);
bool controlloVittoria();

int punteggioX = 0;
int punteggioY = 0;

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
        giocaLivello2();
        break;

    case 3:
        int round;
        do
        {
            cout << "Quanti round vuoi fare? ";
            cin >> round;
        }while(round < 1);
        for(int i=0; i<round; i++)
        {
            giocaLivello3();
        }
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

void sceltaClient(char segno)
{
    bool libera = false;
    int scelta;

    do
    {
        do
        {
            cout << "Inserisci la casella in cui vuoi inserire il tuo segno [1-9]: ";
            cin >> scelta;
        }while(scelta < 1 && scelta > 9);
        if(scelta == 1)
        {
            if(tabella[0][0] == ' ')
            {
                libera = true;
                tabella[0][0] = segno;
            }
        }
        else if(scelta == 2)
        {
            if(tabella[0][1] == ' ')
            {
                libera = true;
                tabella[0][1] = segno;
            }
        }
        else if(scelta == 3)
        {
            if(tabella[0][2] == ' ')
            {
                libera = true;
                tabella[0][2] = segno;
            }
        }
        else if(scelta == 4)
        {
            if(tabella[1][0] == ' ')
            {
                libera = true;
                tabella[1][0] = segno;
            }
        }
        else if(scelta == 5)
        {
            if(tabella[1][1] == ' ')
            {
                libera = true;
                tabella[1][1] = segno;
            }
        }
        else if(scelta == 6)
        {
            if(tabella[1][2] == ' ')
            {
                libera = true;
                tabella[1][2] = segno;
            }
        }
        else if(scelta == 7)
        {
            if(tabella[2][0] == ' ')
            {
                libera = true;
                tabella[2][0] = segno;
            }
        }
        else if(scelta == 8)
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
    cout <<"Scelta per giocatore " << segno <<": " << scelta << "\n";
    stampaTabella();
}

bool controlloVittoria()
{
    char segno;
    //! RIGA 1
    if((tabella[0][0] == 'x' && tabella[0][1] == 'x' && tabella[0][2] == 'x') || (tabella[0][0] == 'o' && tabella[0][1] == 'o' && tabella[0][2] == 'o')){
        segno = tabella[0][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[0][0] = segno;
        tabella[0][1] = segno;
        tabella[0][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;

    }
    //! RIGA 2
    else if((tabella[1][0] == 'x' && tabella[1][1] == 'x' && tabella[1][2] == 'x') || (tabella[1][0] == 'o' && tabella[1][1] == 'o' && tabella[1][2] == 'o')){
        segno = tabella[1][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[1][0] = segno;
        tabella[1][1] = segno;
        tabella[1][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }
    //! RIGA 3
    else if((tabella[2][0] == 'x' && tabella[2][1] == 'x' && tabella[2][2] == 'x') || (tabella[2][0] == 'o' && tabella[2][1] == 'o' && tabella[2][2] == 'o')){
        segno = tabella[2][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[2][0] = segno;
        tabella[2][1] = segno;
        tabella[2][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }

    //! COLONNA 1
    else if((tabella[0][0] == 'x' && tabella[1][0] == 'x' && tabella[2][0] == 'x') || (tabella[0][0] == 'o' && tabella[1][0] == 'o' && tabella[2][0] == 'o')){
        segno = tabella[0][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[0][0] = segno;
        tabella[1][0] = segno;
        tabella[2][0] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }
    //! COLONNA 2
    else if((tabella[0][1] == 'x' && tabella[1][1] == 'x' && tabella[2][1] == 'x') || (tabella[0][1] == 'o' && tabella[1][1] == 'o' && tabella[2][1] == 'o')){
        segno = tabella[0][1];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[0][1] = segno;
        tabella[1][1] = segno;
        tabella[2][1] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }
    //! COLONNA 3
    else if((tabella[0][2] == 'x' && tabella[1][2] == 'x' && tabella[2][2] == 'x') || (tabella[0][2] == 'o' && tabella[1][2] == 'o' && tabella[2][2] == 'o')){
        segno = tabella[0][2];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[0][2] = segno;
        tabella[1][2] = segno;
        tabella[2][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }

    //! DIAGONALE CRESCENTE
    else if((tabella[2][0] == 'x' && tabella[1][1] == 'x' && tabella[0][2] == 'x') || (tabella[2][0] == 'o' && tabella[1][1] == 'o' && tabella[0][2] == 'o')){
        segno = tabella[2][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[2][0] = segno;
        tabella[1][1] = segno;
        tabella[0][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }
    //!DIAGONALE DESCRESCENTE
    else if((tabella[0][0] == 'x' && tabella[1][1] == 'x' && tabella[2][2] == 'x') || (tabella[0][0] == 'o' && tabella[1][1] == 'o' && tabella[2][2] == 'o')){
        segno = tabella[0][0];
        Sleep(2000);
        system("cls");
        svuotaTabella();
        tabella[0][0] = segno;
        tabella[1][1] = segno;
        tabella[2][2] = segno;
        if(segno == 'x') punteggioX++;
        else punteggioY++;
        cout << "Vittoria per " << segno << endl;
        stampaTabella();
        return true;
    }

    else{return false;}

}


void giocaLivello1()
{
    system("cls");
    svuotaTabella();
    stampaTabella();
    int cicli=0;
    while(controlloVittoria()==false){
        Sleep(1500);
        cicli++;
        if(cicli%2==0)
        {
            sceltaCPU('x');
        }else{
            sceltaCPU('o');
        }
    }

}

void giocaLivello2()
{
    char segnoClient;
    char segnoCpu;
    system("cls");
    svuotaTabella();
    stampaTabella();
    int cicli=0;
    do
    {
        cout << "Inserisci il segno che vuoi usare [x / o]: ";
        cin >> segnoClient;
    }while(segnoClient != 'x' && segnoClient != 'o');

    if(segnoClient == 'x') {segnoCpu='o';}
    else segnoCpu = 'x';

    while(controlloVittoria()==false){
        Sleep(1500);
        cicli++;
        if(cicli%2==0)
        {
            sceltaCPU(segnoCpu);
        }else{
            sceltaClient(segnoClient);
        }
    }
}

void giocaLivello3()
{
    char segnoClient1;
    char segnoClient2;
    system("cls");
    cout << "\n\nPunteggio X = " << punteggioX;
    cout << "\nPunteggio Y = " << punteggioY << "\n\n";
    svuotaTabella();
    stampaTabella();
    int cicli=0;
    do
    {
        cout << "Inserisci il segno che vuoi usare [x / o]: ";
        cin >> segnoClient1;
    }while(segnoClient1 != 'x' && segnoClient1 != 'o');

    if(segnoClient1 == 'x') {segnoClient2='o';}
    else segnoClient2 = 'x';

    while(controlloVittoria()==false){
        Sleep(1500);
        cicli++;
        if(cicli%2==0)
        {
            cout << "-- GIOCATORE 1 --" << endl;
            sceltaClient(segnoClient1);
        }else{
            cout << "-- GIOCATORE 2 --" << endl;
            sceltaClient(segnoClient2);
        }
    }
}
