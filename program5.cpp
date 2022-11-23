#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

using namespace std;

class MarvellousFile
{
  public:
    char Fname[30];
    int fd;
    char cChar;
    
    MarvellousFile(char * Name,char cValue)     // Constructor
    {
        cout<<"Inside constructor\n";
        strcpy(Fname,Name);
        cChar = cValue; 
        fd = open(Fname,O_RDWR);
    }
    
    ~MarvellousFile()   // Desructor
    {
        cout<<"Inside Destructor\n";
        close(fd);
    }


  int CountFrequency()
    {
        int iRet = 0, iCnt = 0, i = 0;
        char Buffer[10];
        lseek(fd,0,0);
        
        while((iRet = read(fd,Buffer,10)) != 0)
        {
            for(i = 0; i < iRet; i++)
            {
                if((Buffer[i]==cChar))
                {
                    iCnt++;
                }
            }
        }
        return iCnt;
    }



};

int main()
{
   char Name[30];
   char cValue;
   int iRet=0;
   
   cout<<"Enter name of file\n";
    cin>>Name;
    
   cout<<"Enter Charater \n";
   cin>>cValue; 
    MarvellousFile obj(Name,cValue);
  
    
    iRet = obj.CountFrequency();
    cout<<"Frequency of character is are : "<<iRet<<"\n";
    
  
    return 0;
}
