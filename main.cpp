#include <iostream>
#include <ctime>

using namespace std;


void visualizzaStato(int capacitaMax, int contPersone, float livelloPuliziaPerc) {
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "Capacità della palestra: " << capacitaMax << " persone" << endl;
    cout << "Numero di persone in palestra: " << contPersone << endl;
    cout << "Livello di pulizia della palestra: " << livelloPuliziaPerc  <<"%"<< endl;
    cout << "Posti liberi: " << capacitaMax - contPersone << " persone" << endl;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference,
// modificando direttamente le variabili passata dal main
//Qui modificherò  direttamente le variabili livelloPuliziaPerc e capacitaMax del main
// perchè per questi due parametri ho usato il passaggio per reference (il simbolo &)
void resetPalestra(int & capacitaMax, int valoreCapacitaMax, float & livelloPuliziaPerc, float valorelivelloPuliziaPerc ) {
    // Controllo l'input e sistemo i valori
    capacitaMax = valoreCapacitaMax;
    if (capacitaMax > 80) {
        capacitaMax = 80;
        cout << "Valore troppo grande per capacita massima. Impostato a " << capacitaMax << endl;
    } else {
        if (capacitaMax < 10) {
            capacitaMax = 10;
            cout << "Valore troppo piccolo per capacita massima. Impostato a " << capacitaMax << endl;
        }
    }

    // Controllo l'input e sistemo i valori
    livelloPuliziaPerc = valorelivelloPuliziaPerc;
    if (livelloPuliziaPerc > 100) {
        livelloPuliziaPerc = 100;
        cout << "Valore Livello di pulizia troppo grande. Limitato a " << livelloPuliziaPerc << endl;
    } else {
        if (livelloPuliziaPerc < 0) {
            livelloPuliziaPerc = 0;
            cout << "Livello di pulizia negativa. Impostata a " << livelloPuliziaPerc << endl;
        }
    }

}


string leggiComando() {
    string c;
    
    do {
        cout << "[R] Reset palestra | [E]ntra persone | [A]ttrezzi | [U] Esci persone  | [P]ulisci | [X] esci" << endl;
        cin >> c;
    } while (c != "R" && c != "E" && c != "A" && c != "U" && c != "P" && c != "X");
    
    return c;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente le variabili passata dal main
void pulisciPalestra(float & livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc + 10;
    if (livelloPuliziaPerc > 100) {
        livelloPuliziaPerc = 100;
    }
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente le variabili passata dal main
void usaAttrezzi(float & livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc - (rand() % 50 + 1);
    if (livelloPuliziaPerc < 0) {
        livelloPuliziaPerc = 0;
    }
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference,
// modificando direttamente la variabile contPersone passata dal main (simbolo &)
void entraPersone(int numPersone, int capacitaMax, int & contPersone) {
    int entrate;
    int postiLiberi;
    
    postiLiberi = capacitaMax - contPersone;
    if (postiLiberi >= numPersone) {
        entrate = numPersone;
    } else {
        entrate = postiLiberi;
        cout << "Non c'è spazio per tutte le persone che hai richiesto. Ne sono entrate  " << entrate << endl;
    }
    contPersone = contPersone + entrate;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente la variabile contPersone passata dal main
void esciPersone(int numPersone, int & contPersone) {
    int uscite;
    
    if (contPersone >= numPersone) {
        uscite = numPersone;
    } else {
        uscite = contPersone;
        cout << "In palestra ci sono meno persone di quelle che vorresti far uscire. Ne sono uscite " << uscite << endl;
    }
    contPersone = contPersone - uscite;
}




int main() {
    
    srand(time(0)); //Inizializzazione funzione random...
    
    string c;
    int capacitaMax, contPersone, numPersone;
    float livelloPuliziaPerc;
    
    contPersone = 0;

    resetPalestra(capacitaMax, 50, livelloPuliziaPerc, (rand() % 101) );
    do {
        //Visualizza lo stato corrente
        visualizzaStato(capacitaMax, contPersone, livelloPuliziaPerc);

        //Legge il comando
        c = leggiComando();
        if (c == "R") {
            int valCapacitaMax;
            cout << "Inserisci la capacità massima: ";
            cin >> valCapacitaMax;
            livelloPuliziaPerc = rand() % 101;

            resetPalestra(capacitaMax, valCapacitaMax, livelloPuliziaPerc, (rand() % 101) );
            contPersone = 0;
        } else if (c == "P") {
            pulisciPalestra(livelloPuliziaPerc);
        
        } else if (c == "A") {
            usaAttrezzi(livelloPuliziaPerc);

        } else if (c == "E") {
            cout << "Quante persone entrano in palestra?" << endl;
            cin >> numPersone;
            entraPersone(numPersone, capacitaMax, contPersone);

        } else if (c == "U") {
            cout << "Quante persone da escono dalla palestra?" << endl;
            cin >> numPersone;
            esciPersone(numPersone, contPersone);
        }
    } while (c != "X");
    cout << "Torna presto!" << endl;
    return 0;
}
