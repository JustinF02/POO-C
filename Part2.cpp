#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

#pragma region Classe_Chaine
class Chaine {
private:

    int n;
    char* tab;
    char* tab_copier;
public:
    Chaine();
    Chaine(int);
    Chaine(int, char*);
    Chaine(const Chaine&);
    Chaine(const char*);
    Chaine& operator=(const Chaine&);
    ~Chaine();

    //Déclaration des attributs des méthodes
    void init();
    void affiche();
    void min();
    void maj();
    Chaine concat(const Chaine&);
};

#pragma region Constructeurs et destructeur
Chaine::Chaine() {
    cout << "\nConstructeur Initial Nul" << endl;
    tab = NULL; n = 0;
}
Chaine::Chaine(int pn) {
    cout << "\nConstructeur Vecteur avec la classe Chaine" << endl;
    n = pn;
    tab = new char[n];
    for (int i = 0; i < (int)n; i++) {
        tab[i] = '0';
    }
}
Chaine::Chaine(int pn, char* ptab) {

    cout << "\nConstructeur Vecteur (int, char*)";
    n = pn;
    tab = new char[n];
    for (int i = 0; i < n; i++) {
        tab[i] = ptab[i];
    }
    cout << endl;
}

Chaine::Chaine(const Chaine& vecteur) {
    n = vecteur.n;
    tab = new char[n];
    cout << "\nconstructeur recopie"<<"\n";
    for (int i = 0; i < n; i++) {
        tab[i] = vecteur.tab[i];
    }
}
Chaine& Chaine::operator=(const Chaine& vecteur) {
    if (this != &vecteur) {
        delete tab;
        tab = new char[n = vecteur.n];
        for (int i = 0; i < n; i++) {
            tab[i] = vecteur.tab[i];
        }
    }
    return *this;
}
Chaine::Chaine(const char* ptab) {
    cout << "Constructeur Chaine (const char*)" << endl;
    n = strlen(ptab);
    tab = new char[n];
    for (int i = 0; i < n; i++) {
        tab[i] = ptab[i];
    }
}
Chaine::~Chaine() {
    cout << "Destructeur de Vecteur" << endl;
    delete(tab);    //OU free(tab);
}
#pragma endregion

#pragma region TD2 Méthodes
void Chaine::maj() {
    cout << "Chaine en caractere majuscule : "<<endl;
    for (int i = 0; i < n; i++) {
        tab[i] = toupper(tab[i]);
        cout << tab[i] << " ";
    }
    cout << endl;
}
void Chaine::min() {
    cout << "Chaine en caractere minuscule : "<<endl;
    for (int i = 0; i < n; i++) {
        tab[i] = tolower(tab[i]);
        cout << tab[i] << " ";
    }
    cout << endl;
}

Chaine Chaine::concat(const Chaine& vecteur) {
    char* tab2 = new char[n + vecteur.n];
    for (int i = 0; i < n; i++) {
        tab2[i] = tab[i];
    }
    for (int i = 0; i < vecteur.n; i++) {
        tab2[n + i] = vecteur.tab[i];
    }
    tab2[n + vecteur.n] = '\0';
    cout << "tab2 = " << tab2 << endl;
    Chaine res(tab2);
    res.affiche();
    return res;
}
void Chaine::init() {
    cout << "Saisissez les caracteres : \n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Entrer le caractere : \n" << i + 1; cin >> tab[i];
    }
}
void Chaine::affiche() {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << "\t";
    }
    cout << endl;
}
#pragma endregion

int main()
{
    char string1[] = { 'i', 'u', 't' };
    char string2[] = "info";

    cout << "\n---------------------------Vecteur 1---------------------------\n";
    cout << "\nVecteur nul\n";
    Chaine v1;              //null  //affiche inutile

    cout << "\n---------------------------Vecteur 2---------------------------\n";
    cout << "\nConstructeur Chaine(int)\n";
    Chaine v2(5);           // 5 * 0
    v2.affiche();

    cout << "\n---------------------------Vecteur 3---------------------------\n";
    cout << "\nConstructeur Chaine (int, char*)--- Premiere fois\n";
    Chaine v3(3, string1);  //string 1 iut
    v3.affiche();

    cout << "\n---------------------------Vecteur 4---------------------------\n";
    cout << "\nConstructeur Chaine (int, char*) --- Deuxieme fois\n";
    Chaine v4(4, string2);  //string 2 info
    v4.affiche();

    cout << "\n---------------------------Vecteur 5---------------------------\n";
    cout << "\nMethode init\n";
    Chaine v5(3);           //initialisation
    v5.init();
    v5.affiche();

    cout << "\n---------------------------Vecteur 6---------------------------\n";
    cout << "\nConstructeur de recopie\n";
    Chaine v6(v5);          //recopie
    v6.affiche();

    cout << "\n---------------------------Vecteur 7---------------------------\n";
    cout << "\nConstructeur de surcharge\n";
    Chaine v7(0);           //surcharge
    v7 = v6;
    v7.affiche();

    cout << "\n-----------------------Vecteur maj et min----------------------\n";
    cout << "\nMethode maj et min \n";
    v4.maj();               //maj
    v7.min();               //min

    cout << "\n---------------------------Vecteur 8---------------------------\n";
    cout << "\nMethode de concatenation : \n";
    Chaine v8(0);           //concat
    v8 = v4.concat(v7);
    cout << "\n--------------------------Destructeurs-------------------------\n";
}