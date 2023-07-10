#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
#define MAX_RESP 6
using namespace std;
class fait{
public :
 string nom_fait;
 fait* next;
 fait* create_fact();
 void insert_fact(fait**);
 bool search_fact(fait*);
 void display_fact();
 void set_nom(string nom){
    nom_fait=nom;}
 string get_nom(){
   return nom_fait;}};

class regle{
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
condition=cdt;}
 void set_resultat(string rslt){
resultat=rslt;} };

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
 return temp;
}

fait* fait:: create_fact(){
 fait* temp;
 temp=new(fait);
 if(temp!=nullptr){
   temp->nom_fait= nom_fait;
   temp->next=nullptr;}
 else
     cout<<"probleme d'allocation mémoire"<<endl;
 return temp;}

void fait::insert_fact(fait** h){
 if(h==nullptr)
 *h=this ;
 else{
       fait* temp;
       temp=*h ;
       while(temp->next!=nullptr){
           temp=temp->next;}
       temp->next=this;}}

  bool fait::search_fact(fait* h){
  if(h==nullptr)
      return false;
  else{
      fait* temp=h;
      while(temp->next!=nullptr){
          if((temp->nom_fait).compare(nom_fait)==0)
              return true;
              temp=temp->next;}
      return false;}}
    void fait::display_fact(){
 fait* temp=this;
 while(temp!=nullptr){
  cout<<temp->nom_fait<<endl;
  temp=temp->next;}}
 regle* regle:: create_rule(){
 regle* temp;
 temp=new(regle);
 if(temp!=nullptr){
     temp->condition=condition;
    temp->resultat=resultat;
     temp->next=nullptr;}
 else
     cout<<"probleme d'allocation mémoire"<<endl;
 return temp;}
 void regle::insert_rule(regle** h){
 if(h==nullptr)
     *h=this ;
 else{
       regle* temp;
       temp=*h;
       while(temp->next!=nullptr){
           temp=temp->next;}
       temp->next=this;}}
 int regle::search_rule(regle* h){
 if(h==nullptr)
     return -1;
 else{
     regle* temp=h;
     int i=1;
     while(temp->next!= nullptr){
         if(((temp->condition).compare(condition)==0 )&&((temp->resultat).compare(resultat)==0))
            return i;
            temp=temp->next;
            i++;}
    return -1;}}
  void regle::display_rule(){
regle* temp=this;
while(temp!=nullptr){
 cout<<temp->condition<<endl;
 cout<<temp->resultat<<endl;
 temp=temp->next;}}
  void regle::delete_rule(regle**h){
 int i=(*this).search_rule(*h);
 int current= 1;
  regle* temp= *h;
 regle* pre_temp= nullptr;
 while(current<i){
   pre_temp=temp;
   temp=temp->next;
   current++;}
 pre_temp->next=temp->next;
  temp=temp->next;
  delete temp;}
