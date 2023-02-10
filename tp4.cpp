#include <iostream>
#include <string.h>
#include <map>
#include <fstream>
using namespace std;


void load_file(int len,int pos,map<string,string> &filesorter,char* s)
{    
   fstream fin;
   fin.open(s);
    string key,line;
    while(getline(fin,line))
    {
       key=line.substr(pos,len);
       filesorter.insert(make_pair(key,line));
    }
    fin.close();
}
void sort_file(map<string,string> filesorter,char* s)
{
   fstream fout;
   fout.open(s);
 
    for(const auto& elem : filesorter)
     {
       fout<<elem.second<<endl ;
     }
   
   fout.close();
}

void read_file(char* s)
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
   map<string ,string> filesorter;
   char* file_name=argv[1];
   int pos=atoi(argv[2]);
   int len=atoi(argv[3]);
   read_file(file_name);
   load_file(len ,pos,filesorter,file_name);
   sort_file(filesorter,file_name);
   read_file(file_name);
   return(0);
}