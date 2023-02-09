#include <iostream>
#include <string>
#include <typeinfo>
using namespace std ;


class article
{ 
    public:
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
    public:
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
                operations[i] = o[i];
            }
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

operator string (void)
{
    return(marque);
}
int read_data()
{
 cout<<"Code";
   cin>>code;
   if (code==-1)
   return(0);
   cout<<"designation";
   cin>>designation;
   cout<<"quantité";
   cin>>quantity;
   cout<<"marque";
   cin>>marque;
   cout<<"prix";
   cin>>prix;
   cout<<"le nombre d'operations";
   cin>>nb_operations;
   cout<<"Les 10 operations necessaires a la fabrication:";
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
            p->next=first;
            first=p;
        }
void creer()
{
produit_fini p;
while( p.read_data())
add_first(&p);
}
produit_fini * get_first()
{
return(first);
}
void operator +=(ListeProduitFini l)
{
    produit_fini* p=new produit_fini;
    p=l.get_first();
     while (p)
    {
        this->add_first(p);
        p=p->next;
    }
    delete p;
    p=NULL;
}

/*~ListeProduitFini()
{
produit_fini *p;
produit_fini *save;
for(p=first;p;)
{
save=p;
p=p->next;
delete save;
save=NULL;
}
}*/
void view_liste(produit_fini*);
};
void ListeProduitFini:: view_liste(produit_fini*first)
{
if (first)
{
cout<<first->get_code();
cout<<"haha";
view_liste(first->next);
}
}


int main()
{
    string tab[10]={"1","2","2","E","Z","E","E","U","E","E"};
    produit_fini a(100,"ara",12,"1GG",12,12,tab);
    produit_fini b(200,"ara",12,"1GG",12,12,tab);
    ListeProduitFini l;
    l.add_first(&a);
    ListeProduitFini p;
    p.add_first(&b);
    p+=l;
    p.view_liste(p.get_first());
    return(0);
}