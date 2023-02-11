#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <fstream>
using namespace std;


void load_file_into_map(int len,int pos,map<string,string>& filesorter,const char* &s)
{    
   fstream fin;
   try{
   fin.open(s);
   if (!fin)
   {
    throw ("Erreur: Fichier introuvable ou erronée !");
   }
    string key,line;
    while(getline(fin,line))
    {  
        if ((pos <0)||(len<0)||(pos>=line.size())||(line.size()-pos-1<len)) 
        {   
            throw ("Erreur:La longueur et/ou La position sont incompatibles avec votre fichier !");
        }
       key=line.substr(pos,len);
       filesorter.insert(make_pair(key,line));
       fin.close();
    }
   }
   catch(const char* erreur)
   {
    cout<<erreur<<endl;
    fin.close();
    exit(0);
   }
}
void load_map_into_file(map<string,string>& filesorter,const char* &s)
{
   fstream fout;
   fout.open(s);
 
    for(const auto& elem : filesorter)
     {
       fout<<elem.second<<endl ;
     }
   
   fout.close();
}

void read_file(const char*&s)
{   
   string line;
   fstream fin;
   fin.open(s);
   while (getline(fin,line))
   {
    cout<<line<<endl;
   }
   fin.close();
}


int main(int argc,char** argv)
{   
  if (argc<4)
  {
    cout<< "Ce programme accepte 3 arguments: (1) le nom du fichier que vous voulez trier"<<endl;
    cout <<"(2) la positon du clé de tri par rapport au déut du texte et (3) la longueur du clé ." <<endl;
    return 1;
  }
   map<string ,string> filesorter;
   const char* file_name=argv[1];
   int pos=stoi(argv[2]);
   int len=stoi(argv[3]);
   load_file_into_map(len ,pos,filesorter,file_name);
   cout<<"before:"<<endl;
   read_file(file_name);
   load_map_into_file (filesorter,file_name);
   cout<<"after:"<<endl;
   read_file(file_name);
   return(0);
}