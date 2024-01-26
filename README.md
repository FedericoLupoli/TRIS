**TRIS**

Il gioco si svolge in 3 livelli:
-	Livello 1: CPUvsCPU
-	Livello 2: CLIENTvsCPU
-	Livello 3: CLIENTvsCLIENT

Livello 1
Il livello 1 è totalmente casuale, ogni ciclo viene generato un numero casuale da 1 a 9 e dopo aver controllato che sia una casella disponibile gli viene assegnato il carattere del giocatore (CPU) di quel turno.
Ogni round viene controllata se è presente la vittoria per non effettuare più round di quanti dovuti.

Livello 2
Il livello 2 tiene la parte della selezione della CPU ma viene implementata una parte manuale in cui il giocatore CLIENT deve selezionare la casella in cui vuole inserire il suo segno, anche in questo caso viene controllata lo stato (libero/occupato) della casella e viene controllata ogni volta la vittoria.

Livello 3
Il livello 3 si sviluppa in modo differente, prima di cominciare il gioco viene richiesto all’utente di selezionare il numero di round in cui si vuole giocare e viene inserito all’interno del gioco il punteggio (punteggioX e punteggioY). Una volta cominciato il gioco si svolge esattamente come il livello 1 e 2 con l’unica differenza che ogni mossa viene scelta dall’utente.


SPIEGAZIONE TECNICA
La Tabella: Il tabellone di gioco viene ricreato usando una matrice char 3x3

 

LE FUNZIONI
void svuotaTabella(): //funzione usata per resettare la tabella
-	Quando viene richiamata prende in ordine ogni casella della tabella ([0][0], [0][1], [0][2], …) e la assegna al valore ‘ ‘.

void inizio_gioco(int gioco):
-	Dopo una previa selezione tramite un semplice cin “inizio_gioco” controlla la modalità che è stata scelta e richiama la funzione di ogni modalità utilizzando uno Switch
-	Nel caso della modalità 3 prima di richiamare la funzione del livello 3 richiederà l’inserimento dei round, inserendo il livello in un ciclo for.

void giocaLivello1(): //Livello 1 CPUvsCPU
-	Con un ciclo while continua a far giocare ad oltranza i giocatori fino a che non si verifica una vittoria
-	Con la funzione sceltaCPU() manda l’input per le mosse.

void giocaLivello2(): //Livello 1 CLIENTvsCPU
-	Con un ciclo while continua a far giocare ad oltranza i giocatori fino a che non si verifica una vittoria
-	Con la funzione sceltaCPU() manda l’input per le mosse della cpu.
-	Con la funzione sceltaClient() manda l’input per le mosse del client

void giocaLivello3(): //Livello 3 CLIENTvsCLIENT
-	Con un ciclo while continua a far giocare ad oltranza i giocatori fino a che non si verifica una vittoria
-	All’inizio si chiede ai giocatori che simbolo vogliono usare per giocare.
-	Con la funzione sceltaClient() manda l’input per le mosse del client
-	Ogni partita che si effettua è implementato un punteggio per i due giocatori.


void sceltaCPU(char segno): //funzione per la scelta automatica
-	Con una variabile che ogni volta viene assegnata in modo casuale da 1 a 9 viene selezionata la casella
-	Controlla lo stato della casella guardando il valore assegnato all’interno (se è uguale a ‘ ‘).
-	Assegna nella casella selezionata il segno passato come parametro.

void sceltaClient(char segno): //funzione per la scelta automatica
-	Con una variabile che ogni volta viene richiesta all’utente da 1 a 9 viene selezionata la casella
-	Controlla lo stato della casella guardando il valore assegnato all’interno (se è uguale a ‘ ‘).
-	Assegna nella casella selezionata il segno passato come parametro.

bool controlloVittoria(): //funzione usata per ciclare i livelli e controllare la vittoria
-	Controlla tutte le possibilità di tris (Riga 0,1,2;Colonna 0,1,2; Diagonali), se in una possibilità ci sono simboli uguali in tutte e 3 le caselle viene fermato il gioco e stampato a schermo il tris effettuato assegnando la vittoria
