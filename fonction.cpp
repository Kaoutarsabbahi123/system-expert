//SYSTEME EXPERT BRUT
#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
#include"header.h"
using namespace std;

void menu_principal(){
cout<<"\t\t\t\t\t>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<"<<endl;
cout<<"\t\t\t\t\t 1.FAITS                         "<<endl;
cout<<"\t\t\t\t\t 2.REGLES                        "<<endl;
cout<<"\t\t\t\t\t 0.POUR QUITTER L'APPLICATION    "<<endl;
cout<<"\t\t\t\t\t    -----------------------------"<<endl;
cout<<"\t\t\t\t\t          Choisir :[1/2/0]"<<endl;
cout<<"\t\t\t\t\t    -----------------------------\n\n"<<endl;
}

void menu_fait(){
cout<<"\t\t\t\t\t>>>>>>>>>>>>MENU FAIT<<<<<<<<<<<<<"<<endl;
cout<<"\t\t\t\t\t1.CREER LA BASE DE FAIT          "<<endl;
cout<<"\t\t\t\t\t2.POUR SUPPRIMER UN FAIT         "<<endl;
cout<<"\t\t\t\t\t    -----------------------------"<<endl;
cout<<"\t\t\t\t\t          Choisir :[1/2]"<<endl;
cout<<"\t\t\t\t\t    -----------------------------\n\n"<<endl;
}


void menu_regle(){
cout<<"\t\t\t\t\t>>>>>>>>>>>>MENU REGLE<<<<<<<<<<<<<"<<endl;
cout<<"\t\t\t\t\t1.POUR AJOUTER UNE REGLE          "<<endl;
cout<<"\t\t\t\t\t2.POUR SUPPRIMER UNE REGLE        "<<endl;
cout<<"\t\t\t\t\t    -----------------------------"<<endl;
cout<<"\t\t\t\t\t          Choisir :[1/2]"<<endl;
cout<<"\t\t\t\t\t    -----------------------------\n\n"<<endl;
}
/*fait* fait:: create_fact()
{
    fait* temp;
    temp=new(fait);
    if(temp!=nullptr)
    {
        temp->nom_fait= nom_fait;
        temp->next=nullptr;
    }
    else
        cout<<"probleme d'allocation mémoire"<<endl;
    return temp;
}

void fait::insert_fact(fait** h)
{
    if(h==nullptr)
        *h=this ;
    else
        {
          fait* temp;
          temp=*h ;
          while(temp->next!=nullptr)
          {
              temp=temp->next;
          }
          temp->next=this;
        }
}

bool fait::search_fact(fait* h)
{
    if(h==nullptr)
        return false;
    else
    {
        fait* temp=h;
        while(temp->next!=nullptr)
        {
            if((temp->nom_fait).compare(nom_fait)==0)
                return true;
                temp=temp->next;
        }
        return false;
    }
}

void fait::display_fact()
{
   fait* temp=this;
   while(temp!=nullptr){
    cout<<temp->nom_fait<<endl;
    temp=temp->next;
   }
}

regle* regle:: create_rule()
{
    regle* temp;
    temp=new(regle);
    if(temp!=nullptr)
    {
        temp->condition=condition;
        temp->resultat=resultat;
        temp->next=nullptr;
    }
    else
        cout<<"probleme d'allocation mémoire"<<endl;
    return temp;
}

void regle::insert_rule(regle** h)
{
    if(h==nullptr)
        *h=this ;
    else
        {
          regle* temp;
          temp=*h;
          while(temp->next!=nullptr)
          {
              temp=temp->next;
          }
          temp->next=this;
        }
}

int regle::search_rule(regle* h)
{
    if(h==nullptr)
        return -1;
    else
    {
        regle* temp=h;
        int i=1;
        while(temp->next!= nullptr)
        {
            if(((temp->condition).compare(condition)==0 )&&((temp->resultat).compare(resultat)==0))
                return i;
                temp=temp->next;
                i++;
        }
        return -1;
    }
}

void regle::display_rule()
{
   regle* temp=this;
   while(temp!=nullptr){
    cout<<temp->condition<<endl;
    cout<<temp->resultat<<endl;
    temp=temp->next;
   }
}

void regle::delete_rule(regle**h)
{
  int i=(*this).search_rule(*h);
  int current= 1;
  regle* temp= *h;
  regle* pre_temp= nullptr;
  while(current<i)
  {
      pre_temp=temp;
      temp=temp->next;
      current++;
  }
  pre_temp->next=temp->next;
  temp=temp->next;
  delete temp;

}*/

Qst* create_question(string quest,string rsp1="none",string rsp2="none",string rsp3="none",string rsp4="none",string rsp5="none",string rsp6="none"){
 Qst* temp=new(Qst);
 temp->question=quest;
(temp->liste_reponse[0]).rsppos=rsp1;
(temp->liste_reponse[0]).next=nullptr;
(temp->liste_reponse[1]).rsppos=rsp2;
(temp->liste_reponse[1]).next=nullptr;
(temp->liste_reponse[2]).rsppos=rsp3;
(temp->liste_reponse[2]).next=nullptr;
(temp->liste_reponse[3]).rsppos=rsp4;
(temp->liste_reponse[3]).next=nullptr;
(temp->liste_reponse[4]).rsppos=rsp5;
(temp->liste_reponse[4]).next=nullptr;
(temp->liste_reponse[5]).rsppos=rsp6;
(temp->liste_reponse[5]).next=nullptr;
 temp->reponse="NONE";
 return temp;
}