void moteur_inference(fait** head2,regle** head3){
fait* temp = *(head2);
while(temp!= NULL){
regle* temp1=*(head3);
while(temp1!= NULL){
if((temp1->condition.compare(temp->nom_fait))==0){
fait A;
A.set_nom(temp1->resultat);
(A.create_fact())->insert_fact(head2);
regle B;
B.set_condition(temp1->condition);
B.set_resultat(temp1->resultat);
(B.create_rule())->delete_rule(head3);
temp1=temp1->next;
}
temp=temp->next;
}}}
int main(){
fait f;
fait* head = f.create_fact();
regle r;
regle* head1 = r.create_rule();
ifstream projet;
projet.open("fait.txt",ios::in);
string ligne;
fait f1;
while(getline(projet,ligne)){ f1.set_nom(ligne);}
 (f1.create_fact())->insert_fact(&head);
ifstream projet1;
projet1.open("regle.txt",ios::in);
string ligne1;
regle r1;
int i=1;
while(getline(projet1,ligne1)){
if (i%2==1){
r1.set_condition(ligne);
}
else{
r1.set_resultat(ligne1);
(r1.create_rule())->insert_rule(&head1);
}
i++;
}

Qst *Q1=create_question("Why do you want to learn programming ?","For my kids","Make money","I don\'t know Just pick one for me","Just for fun","I\'m interested","Improve myself");
Qst *Q2=create_question("How do you want to get money?","Get a job","I have startup idea");
Qst *Q3=create_question("Which platform or field?","gaming","mobile","Entreprise","web","I just want money","I want to work for big tech companies");
Qst *Q4=create_question("Which Operating System?","Ios","Android");
Qst *Q5=create_question("What do you think about Microsoft?","I'm fun","Not bad","Suck");
Qst *Q6=create_question("Which company?","Google","Microsoft","Apple","Facebook");
Qst *Q7=create_question("Front_End or Back_End?","Front_End","Back_End");
Qst *Q8=create_question("Do you want to work for a corporate or a stratup?","corporate","stratup");
Qst *Q9=create_question("Which platform or field?","web","Gaming","Mobile","Entreprise");
Qst *Q10=create_question("Does your web app provides information in real time like Twitter?","Yes","No");
Qst *Q11=create_question("Do you want to learn something new?","Yes","No","Not sure");
Qst *Q12=create_question("Which one is your favourite toy?","Lego","Play_Doh","I\'ve an old and ugly toy but i love it so much");
Qst *Q13=create_question("Do you have a brilliant idea?","Yes","No");
Qst *Q14=create_question("How do you prefer to learn things?","Easy way","Best way","slighty harder way","The realy hard way");
Qst *Q15=create_question("Do you have an auto or manual car?","Auto","Manual");
Q1->liste_reponse[1].next=Q2;
Q2->liste_reponse[0].next=Q3;
Q2->liste_reponse[1].next=Q9;
Q3->liste_reponse[1].next=Q4;
Q3->liste_reponse[2].next=Q5;
Q3->liste_reponse[3].next=Q7;
Q7->liste_reponse[1].next=Q8;
Q8->liste_reponse[0].next=Q5;
Q8->liste_reponse[1].next=Q11;
Q11->liste_reponse[1].next=Q12;
Q11->liste_reponse[2].next=Q13;
Q3->liste_reponse[4].next=Q6;
Q9->liste_reponse[0].next=Q10;
Q10->liste_reponse[1].next=Q11;
Q1->liste_reponse[3].next=Q13;
Q13->liste_reponse[0].next=Q9;
Q13->liste_reponse[1].next=Q14;
Q14->liste_reponse[2].next=Q15;
Q1->liste_reponse[4].next=Q13;
Q1->liste_reponse[5].next=Q13;
fait f3;

//question principale
cout<<Q1->question<<endl;
for(i=0;i<6;i++){
 cout<<i+1<<":"<<Q1->liste_reponse[i].rsppos<<endl;
}
cout<<"TAPEZ VOTRE REPONSE"<<endl;//reponse de la question principale
int R;
cin>>R;
switch(R){
case 1:{
(*head).set_nom(Q1->liste_reponse[0].rsppos);//si il a choisi for my kids
 break;}
case 2:{//si il choisi make money
    fait *f;
    f->set_nom(Q1->liste_reponse[1].rsppos);
    f->insert_fact(&head);
    cout<<Q3->question<<endl;//why do you want to get money
    for(i=0;i<2;i++){
      cout<<i+1<<":"<<Q2->liste_reponse[i].rsppos<<endl;//la liste des choix de cette question
          }
    int R1;
    cin>>R1;
    switch(R1){
    case 1:{//si il choisi get a job
        fait f1;
        f1.set_nom(Q2->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
       cout<<Q3->question<<endl;
       for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q3->liste_reponse[i].rsppos<<endl;
            }
       int R2;
       cin>>R2;
       switch(R2){
         case 1:{
         fait f1;
        f1.set_nom(Q2->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
       cout<<Q3->question<<endl;
         }
       }

    break;
    }
    }
break;
}
case 3:{
fait f1;
        f1.set_nom(Q1->liste_reponse[2].rsppos);
        f1.insert_fact(&head);
 break;
}
case 4:{
    fait f1;
        f1.set_nom(Q1->liste_reponse[3].rsppos);
        f1.insert_fact(&head);
        cout<<Q13->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q13->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            switch(a){
            case 1:{
                fait f1;
        f1.set_nom(Q13->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
        cout<<Q9->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q9->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            if(a==1){
                fait f1;
        f1.set_nom(Q9->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
            }

            }
            case 2:{
            fait f1;
        f1.set_nom(Q13->liste_reponse[1].rsppos);
        f1.insert_fact(&head);
        cout<<Q14->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q14->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            fait f;
        f.set_nom(Q14->liste_reponse[a].rsppos);
        f.insert_fact(&head);
        if(a==2){
            cout<<Q15->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q15->liste_reponse[i].rsppos<<endl;
            }
            int c;
            cin>>c;
            fait f1;
        f1.set_nom(Q15->liste_reponse[c].rsppos);
        f.insert_fact(&head);

        }
            }
            }
 break;
}
case 5:{
    fait f1;
        f1.set_nom(Q1->liste_reponse[4].rsppos);
        f1.insert_fact(&head);
        cout<<Q13->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q13->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            switch(a){
            case 1:{
            fait f1;
        f1.set_nom(Q13->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
        cout<<Q14->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q13->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            fait f;
        f.set_nom(Q13->liste_reponse[a].rsppos);
        f.insert_fact(&head);

            }
            }
break;
}
case 6:{
        fait f1;
        f1.set_nom(Q1->liste_reponse[4].rsppos);
        f1.insert_fact(&head);
        cout<<Q13->question<<endl;
        for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q13->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            switch(a){
            case 1:{
            fait f1;
        f1.set_nom(Q13->liste_reponse[0].rsppos);
        f1.insert_fact(&head);
        cout<<Q14->question<<endl;
       for(i=0;i<6;i++){
          cout<<i+1<<":"<<Q13->liste_reponse[i].rsppos<<endl;
            }
            int a;
            cin>>a;
            fait f;
        f.set_nom(Q13->liste_reponse[a].rsppos);
        f.insert_fact(&head);

            }
            }
break;
}
}
moteur_inference(&head,&head1);
f1.display_fact();
return 0;}
