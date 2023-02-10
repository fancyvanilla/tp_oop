#include <iostream>
#include <string>

using namespace std ;


class article
{ 
    private:
    int code;
    string designation ;
    int quantity ;

  public:
        article() {
            code = 0;
            designation = "";
            quantity = 0;
        }
        void set_code(int c) { code = c; }
        int get_code() { return (code); }
        void set_designation(string d) { designation = d; }
        string get_designation() { return (designation); }
        void set_stock(int s) { quantity = s; }
        int get_stock() { return (quantity); }

        article(int code,string design,int quant)
        {
            this->code=code;
            this->designation=design;
            this->quantity=quant;
        }
        operator int (void)
        {
            return(code);
        }
};

class produit_fini : public article 
{
    private:
        string marque;
        float prix;
        int nb_operations;
        string operations[10];
        produit_fini* next;
    public:
        produit_fini() : article() {
            marque = "";
            prix = 0;
            nb_operations = 0;
        }
        void set_marque(string m) { marque = m; }
        string get_marque() { return (marque); }
        void set_prix_revient(float p) { prix = p; }
        float get_prix_revient() { return (prix); }
        void set_nb_operations(int n) { nb_operations = n; }
        int get_nb_operations() { return (nb_operations); }
        void set_operations(string o[10]) {
            for (int i = 0; i < 10; i++) {
                do {
                operations[i] = o[i];
                }while ((operations[i].size())!=30);
            }
        }
        void set_next(produit_fini*p)
        {
            next=p;
        }
string* get_operations() { return (operations );}
produit_fini(int code,string design,int quant,string marque,int prix,int nb,string * tab):article(code,design,quant)
{
set_marque(marque);
set_prix_revient(prix);
set_nb_operations(nb);
set_operations(tab);
next=NULL;
}
int read_data()
{ 
  int cod,quant;
  string design;
  cout<<"Code:"<<endl;
   cin>>cod;
   if (cod==-1)
   return(0);
   this->set_code(cod);
   cout<<"designation:"<<endl;
   cin>>design;
   this->set_designation(design);
   cout<<"quantité:"<<endl;
   cin>>quant;
   this->set_stock(quant);
   cout<<"marque"<<endl;
   cin>>marque;
   cout<<"prix"<<endl;
   cin>>prix;
   cout<<"le nombre d'operations"<<endl;
   cin>>nb_operations;
   cout<<"Les 10 operations necessaires a la fabrication:"<<endl;
    for (int i = 0; i < 10; i++) {
                cin>>operations[i];
            }
  
   return(1);
}
produit_fini* get_next()
{
    return(next);
}

friend class ListeProduitFini;
};

class ListeProduitFini {
    private:
        produit_fini* first;
    public:
        ListeProduitFini() {
           first=NULL;
        }
        void add_first(produit_fini* p) {
            p->set_next(first);
            first=p;
        }
    produit_fini * get_first()
       {
        return(first);
       }
void create()
{
produit_fini* p=new produit_fini;
while( p->read_data())
add_first(p);
}
void view_list()
{
    produit_fini*p=first; 
    while (p)
    {
        cout<<p->get_code()<<endl;
        p=p->next;
    }
}
 void operator +=(ListeProduitFini l)
 {
    produit_fini* p;
    produit_fini* n;
    p=l.get_first();
    n=p;
    int i=0;
    while(p)
    {   n=n->next;
        this->add_first(p);
        i++;
        p=n;
    }
 }
 ~ListeProduitFini()
{
produit_fini *p;
produit_fini *save;
for(p=first;p;)
{
save=p;
p=p->next;
save=NULL;
delete save;}
}
};


int main()
{
    string tab[10]={"1","2","2","E","Z","E","E","U","E","E"};
    produit_fini a(100,"ara",12,"1GG",12,12,tab);
    produit_fini b(200,"ara",12,"1GG",12,12,tab);
    produit_fini c(300,"ara",12,"1GG",12,12,tab);

    ListeProduitFini p;
    ListeProduitFini l;
    p.add_first(&a);
    cout<<"before:"<<endl;
    l.add_first(&b);
    l.add_first(&c);
    p.view_liste();
    p+=l;
    cout<<"after:"<<endl;
    p.view_liste();
    return(0);
}