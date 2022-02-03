#include  <cstdlib>
#include  <iostream>
#include  <conio.h>
#include  <windows.h>
#include  <stdio.h>
#include  <stdlib.h>
#define vertices 500
#define nodos 300

using namespace std;

struct  orden{
int  grado; //representa el numero  de conexiones
int  color; // representa el valor del numero
int  n;  //representa el numero  de vertice
};
typedef struct  orden ver;

int B[nodos];//,ad[vertices][vertices];

//Ordenamos Mediante el Metodo de Ordenacion: Inserccion
void OrdenarMayaMen(int n, ver v[])
{
    int i,k;
    int aux,aux1;
    for(i=1;i < n;i++)
    {
            aux=v[i].grado;
            aux1=B[i];
            k=i-1;
            while(k >=0 && aux > v[k].grado)
            {
                v[k+1].grado=v[k].grado;
                B[k+1]=B[k];
                k=k-1;
            }
            v[k+1].grado=aux;
            B[k+1]=aux1;
    }
}

void IngresarMatriz(int ad[][vertices],int nds, int arst)//,int ad[][vertices]) //Es  para guardar la matriz de  Adyacencias :P
{
  int i,j,nodoi,nodof;

  for(i=0;i < nds;i++)
   { for(j=0;j < nds;j++)
        { ad[i][j]=0;}
   }

  //Llenamos la  matriz
  for(i=0;i < arst;i++)
   { cout << "\n\n\tArista " << i+1 << "\n";
     cout << "\tN. inicio: ";
     cin >> nodoi;
     cout << "\tN. termino: ";
     cin >> nodof;

     ad[nodoi-1][nodof-1]=1;
     ad[nodof-1][nodoi-1]=1;
   }

   //Matriz de Adyacencia
  /* for(i=0;i < nds;i++)
     { for(j=0;j < nds;j++)
         ad[i][j]=ad[i][j];

      }*/
}


void Greedy(int ad[][vertices],int nds)//,int  ad[vertices][vertices])
{
  ver v[nds];
  int i,j,aux,zz,max=1;

  //Etapa de  Coloracion
   for(i=0;i < nds;i++)
    {v[i].color=1;
     zz=0;
     aux=1;
     while(aux==1)
      {for(j=0;j < nds;j++)
         { if(ad[j][i]==1)
            {if(v[i].color==v[j].color)
               { zz=1;}
            }
         }
         if(zz==1)
           {aux=1;
            zz=0;
            v[i].color++;
           }
         else
            {aux=0;}
            if(v[i].color   >   max)
              { max=v[i].color;}
       }
     }

  cout << "\n\tAlgoritmo Voraz \n" << "\tmaxcolor= " << max << "\n";

  //Se imprime el  conjunto de  vertices  de  cada color
  for(i=0;i < max;i++)
  {printf("\t  %c= { ",'a'+i);
    for(j=0;j < nds;j++)
     { if(v[j].color==i+1)
         cout << " " << j+1;
     }
    cout << "  }\n";
  }

}

void WelshPowell(int ad[][vertices],int  nds)//,int ad[][vertices])
{
  ver v[nds];
  int x,y,i,j,aux,zz,max=1;
  //Se inicializa  el  grado y  color en  cero
  for(i=0;i < nds;i++)
  { v[i].grado=0;
    v[i].color=0;
    v[i].n=i;
  }
   //Se encuentra el  grado de  los vertices.
   for(i=0;i < nds;i++)
   {for(j=0;j < nds;j++)
       {if(ad[i][j]==1)
          {v[i].grado++;
           v[j].grado++;
           //cout <  < " " <  < v[i].grado <  < " " <  < v[j].grado <  < endl;
          }
        }
   }

   for(i=0;i < nds;i++)
   {  v[i].grado=v[i].grado/2;
      //cout <  < " " <  < v[i].grado <  < endl;
      B[i]=i;
   }
   //Ordenacion en  funcion  de  sus   grados!
   OrdenarMayaMen(nds,v);
   for(i=0;i < nds;i++)
      v[i].n=B[i];

  //Etapa de Coloracion
   for(i=0;i < nds;i++)
    {v[i].color=1;
     zz==0;
     aux=1;
      while(aux==1)
      { for(j=0;j < nds;j++)
         { if(ad[v[j].n][v[i].n]==1)
             {if(v[i].color==v[j].color)
               {zz=1;}
             }
          }
         if(zz==1)
         {v[i].color++;
          zz=0;
          aux=1;
         }else
          {aux=0;
          }
          if(v[i].color > max)
            {max=v[i].color;
            }
      }
     }
 //Se  Imprime el  Coloreo

  cout << "\n\tAlgoritmo de coloraci\xa2n Welsh-Powell\n" << "\tmaxcolor= " << max << "\n";

  //Se imprime el  conjunto de  vertices  de  cada color
  for(i=0;i < max;i++)
   { printf("\t %c= { ",'a'+i);
      for(j=0;j < nds;j++)
       { if(v[j].color==i+1)
          cout << " " << v[j].n+1;
       }
      cout << "  }\n";
   }

}

