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
    void VerificareVecini();
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
void Minesweeper::VerificareVecini()
{
    int numarBombeVecine;
    for (int a=0;a<lungime;a++)
    {
        for (int b=0;b<inaltime;b++)
        {
            if(matriceaSursa[a][b]!='*')
            {
                int numarBombeVecine=0;
                if (a==0 && b==0)
                {
                    if (matriceaSursa[a+1][b]=='*')
                        numarBombeVecine++;
                    if (matriceaSursa[a+1][b+1]=='*')
                        numarBombeVecine++;
                    if (matriceaSursa[a][b+1]=='*')
                        numarBombeVecine++;
                }
                else
                    if (a==0 && b==9)
                    {

                        if (matriceaSursa[a][b-1]=='*')
                            numarBombeVecine++;
                        if (matriceaSursa[a+1][b-1]=='*')
                            numarBombeVecine++;
                        if (matriceaSursa[a+1][b]=='*')
                            numarBombeVecine++;
                    }
                    else
                        if (a==9 && b==9)
                        {
                            if (matriceaSursa[a-1][b]=='*')
                                numarBombeVecine++;
                            if (matriceaSursa[a-1][b-1]=='*')
                                numarBombeVecine++;
                            if (matriceaSursa[a][b-1]=='*')
                                numarBombeVecine++;
                        }
                        else
                            if (a==9 && b==0)
                            {
                                if (matriceaSursa[a-1][b]=='*')
                                    numarBombeVecine++;
                                if (matriceaSursa[a-1][b+1]=='*')
                                    numarBombeVecine++;
                                if (matriceaSursa[a][b+1]=='*')
                                    numarBombeVecine++;
                            }
                            else
                                if(a==0)
                                {
                                    if (matriceaSursa[a][b-1]=='*')
                                        numarBombeVecine++;
                                    if (matriceaSursa[a][b+1]=='*')
                                        numarBombeVecine++;
                                    if (matriceaSursa[a+1][b-1]=='*')
                                        numarBombeVecine++;
                                    if (matriceaSursa[a+1][b+1]=='*')
                                        numarBombeVecine++;
                                    if (matriceaSursa[a+1][b]=='*')
                                        numarBombeVecine++;
                                }
                                else
                                    if(a==9)
                                    {
                                        if (matriceaSursa[a][b-1]=='*')
                                            numarBombeVecine++;
                                        if (matriceaSursa[a][b+1]=='*')
                                            numarBombeVecine++;
                                        if (matriceaSursa[a-1][b-1]=='*')
                                            numarBombeVecine++;
                                        if (matriceaSursa[a-1][b+1]=='*')
                                            numarBombeVecine++;
                                        if (matriceaSursa[a-1][b]=='*')
                                            numarBombeVecine++;
                                    }
                                    else
                                        if(b==0)
                                        {
                                            if (matriceaSursa[a-1][b]=='*')
                                                numarBombeVecine++;
                                            if (matriceaSursa[a+1][b]=='*')
                                                numarBombeVecine++;
                                            if (matriceaSursa[a-1][b+1]=='*')
                                                numarBombeVecine++;
                                            if (matriceaSursa[a+1][b+1]=='*')
                                                numarBombeVecine++;
                                            if (matriceaSursa[a][b+1]=='*')
                                                numarBombeVecine++;
                                        }
                                        else
                                            if(b==9)
                                            {
                                                if (matriceaSursa[a-1][b]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a+1][b]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a-1][b-1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a+1][b-1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a][b-1]=='*')
                                                    numarBombeVecine++;
                                            }
                                            else
                                            {
                                                if (matriceaSursa[a-1][b]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a][b-1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a-1][b-1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a+1][b+1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a-1][b+1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a+1][b-1]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a+1][b]=='*')
                                                    numarBombeVecine++;
                                                if (matriceaSursa[a][b+1]=='*')
                                                    numarBombeVecine++;
                                            }
                    numarBombeVecine=numarBombeVecine+48;
                    matriceaSursa[a][b]=numarBombeVecine;
            }
        }
    }
}
void Minesweeper::Afiseaza_Matrice_Afisata()
{
    int a ,b;
    cout<<"  ";
    for(a=0;a<lungime;a++)
        cout<<"  "<<char(a+65)<<" ";
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
    thisgame.VerificareVecini();
    thisgame.Mesaj_de_Incheiere();
    return 0;
}
