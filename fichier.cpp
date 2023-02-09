#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>

class fichier
{   
    char* Name;
    char* mode;
    FILE* fp;
    int size_len;

 public:

fichier()
{  
    Name=new char[1];
    strcpy(Name,"");
     mode=new char[1];
    strcpy(mode,"");
    fp=NULL;
  
}
fichier(const char* Name,const char* mode ,int size)
{
    this->Name=new char[strlen(Name)+1];
    this->mode=new char[strlen(mode)+1];
    strcpy(this->Name,Name);
    strcpy(this->mode,mode);
    size_len=size;
    fp=fopen(Name,mode);
    if (!fp) 
    {
      cout<<"Erreur" ;
      exit(0); 
    }
}
void set_Name(const char*Name)
{ 
 rename(this->Name,Name);
 free(this->Name);
 this->Name=new char(strlen(Name)+1);
 strcpy(this->Name,Name);
}
FILE* get_fp()
{
  return(fp);
}
char* get_Name()
{
  return(Name);
}
void set_mode(const char*mode)
{
  free(this->mode);
  this->mode=new char[strlen(mode)+1];
  strcpy(this->mode,mode);
}
char* get_mode()
{
  return(mode);
}
void set_size_len(int size)
{
 size_len=size;
}
int get_size_len()
{
  return(size_len);
}

void write(const char* ch)
{  
    if (strcmp(mode,"w") && strcmp(mode,"w+")) {cout<<"ERROR:Le fichier doit entre ouvert en mode w ou w+\n";}
    else 
    { 
      fprintf(fp,"%-*.*s",size_len,size_len,ch);
    }
}
 void read()
 {
     char ch;
        if (!strcmp(mode,"w") || (!strcmp(mode,"a"))){ cout <<"Error:Le fichier doit etre ouvert en mode r ou r+ ou w+ ou a+\n";}
        else 
        {      
            while( ( ch = fgetc(fp) ) != EOF )
           {
              printf("%c",ch);
           }
        }
 }

void afficher()
{ 
    char ch;
        if (!strcmp(mode,"w") || (!strcmp(mode,"a"))){ cout <<"Error:Le fichier doit etre ouvert en mode r ou r+ ou w+ ou a+\n";}
        else 
        {   
            rewind(fp);
             while( ( ch = fgetc(fp) ) != EOF )
           {
              printf("%c",ch);
           }
        }
} 

fichier operator+(fichier a)
{ 
  int size=max(a.get_size_len(),this->size_len);
  char buffer[size+1];
  char * name=new char[strlen(a.get_Name())+strlen(this->Name)+1];
  strcpy(name,this->Name);
  strcat(name,a.get_Name());
  fichier s(name,"w+",size); 
  rewind(a.get_fp());
  rewind(this->fp);
  rewind(s.get_fp());
  while (fgets(buffer,size+1,this->fp))
            {
              s.write(buffer);
            }
  while (fgets(buffer,size+1,a.get_fp()))
            {
              s.write(buffer);
            }
  return(s);
}

void creer()
{ 
    char s[size_len+1];
    rewind(fp);
    while(fgets(s,size_len+1,stdin))
    { 
      this->write(s);
    }
}
  ~ fichier()
{ 
  fclose(fp);
  delete Name;
  delete mode;
}

};

int main()
{
     fichier a("first","w+",15);
     fichier b("second","w+",15);
     fichier c;
     a.write("hello");
     b.write("world");
     fichier c=a+b;
     c.afficher();
  return(0);
}

