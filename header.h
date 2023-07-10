#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED



#endif // HEADER_H_INCLUDED
#ifndef HEADERALGO_H_INCLUDED
#define HEADERALGO_H_INCLUDED



#endif // HEADERALGO_H_INCLUDED


#include<iostream>
#include<cstring>
#include<fstream>
#define MAX_RESP 6
using namespace std;


//la classe des faits
class fait
{
    public :
      string nom_fait;
      fait* next;
      fait* create_fact();
      void insert_fact(fait**);
      bool search_fact(fait*);
      void display_fact();
      //setter
      void set_nom(string nom){
      nom_fait=nom;
      }
      //getter
      string get_nom(){
      return nom_fait;
      }
};

//la classe des regles
class regle
{
    public :
      string condition;
      string resultat;
      regle *next;
      regle* create_rule();
      void insert_rule(regle**);
      void delete_rule(regle**);
      int search_rule(regle*);
      void display_rule();
      void set_condition(string cdt){
      condition=cdt;
      }
      void set_resultat(string rslt){
      resultat=rslt;
      }
};
typedef struct Qst;
typedef struct A{
string rsppos;
Qst* next;
}A;

typedef struct Qst
{
    string question;
    A liste_reponse[MAX_RESP];
    string reponse;

}Qst;

Qst* create_question();
