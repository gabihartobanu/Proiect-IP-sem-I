#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
char matriceaSursa[100][100],matriceaAfisata[100][100];
class Minesweeper
{
private:
    int x,y,lungime,inaltime,nrMine;
    int nonmines;
public:
    Minesweeper();
    void Mesaj_Bun_Venit();
    void plasareMine();
    void Countem();
    void Mutare();
    void Afiseaza_Matrice_Afisata();
    void Mesaj_de_Incheiere();
};
Minesweeper::Minesweeper()
{
    nonmines=0;
}
void Minesweeper::Mesaj_Bun_Venit()
{
    cout<<" ________________________________________________________________"<<endl;
    cout<<"| Bun venit in jocul meu de Minesweeper                          |"<<endl;
    cout<<"|----------------------------------------------------------------|"<<endl;
    cout<<"|  * Tastati coordonatele pozitiei pe care o doriti              |"<<endl;
    cout<<"|  * Coordonatele merg de sus in jos si de la stanga la dreapta  |"<<endl;
    cout<<"|  * Daca deschideti o mina pierdeti                             |"<<endl;
    cout<<"|  * Nu deschideti coordonate pe care le considerati mine        |"<<endl;
    cout<<"|                                                                |"<<endl;
    cout<<"|                                                                |"<<endl;
    cout<<"|                                                                |"<<endl;
    cout<<"| Mult succes!!!                                                 |"<<endl;
    cout<<"|________________________________________________________________|"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"Acum dati dimensiunea matricei, de preferabil patratica."<<endl;
    cout<<"Dati lungimea matricei: ";
    cin>>lungime;
    cout<<"Dati inaltimea matricei: ";
    cin>>inaltime;
    system("cls");
}
void Minesweeper::plasareMine()
{
    int i,j;
    if((lungime*inaltime)%10==0)
        nrMine=(lungime*inaltime)/10;
    else nrMine=(lungime*inaltime)/10+1;
    for(int mine=0;mine<nrMine;mine++)
    {
        int x=rand()%lungime;
        int y=rand()%inaltime;

        if (matriceaSursa[x][y]=='*')
            mine--;
        else
            matriceaSursa[x][y]='*';
    }
}
void Minesweeper::Afiseaza_Matrice_Afisata()
{
    int a ,b;
    cout<<"  ";
    for(a=0;a<lungime;a++)
        cout<<"  "<<a<<" ";
    cout<<endl;
    cout<<"  ";
    for(a=0;a<lungime*4;a++)
        cout<<"_";
    cout<<endl;
    for (a=0;a<lungime;a++)
    {
        cout<<a<<" |";
        for (b=0;b<inaltime;b++)
        {
            cout<<" "<<matriceaSursa[a][b]<<" |";
        }
        cout<<endl;
        cout<<"  ";
        for(b=0;b<lungime*4;b++)
            cout<<"_";
        cout<<endl;
    }
}
void Minesweeper::Mesaj_de_Incheiere()
{
    int a ,b;
    for(a=0;a<lungime*4-4;a++)
        cout<<"_";
    cout<<endl;
    for (a=0;a<lungime;a++)
    {
        cout<<"|";
        for (b=0;b<inaltime;b++)
        {
            cout<<matriceaSursa[a][b]<<" |";
        }
        cout<<endl;
        for(b=0;b<lungime*4-4;b++)
            cout<<"_";
        cout<<endl;
    }

    cout<<"Multumesc pentru ca ati jucat acest joc"<<endl;
    if (nonmines==lungime*inaltime-nrMine)
    {
        cout<<"Felicitari, acum dute sa joci un Minesweeper adevarat!"<<endl;
    }
    else
    {
        cout<<"Ai pierdut, mai bine joaca un Minesweeper adevarat!"<<endl;
    }

    cout<<endl<<"Multumesc ca ati trecut pe aici!"<<endl;

}
int main()
{
    int i,j;
    srand(time(0));
    Minesweeper thisgame;
      thisgame.Mesaj_Bun_Venit();
    thisgame.plasareMine();
    //thisgame.Afiseaza_Matrice_Afisata();
    thisgame.Mesaj_de_Incheiere();
    return 0;
}
