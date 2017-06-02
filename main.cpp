#include<stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
#define endl '\n'
//#include <iostream>
//▒▒▒▒ ☩  ☫♞ Enhanced By H3inZuM™ ♞☫  ☩ ▒▒▒▒
//#include<windows.h>
using namespace std;
const int CARACTERES = 26; // Alfabetillo
const int STATUS = 100000; // numero de estados 10*10000

struct registro{
    struct nodos{
    int c;
    int a[CARACTERES];
  };

  nodos arbolito[STATUS];// arbolito
  int nodos;

  void clear(){
    arbolito[nodos].c = 0;
    memset(arbolito[nodos].a, -1, sizeof arbolito[nodos].a);
    nodos++;
  }

  void init(){
    nodos = 0;
    clear();
  }

  int add(const string &s, int valor, bool query = 0){ //Añadiendo
    int punternodo = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = s[i] - 'A';
      if(arbolito[punternodo].a[id] == -1){
        if(query) return 0;
        arbolito[punternodo].a[id] = nodos;
        clear();
      }
      punternodo = arbolito[punternodo].a[id];
      if(!query) arbolito[punternodo].c += valor;
    }
    return arbolito[punternodo].c;
  }

  long long BusquedaDFS(int nodos) {//Busqueda en el grafo ---> algoritmo "Depth First Search"
    long long resul = abs(arbolito[nodos].c); //tomando el absoluto
    for (int i = 0; i < 26; ++i) {
      if (arbolito[nodos].a[i] != -1) {
        resul += BusquedaDFS(arbolito[nodos].a[i]);
      }
    }
    return resul;
  }
};

registro arbolito;


int main() {
  cout<<"###########################################################"<<endl;
  cout<<"################# DISENIO DE CAMISETAS ####################"<<endl;
  cout<<"###########################################################"<<endl<<endl;
  cout<<"INGRESE CANTIDAD DE JUGADORES Y SUS APELLIDOS:"<<endl<<endl;
  //cout<<""<<endl;
  ios_base::sync_with_stdio(false);//mezclar flujo E / S de C y C ++
  SetConsoleTitle("<---> #### Enhanced By H3inZuM ####<--->");
  cin.tie(NULL);// disvinculando cin de cout
  system("color a");
  int n;
  int j=1;
  cout<<""<<endl;
  cout<<"##### CANTIDAD MAX. DE LETRAS QUE SE PUEDEN IMPRIMIR #####"<<endl<<endl;

  while (cin >> n && n != -1) { //Hasta que ingrese -1
    cout<<"CONJUNTO:"<<j<<endl<<endl;
    string lineas;
    arbolito.init();
    int total = 0;
    j+=1;

      for (int i = 0; i < n; ++i) { //conteo
      cin >> lineas;
      arbolito.add(lineas, 1);
      total += lineas.size();
    }

      for (int i = 0; i < n; ++i) {
      cin >> lineas;
      arbolito.add(lineas, -1);
      total += lineas.size();
    }

    total -= arbolito.BusquedaDFS(0);// Imprimiendo total de letras
    cout <<"  "<< (total >> 1)<< endl<<endl;
    }
  return 0;
  //▒▒▒▒ ☩  ☫♞ Enhanced By H3inZuM™ ♞☫  ☩ ▒▒▒▒
}
