#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cstring>
#include<windows.h>
using namespace std;
char matriceaSursa[100][100],matriceaAfisata[100][100];
class Minesweeper
{
private:
    int x,y,lungime,inaltime,nrMine=0,nrFlaguri=0;
    int nonmines=0;
public:
    Minesweeper();
    void Mesaj_Bun_Venit();
    void plasareMine();
    void VerificareVecini();
    void Mutare();
    void Afiseaza_Matrice_Afisata();
    void Mesaj_de_Incheiere();
    void umplere(int, int);
};
Minesweeper::Minesweeper()
{
    nonmines=0;
}
void Minesweeper::Mesaj_Bun_Venit()
{
    int optiune;
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
    cout<<"Alegeti una din optiunile de mai jos"<<endl;
    cout<<"1. Easy"<<endl;
    cout<<"2. Normal"<<endl;
    cout<<"3. Hard"<<endl;
    cout<<"4. Personalizat"<<endl;
    cout<<"5. Iesire"<<endl;
    cin>>optiune;
    system("cls");
    if(optiune==5)
        exit(0);
    if(optiune==1)
    {
        inaltime=9;
        lungime=9;
        nrMine=10;
    }
    if(optiune==2)
    {
        inaltime=16;
        lungime=16;
        nrMine=40;
    }
    if(optiune==3)
    {
        inaltime=16;
        lungime=30;
        nrMine=99;
    }
    if(optiune==4)
    {
        cout<<"Acum dati dimensiunea matricei, de preferabil patratica."<<endl;
        cout<<"Dati inaltimea matricei: ";
        cin>>inaltime;
        cout<<"Dati lungimea matricei: ";
        cin>>lungime;
        system("cls");
    }
}
void Minesweeper::plasareMine()
{
    int i,j;
    if(nrMine==0)
        if((lungime*inaltime)%10==0)
            nrMine=(lungime*inaltime)/10;
        else nrMine=(lungime*inaltime)/10+1;
    for(int mine=0;mine<nrMine;mine++)
    {
        int x=rand()%inaltime;
        int y=rand()%lungime;

        if (matriceaSursa[x][y]=='*')
            mine--;
        else
            matriceaSursa[x][y]='*';
    }
    for(i=0;i<inaltime;i++)
        for(j=0;j<lungime;j++)
            matriceaAfisata[i][j]=char(176);
}
void Minesweeper::VerificareVecini()
{
    for (int a=0;a<inaltime;a++)
    {
        for (int b=0;b<lungime;b++)
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
                    matriceaSursa[a][b]=char(numarBombeVecine);
            }
        }
    }
}
void Minesweeper::umplere(int x, int y)
{
    int coada[2][1000],prim=0,ultim=0;
    nonmines++;
    coada[0][ultim]=x;
    coada[1][ultim]=y;
    matriceaAfisata[x][y]=matriceaSursa[x][y];
    ultim++;
    while(prim<ultim)
        {
            x=coada[0][prim];
            y=coada[1][prim];
            if(matriceaSursa[x][y]=='0')
                if (x==0 && y==0)
                {
                    coada[0][ultim]=x;
                    coada[1][ultim]=y+1;
                    if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                        {
                            nonmines++;
                            matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                            ultim++;
                        }
                    coada[0][ultim]=x+1;
                    coada[1][ultim]=y+1;
                    if(matriceaAfisata[x+1][y+1]==char(176) && matriceaAfisata[x+1][y+1]!='!')
                        {
                            nonmines++;
                            matriceaAfisata[x+1][y+1]=matriceaSursa[x+1][y+1];
                            ultim++;
                        }
                    coada[0][ultim]=x+1;
                    coada[1][ultim]=y;
                    if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                        {
                            nonmines++;
                            matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                            ultim++;
                        }
                    //nonmines=nonmines+3;
                }
                else
                    if (x==0 && y==lungime-1)
                    {
                        coada[0][ultim]=x;
                        coada[1][ultim]=y-1;
                        if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                            {
                                nonmines++;
                                matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                ultim++;
                            }
                        coada[0][ultim]=x+1;
                        coada[1][ultim]=y-1;
                        if(matriceaAfisata[x+1][y-1]==char(176) && matriceaAfisata[x+1][y-1]!='!')
                            {
                                nonmines++;
                                matriceaAfisata[x+1][y-1]=matriceaSursa[x+1][y-1];
                                ultim++;
                            }
                        coada[0][ultim]=x+1;
                        coada[1][ultim]=y;
                        if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                            {
                                nonmines++;
                                matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                                ultim++;
                            }
                        //nonmines=nonmines+3;
                    }
                    else
                        if (x==inaltime-1 && y==lungime-1)
                        {
                            coada[0][ultim]=x-1;
                            coada[1][ultim]=y;
                            if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                {
                                    nonmines++;
                                    matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                    ultim++;
                                }
                            coada[0][ultim]=x-1;
                            coada[1][ultim]=y-1;
                            if(matriceaAfisata[x-1][y-1]==char(176) && matriceaAfisata[x-1][y-1]!='!')
                                {
                                    nonmines++;
                                    matriceaAfisata[x-1][y-1]=matriceaSursa[x-1][y-1];
                                    ultim++;
                                }
                            coada[0][ultim]=x;
                            coada[1][ultim]=y-1;
                            if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                                {
                                    nonmines++;
                                    matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                    ultim++;
                                }
                            //nonmines=nonmines+3;
                        }
                        else
                            if (x==inaltime-1 && y==0)
                            {
                                coada[0][ultim]=x-1;
                                coada[1][ultim]=y;
                                if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                    {
                                        nonmines++;
                                        matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                        ultim++;
                                    }
                                coada[0][ultim]=x-1;
                                coada[1][ultim]=y+1;
                                if(matriceaAfisata[x-1][y+1]==char(176) && matriceaAfisata[x-1][y+1]!='!')
                                    {
                                        nonmines++;
                                        matriceaAfisata[x-1][y+1]=matriceaSursa[x-1][y+1];
                                        ultim++;
                                    }
                                coada[0][ultim]=x;
                                coada[1][ultim]=y+1;
                                if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                                    {
                                        nonmines++;
                                        matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                                        ultim++;
                                    }
                                //nonmines=nonmines+3;
                            }
                            else
                                if(x==0)
                                {
                                    coada[0][ultim]=x;
                                    coada[1][ultim]=y-1;
                                    if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                                        {
                                            nonmines++;
                                            matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                            ultim++;
                                        }
                                    coada[0][ultim]=x;
                                    coada[1][ultim]=y+1;
                                    if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                                        {
                                            nonmines++;
                                            matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                                            ultim++;
                                        }
                                    coada[0][ultim]=x+1;
                                    coada[1][ultim]=y-1;
                                    if(matriceaAfisata[x+1][y-1]==char(176) && matriceaAfisata[x+1][y-1]!='!')
                                        {
                                            nonmines++;
                                            matriceaAfisata[x+1][y-1]=matriceaSursa[x+1][y-1];
                                            ultim++;
                                        }
                                    coada[0][ultim]=x+1;
                                    coada[1][ultim]=y+1;
                                    if(matriceaAfisata[x+1][y+1]==char(176) && matriceaAfisata[x+1][y+1]!='!')
                                        {
                                            nonmines++;
                                            matriceaAfisata[x+1][y+1]=matriceaSursa[x+1][y+1];
                                            ultim++;
                                        }
                                    coada[0][ultim]=x+1;
                                    coada[1][ultim]=y;
                                    if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                                        {
                                            nonmines++;
                                            matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                                            ultim++;
                                        }
                                    //nonmines=nonmines+5;
                                }
                                else
                                    if(x==inaltime-1)
                                    {
                                        coada[0][ultim]=x;
                                        coada[1][ultim]=y-1;
                                        if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                                ultim++;
                                            }
                                        coada[0][ultim]=x;
                                        coada[1][ultim]=y+1;
                                        if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                                                ultim++;
                                            }
                                        coada[0][ultim]=x-1;
                                        coada[1][ultim]=y-1;
                                        if(matriceaAfisata[x-1][y-1]==char(176) && matriceaAfisata[x-1][y-1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x-1][y-1]=matriceaSursa[x-1][y-1];
                                                ultim++;
                                            }
                                        coada[0][ultim]=x-1;
                                        coada[1][ultim]=y+1;
                                        if(matriceaAfisata[x-1][y+1]==char(176) && matriceaAfisata[x-1][y+1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x-1][y+1]=matriceaSursa[x-1][y+1];
                                                ultim++;
                                            }
                                        coada[0][ultim]=x-1;
                                        coada[1][ultim]=y;
                                        if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                                ultim++;
                                            }
                                        //nonmines=nonmines+5;
                                    }
                                    else
                                        if(y==0)
                                        {
                                            coada[0][ultim]=x-1;
                                            coada[1][ultim]=y;
                                            if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                                ultim++;
                                            }
                                            coada[0][ultim]=x+1;
                                            coada[1][ultim]=y;
                                            if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                                                ultim++;
                                            }
                                            coada[0][ultim]=x-1;
                                            coada[1][ultim]=y+1;
                                            if(matriceaAfisata[x-1][y+1]==char(176) && matriceaAfisata[x-1][y+1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x-1][y+1]=matriceaSursa[x-1][y+1];
                                                ultim++;
                                            }
                                            coada[0][ultim]=x+1;
                                            coada[1][ultim]=y+1;
                                            if(matriceaAfisata[x+1][y+1]==char(176) && matriceaAfisata[x+1][y+1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x+1][y+1]=matriceaSursa[x+1][y+1];
                                                ultim++;
                                            }
                                            coada[0][ultim]=x;
                                            coada[1][ultim]=y+1;
                                            if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                                            {
                                                nonmines++;
                                                matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                                                ultim++;
                                            }
                                            //nonmines=nonmines+5;
                                        }
                                        else
                                            if(y==lungime-1)
                                            {
                                                coada[0][ultim]=x-1;
                                                coada[1][ultim]=y;
                                                if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x+1;
                                                coada[1][ultim]=y;
                                                if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x-1;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x-1][y-1]==char(176) && matriceaAfisata[x-1][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x-1][y-1]=matriceaSursa[x-1][y-1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x+1;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x+1][y-1]==char(176) && matriceaAfisata[x+1][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x+1][y-1]=matriceaSursa[x+1][y-1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                                    ultim++;
                                                }
                                                //nonmines=nonmines+5;
                                            }
                                            else
                                            {
                                                coada[0][ultim]=x-1;
                                                coada[1][ultim]=y;
                                                if(matriceaAfisata[x-1][y]==char(176) && matriceaAfisata[x-1][y]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x-1][y]=matriceaSursa[x-1][y];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x][y-1]==char(176) && matriceaAfisata[x][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x][y-1]=matriceaSursa[x][y-1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x-1;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x-1][y-1]==char(176) && matriceaAfisata[x-1][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x-1][y-1]=matriceaSursa[x-1][y-1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x+1;
                                                coada[1][ultim]=y+1;
                                                if(matriceaAfisata[x+1][y+1]==char(176) && matriceaAfisata[x+1][y+1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x+1][y+1]=matriceaSursa[x+1][y+1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x-1;
                                                coada[1][ultim]=y+1;
                                                if(matriceaAfisata[x-1][y+1]==char(176) && matriceaAfisata[x-1][y+1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x-1][y+1]=matriceaSursa[x-1][y+1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x+1;
                                                coada[1][ultim]=y-1;
                                                if(matriceaAfisata[x+1][y-1]==char(176) && matriceaAfisata[x+1][y-1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x+1][y-1]=matriceaSursa[x+1][y-1];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x+1;
                                                coada[1][ultim]=y;
                                                if(matriceaAfisata[x+1][y]==char(176) && matriceaAfisata[x+1][y]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x+1][y]=matriceaSursa[x+1][y];
                                                    ultim++;
                                                }
                                                coada[0][ultim]=x;
                                                coada[1][ultim]=y+1;
                                                if(matriceaAfisata[x][y+1]==char(176) && matriceaAfisata[x][y+1]!='!')
                                                {
                                                    nonmines++;
                                                    matriceaAfisata[x][y+1]=matriceaSursa[x][y+1];
                                                    ultim++;
                                                }
                                                //nonmines=nonmines+8;
                                            }
            prim++;
        }
    //nonmines=nonmines+ultim-1;
    /*for(int i=0;i<ultim;i++)
    {
        x=coada[0][i];
        y=coada[1][i];
        matriceaAfisata[x][y]=matriceaSursa[x][y];
        nonmines++;
    }*/
}
void Minesweeper::Mutare()
{
    char coloana;
    int linie, operatie;
    cout<<"Mai avetit de completat "<<lungime*inaltime-nonmines-nrMine<<" spatii fara mine."<<endl;
    Afiseaza_Matrice_Afisata();
    cout<<"Introduceti o linie de la 0 la "<<inaltime-1<<endl;
    cin>>linie;
    if (linie == VK_ESCAPE)
        exit(0);
    if (linie<0 || linie>=inaltime)
    {
        cout<<"Introduceti o linie de la 0 la "<<inaltime-1<<endl;
        system("pause");
        system("cls");
        Mutare();
    }
    cout<<"Introduceti o coloana de la A la "<<char(lungime+64)<<endl;
    cin>>coloana;
    if (coloana<'A' || coloana>=lungime+'A')
    {
        cout<<"Introduceti o coloana de la A la "<<char(lungime+64)<<endl;
        system("pause");
        system("cls");
        Mutare();
    }
    cout<<"Alegeti o operatie: 0 = deschidere; 1 = marcareca posibila bomba."<<endl;
    cin>>operatie;
    if(operatie<0 || operatie>1)
    {
        cout<<"Introduceti o operatie valida"<<endl;
        system("pause");
        system("cls");
        Mutare();
    }
    if(operatie==1 && matriceaAfisata[linie][coloana-65]=='!')
    {
        matriceaAfisata[linie][coloana-65]=char(176);
        nrFlaguri--;
        nonmines--;
        //system("pause");
        system("cls");
        Mutare();
    }
    if(operatie==1)
        {
            if(matriceaAfisata[linie][coloana-65]!=matriceaSursa[linie][coloana-65] && nrFlaguri<nrMine)
                {
                    matriceaAfisata[linie][coloana-65]='!';
                    nrFlaguri++;
                    nonmines++;
                }

            system("cls");
            Mutare();
        }
    else
    {
        if(matriceaAfisata[linie][coloana-65]=='!')
        {
            cout<<"Nu poti deschide ceva marcat ca posibila mina"<<endl;
            system("pause");
            system("cls");
            Mutare();
        }
        if (matriceaAfisata[linie][coloana-65]==matriceaSursa[linie][coloana-65])
        {
            system("cls");
            Mutare();
        }
        else
        {
            umplere(linie,coloana-65);
            //matriceaAfisata[linie][coloana-65]=matriceaSursa[linie][coloana-65];
            //nonmines++;
            system("cls");
        }
        if (lungime*inaltime-nonmines-nrMine<=0 || matriceaSursa[linie][coloana-65]=='*')
        {
            Mesaj_de_Incheiere();
        }
        else
            Mutare();
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
    for (a=0;a<inaltime;a++)
    {
        cout<<a<<" |";
        for (b=0;b<lungime;b++)
        {
            cout<<" "<<matriceaAfisata[a][b]<<" |";
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
    int a ,b, optiune;
    for(a=0;a<lungime*3;a++)
        cout<<"_";
    cout<<endl;
    for (a=0;a<inaltime;a++)
    {
        cout<<"|";
        for (b=0;b<lungime;b++)
        {
            cout<<matriceaSursa[a][b]<<" |";
        }
        cout<<endl;
        for(b=0;b<lungime*3;b++)
            cout<<"_";
        cout<<endl;
    }
    if (nonmines==lungime*inaltime-nrMine)
    {
        cout<<"Felicitari, ati castigat!"<<endl;
    }
    else
    {
        cout<<"Ati pierdut, mai incercati!"<<endl;
    }

    cout<<endl<<"Multumesc ca ati trecut pe aici!"<<endl;
    cout<<"Alegeti una din optiunile de mai jos"<<endl;
    cout<<"1. Mai incercati o data"<<endl;
    cout<<"2. Parasiti jocul"<<endl;
    cin>>optiune;
    if(optiune>2 || optiune <1)
    {
        cout<<"introduceti o optiune valida"<<endl;
        system("cls");
        Mesaj_de_Incheiere();
    }
    else
    {
        if(optiune==2)
            exit(0);
        if(optiune==1)
            {
                system("cls");
                srand(time(0));
                Minesweeper thisgame;
                thisgame.Mesaj_Bun_Venit();
                thisgame.plasareMine();
                //thisgame.Afiseaza_Matrice_Afisata();
                thisgame.VerificareVecini();
                thisgame.Mutare();
                //thisgame.Mesaj_de_Incheiere();
            }
    }
}

int main()
{
    srand(time(0));
    Minesweeper thisgame;
      thisgame.Mesaj_Bun_Venit();
    thisgame.plasareMine();
    //thisgame.Afiseaza_Matrice_Afisata();
    thisgame.VerificareVecini();
    thisgame.Mutare();
    //thisgame.Mesaj_de_Incheiere();
    return 0;
}
