#include <iostream>
#include"fonction.cpp"

using namespace std;

int main()
{
   string nom_fichier;
   int reponse_menu;
   cout<<" veuillez entrer le nom du fichier dont lequel vous voulez enregistrer votre systeme expert suivi de l'extension.cpp :"<<endl;
   cin>>nom_fichier;
   ofstream projetcpp;
   projetcpp.open(nom_fichier);
   projetcpp<<"#include<iostream>"<<endl;
   projetcpp<<"#include<cstring>"<<endl;
   projetcpp<<"#include<fstream>"<<endl;
   projetcpp<<"#include<ctime>"<<endl;
   projetcpp<<"using namespace std;\n"<<endl;
   projetcpp<<"class fait{"<<endl;
   projetcpp<<"public :"<<endl;
   projetcpp<<" string nom_fait;"<<endl;
   projetcpp<<" fait* next;"<<endl;
   projetcpp<<"fait* create_fact();"<<endl;
   projetcpp<<"void insert_fact(fait**);"<<endl;
   projetcpp<< "bool search_fact(fait*);"<<endl;
   projetcpp<<"void display_fact();"<<endl;
   projetcpp<<"void set_nom(string nom){"<<endl;
   projetcpp<<"nom_fait=nom;}"<<endl;
   projetcpp<<"string get_nom(){"<<endl;
   projetcpp<<"return nom_fait;}}; \n"<<endl;
   projetcpp<<"class regle{"<<endl;
   projetcpp<<"public :"<<endl;
   projetcpp<<" string condition;"<<endl;
   projetcpp<<" string resultat;"<<endl;
   projetcpp<<"regle *next;"<<endl;
   projetcpp<<"regle* create_rule();"<<endl;
   projetcpp<<"void insert_rule(regle**);"<<endl;
   projetcpp<<"void delete_rule(regle**);"<<endl;
   projetcpp<<" int search_rule(regle*);"<<endl;
   projetcpp<<" void display_rule();"<<endl;
   projetcpp<<" void set_condition(string cdt){"<<endl;
   projetcpp<<"condition=cdt;}"<<endl;
   projetcpp<<" void set_resultat(string rslt){"<<endl;
   projetcpp<<"resultat=rslt;} };\n"<<endl;
   projetcpp<<"fait* fait:: create_fact(){"<<endl;
   projetcpp<<" fait* temp;"<<endl;
   projetcpp<<" temp=new(fait);"<<endl;
   projetcpp<<" if(temp!=nullptr){"<<endl;
   projetcpp<<"   temp->nom_fait= nom_fait;"<<endl;
   projetcpp<<"   temp->next=nullptr;}"<<endl;
   projetcpp<<" else"<<endl;
   projetcpp<<"     cout<<\"probleme d'allocation mémoire\"<<endl;"<<endl;
   projetcpp<<" return temp;}\n"<<endl;
   projetcpp<<"void fait::insert_fact(fait** h){"<<endl;
   projetcpp<<" if(h==nullptr)"<<endl;
   projetcpp<<" *h=this ;"<<endl;
   projetcpp<<" else{"<<endl;
   projetcpp<<"       fait* temp;"<<endl;
   projetcpp<<"       temp=*h ;"<<endl;
   projetcpp<<"       while(temp->next!=nullptr){"<<endl;
   projetcpp<<"           temp=temp->next;}"<<endl;
   projetcpp<<"       temp->next=this;}}\n"<<endl;

   projetcpp<<"  bool fait::search_fact(fait* h){"<<endl;
   projetcpp<<"  if(h==nullptr)"<<endl;
   projetcpp<<"      return false;"<<endl;
   projetcpp<<"  else{"<<endl;
   projetcpp<<"      fait* temp=h;"<<endl;
   projetcpp<<"      while(temp->next!=nullptr){"<<endl;
   projetcpp<<"          if((temp->nom_fait).compare(nom_fait)==0)"<<endl;
   projetcpp<<"              return true;"<<endl;
   projetcpp<<"              temp=temp->next;}"<<endl;
   projetcpp<<"      return false;}}"<<endl;

   projetcpp<<"    void fait::display_fact(){"<<endl;
   projetcpp<<" fait* temp=this;"<<endl;
   projetcpp<<" while(temp!=nullptr){"<<endl;
   projetcpp<<"  cout<<temp->nom_fait<<endl;"<<endl;
   projetcpp<<"  temp=temp->next;}}"<<endl;

   projetcpp<<" regle* regle:: create_rule(){"<<endl;
   projetcpp<<" regle* temp;"<<endl;
   projetcpp<<" temp=new(regle);"<<endl;
   projetcpp<<" if(temp!=nullptr){"<<endl;
   projetcpp<<"     temp->condition=condition;"<<endl;
   projetcpp<<"    temp->resultat=resultat;"<<endl;
   projetcpp<<"     temp->next=nullptr;}"<<endl;
   projetcpp<<" else"<<endl;
   projetcpp<<"     cout<<\"probleme d'allocation mémoire\"<<endl;"<<endl;
   projetcpp<<" return temp;}"<<endl;

   projetcpp<<" void regle::insert_rule(regle** h){"<<endl;
   projetcpp<<" if(h==nullptr)"<<endl;
   projetcpp<<"     *h=this ;"<<endl;
   projetcpp<<" else{"<<endl;
   projetcpp<<"       regle* temp;"<<endl;
   projetcpp<<"       temp=*h;"<<endl;
   projetcpp<<"       while(temp->next!=nullptr){"<<endl;
   projetcpp<<"           temp=temp->next;}"<<endl;
   projetcpp<<"       temp->next=this;}}"<<endl;

   projetcpp<<" int regle::search_rule(regle* h){"<<endl;
   projetcpp<<" if(h==nullptr)"<<endl;
   projetcpp<<"     return -1;"<<endl;
   projetcpp<<" else{"<<endl;
   projetcpp<<"     regle* temp=h;"<<endl;
   projetcpp<<"     int i=1;"<<endl;
   projetcpp<<"     while(temp->next!= nullptr){"<<endl;
   projetcpp<<"         if(((temp->condition).compare(condition)==0 )&&((temp->resultat).compare(resultat)==0))"<<endl;
    projetcpp<<"            return i;"<<endl;
    projetcpp<<"            temp=temp->next;"<<endl;
    projetcpp<<"            i++;}"<<endl;
    projetcpp<<"    return -1;}}"<<endl;

   projetcpp<<"  void regle::display_rule(){"<<endl;
   projetcpp<<"regle* temp=this;"<<endl;
   projetcpp<<"while(temp!=nullptr){"<<endl;
   projetcpp<<" cout<<temp->condition<<endl;"<<endl;
   projetcpp<<" cout<<temp->resultat<<endl;"<<endl;
   projetcpp<<" temp=temp->next;}}"<<endl;

   projetcpp<<"  void regle::delete_rule(regle**h){"<<endl;
   projetcpp<<" int i=(*this).search_rule(*h);"<<endl;
   projetcpp<<" int current= 1;"<<endl;
   projetcpp<<"  regle* temp= *h;"<<endl;
   projetcpp<<" regle* pre_temp= nullptr;"<<endl;
   projetcpp<<" while(current<i){"<<endl;
   projetcpp<<"   pre_temp=temp;"<<endl;
   projetcpp<<"   temp=temp->next;"<<endl;
   projetcpp<<"   current++;}"<<endl;
   projetcpp<<" pre_temp->next=temp->next;"<<endl;
   projetcpp<<"  temp=temp->next;"<<endl;
   projetcpp<<"  delete temp;}"<<endl;

   projetcpp<<"void moteur_inference(fait** head2,regle** head3){"<<endl;
   projetcpp<<"fait* temp = *(head2)" <<endl;
   projetcpp<<"while(temp!= NULL){"<<endl;
   projetcpp<<"regle* temp1=*(head3)"<<endl;
   projetcpp<<"while(temp1!= NULL){"<<endl;
   projetcpp<<"if((temp1->condition.compare(temp->nom_fait))==0){"<<endl;
   projetcpp<<"fait A;"<<endl;
   projetcpp<<"A.set_nom(temp1->resultat);"<<endl;
   projetcpp<<"(*(A.create_fact())).insert_fact(&head2);"<<endl;
   projetcpp<<"regle B;"<<endl;
   projetcpp<<"B.set_condition(temp1->condition);"<<endl;
   projetcpp<<"B.set_resultat(temp1->resultat);"<<endl;
   projetcpp<<"(*(B.create_rule())).delete_rule(&head3);"<<endl;
   projetcpp<<"temp1=temp1->next;"<<endl;
   projetcpp<<"}"<<endl;
   projetcpp<<"temp=temp->next;"<<endl;
   projetcpp<<"}}}"<<endl;
   projetcpp<<"int main(){"<<endl;
   projetcpp<<"fait f;"<<endl;
   projetcpp<<"fait* head = f.create_fact();"<<endl;
   projetcpp<<"regle r;"<<endl;
   projetcpp<<"regle* head1 = r.create_rule();"<<endl;
   system("cls");
    menu_principal();
    do{
   cout<<"\t\t\t\t\tEntrer votre choix :";
   cin>>reponse_menu;
   switch(reponse_menu){
   case 1:{
   	    system("cls");
        menu_fait();
        cin>>reponse_menu;
        switch(reponse_menu){
        case 1:{
        system("cls");
        ofstream projet;
        projet.open("fait.txt",ios::out|ios::app);
        cout<<"\n\n\t\t\tveuillez entrer le nombre de faits à ajouter"<<endl;
        int nbf;
        cin>>nbf;
        for(int i=0;i<nbf;i++){
        fflush(stdin);
        cout<<"entrer le nom du fait"<<endl;
        string nomfait;
        getline(cin,nomfait);
        projet<<nomfait<<"\n";
        }
        projet.close();
        projetcpp<<"ifstream projet;"<<endl;
        projetcpp<<"projet.open(\"fait.txt\",ios::in);"<<endl;
        projetcpp<<"string ligne;"<<endl;
        projetcpp<<"fait f1;"<<endl;
        projetcpp<<"while(getline(projet,ligne)){ f1.set_nom(ligne);}"<<endl;
        projetcpp<<" *(f1.create_fact()).insert_fact(&head);"<<endl;
        break;
        }
        case 2:{
        system("cls");
        string nom_fait_supp;
        fflush(stdin);
        cout<<"\n\n\t\t\tEntrer le fait a supprimer :"<<endl;
        getline(cin,nom_fait_supp);
        ofstream projet1;
        projet1.open("fait1.txt",ios::out);
        ifstream projet2;
        projet2.open("fait.txt",ios::in);
        string ligne;
        while(getline(projet2,ligne)){
            if(ligne!=nom_fait_supp){
               projet1<<ligne;
            }
        }
        projet1.close();
        projet2.close();
        remove("fait.txt");
        rename("fait1.txt","fait.txt");
        break;
        }
        }
    break;
   }
   case 2:{
   	    system("cls");
        menu_regle();
        cin>>reponse_menu;
        switch(reponse_menu){
            case 1:{
               system("cls");
              ofstream projet1;
              projet1.open("regle.txt",ios::out|ios::app);
              string cond;
              string res;
              int nbrr;
              cout<<"Combien de regles vous voulez entrer"<<endl;
              cin>>nbrr;
              for(int i=0;i<nbrr;i++){
              fflush(stdin);
              cout<<"Entrez la condition"<<endl;
              getline(cin,cond);
              projet1<<cond<<endl;
              cout<<"Entrez le resultat"<<endl;
              getline(cin,res);
              projet1<<res<<endl;
              }
             projet1.close();
             projetcpp<<"ifstream projet1;"<<endl;
             projetcpp<<"projet1.open(\"regle.txt\",ios::in);"<<endl;
             projetcpp<<"string ligne1;"<<endl;
             projetcpp<<"regle r1;"<<endl;
             projetcpp<<"int i=1;"<<endl;
             projetcpp<<"while(getline(projet1,ligne1)){ "<<endl;
             projetcpp<<"if (i%2==1){"<<endl;
             projetcpp<<"r1.set_condition(ligne);"<<endl;
             projetcpp<<"}"<<endl;
             projetcpp<<"else{"<<endl;
             projetcpp<<"r1.set_resultat(ligne);"<<endl;
             projetcpp<<" *(r1.create_rule()).insert_rule(&head1);"<<endl;
             projetcpp<<"}"<<endl;
             projetcpp<<"i++;"<<endl;
             projetcpp<<"}"<<endl;
             break;
            }
           case 2:{
               system("cls");
                 ofstream projet3;
                 projet3.open("regle1.txt",ios::out);
                 ifstream projet4;
                 projet4.open("regle.txt",ios::in);
                 string ligne;
                 string nom_condition_supp;
                 cout<<"entrer la condition a supprimer :"<<endl;
                 fflush(stdin);
                 getline(cin,nom_condition_supp);
                 int i=0;
                 while(getline(projet4,ligne)){
                  if(ligne!=nom_condition_supp && i==0){
                   projet3<<ligne<<endl;
                     }
                  if(ligne==nom_condition_supp){
                    i=1;
                  }
                  else{
                    i=0;
                  }
                    }
                 projet3.close();
                 projet4.close();
                 remove("regle.txt");
                 rename("regle1.txt","regle.txt");

           break;
           }
   }
   break;
   }

  }}while(reponse_menu!=0);
  projetcpp<<"return 0;}"<<endl;
  cout<<">>>>>>>>>>>>>>>> MERCI D\'AVOIR UTILISER CETTE APPLICATION <<<<<<<<<<<<<<<"<<endl;
    return 0;
}