void MMI(int ad[][vertices],int  nds)//,int ad[][vertices])
{
ver v[nds];
int x,y,i,j,k,aux,zz,max=1;

  //Se inicializa  el  grado y  color en  cero
   for(i=0;i < nds;i++)
    {v[i].grado=0;
     v[i].color=0;
     v[i].n=i+1;
    }
   //Se encuentra el  grado de  los vertices.
    for(i=0;i < nds;i++)
     {for(j=0;j < nds;j++)
       { if(ad[i][j]==1)
           {v[i].grado++;
            v[j].grado++;
           }
       }
     }

    for(i=0;i < nds;i++)
       v[i].grado=v[i].grado/2;

   k=nds;
   for(i=0;i < nds;i++)
     { v[i].n=B[k-1];
       k--;
     }

    //Etapa de  Coloracion
   //v[0].color=1;
   for(i=0;i < nds;i++)
    { v[i].color=1;
      zz==0;
      aux=1;
      while(aux==1)
       { for(j=0;j < nds;j++)
           {if(ad[v[i].n][v[j].n])
              { if(v[i].color==v[j].color)
                {zz=1;}
              }
           }
           if(zz==1)
           { v[i].color++;
             zz=0;
             aux=1;
           }else
           {aux=0;}
              if(v[i].color > max)
               { max=v[i].color;}
        }
     }

   //Se  Imprime el  Coloreo
  cout << "\n\tAlgoritmo de  coloraci\xa2n Matula-Marble-Isaacson\n" << "\tmaxcolor= " << max << "\n";

  //Se imprime el  conjunto de  vertices  de  cada   color
  for(i=0;i < max;i++)
    {printf("\t %c= { ",'a'+i);
     for(j=0;j < nds;j++)
      { if(v[j].color==i+1)
         cout << " " << v[j].n+1;
      }
    cout << "  }\n";
   }

}

int main(int argc, char *argv[])
{
  int i,j,cant_nodos,cant_aristas,ad[vertices][vertices];
  char s,N,n;
  do{
  cout << "\n\t\tALGORITMOS HEURISTICOS PARA EL COLOREADO DE GRAFOS\n";
  cout << "\t\t--------------------------------------------------\n";

  cout << "\n\n\t Ingrese Datos \n";
  cout << "\n\t Num. Nodos: ";
  cin >> cant_nodos;
  cout << "\t Aristas: ";
  cin >> cant_aristas;

  //Aqui se  crea la matriz de  adyacencia
  IngresarMatriz(ad,cant_nodos,cant_aristas);//,ad);
  //Mostrar Matriz de Adyacencia
  /* cout <  < "\n\t";
   for(i=0;i < nds;i++)
     { for(j=0;j < nds;j++)
         ad[i][j]=ad[i][j];
        cout <  < "\n\t";
      }
  */
  //Se colorea vertice  a  vertice en  el  orden inicial
  Greedy(ad,cant_nodos);//,ad);
  //Se colorea vertice  a  vertice iniciando  por los de  mayor  grado
  WelshPowell(ad,cant_nodos);//,ad);
  //Se colorea vertice  a  vertice iniciando  por los de  menor  grado
  MMI(ad,cant_nodos);//,ad);

 cout << "\n\tSi desea continuar presione cualquier tecla \n\tSi no escriba 'n' o 'N': ";
 s=getch();
 system("cls");
  }while(s!='N' && s!='n');
 cout << "Hasta Luego!!!!";
 Sleep(1600);
 exit(0);

 cout << "\n\n";
 system("PAUSE");
}
