#include<bits/stdc++.h>

using namespace std;

class Data{
    public:
    int roll;
    
    int chain;
    
    Data(){
        roll = 0;
        chain = -1;
    }


};

class Student{

public:
    Data Stud[10];
    int chn[10];


    void insert(int n){
      int x = n%10;

      if(Stud[x].roll==0){
        Stud[x].roll = n;

        
}
      else{
        int pos = 0;
        for (int i = x; i < n; i++)
        {
            if(Stud[i].roll==0){
                Stud[i].roll = n;
                pos = i;
                break;


            }
        }

        Stud[x].chain = pos;
        chn[x] = pos;
        
      }


    }


    void search(int n){
        int x = n%10;

        int f = 0;

        if(Stud[x].roll==n){
            cout<<"The data is found !"<<'\n';

            
            cout<<"The roll no is "<<Stud[x].roll<<"\n";
            return;

        }
        else{
            int i = 0;
            while(i<n){
                if(Stud[i].roll==n){
                    cout<<"Data is found !! \n";

                   
                    cout<<"Roll is\n";
                    cout<<Stud[i].roll<<'\n';

                    return;

                }
                else if(Stud[i].roll==-1){
                    cout<<"Inititally present but deleted\n";
                }
                i++;
            }
        }

        cout<<"Data is not present\n";

        return;
    }


    void display(int n){
      for(int i = 0;i<n;i++){
        if(Stud[i].roll==0){
            continue;
        }
        else{
            
            cout<<"Roll no of the Student is: "<<Stud[i].roll<<'\n';
        }

      }
    
    }
    void del(int n){
        int x = n%10;
     int i = 0;
        while(i<n){
        if(Stud[i].roll==n){
           
            Stud[i].roll = -1;
            cout<<"data deleted succesfully\n";
            return;

        }
        
        i++;
        }
   cout<<"Data is not present \n";
   return;


        
    }

};

int main(){

    int ch;
    cout<<"Enter choice \n";
    cin>>ch;

     int n;

    cout<<"Enter the number of student  \n";
    cin>>n;

  Student s;
    cin>>ch;


    while(ch<=4){
        cout<<"Enter choice \n";
        cin>>ch;
        if(ch==1){

           

  
    cout<<"Add data "<<"\n";

 for (int i = 0;i<n;i++){
    int rl;
    string nm;


    cout<<"enter roll \n";
    cin>>rl;
    

    s.insert(rl);





    
 }
}


       else if(ch==2) {
        cout<<"enter number to be searched \n";
 int ser;
 cin>>ser;
 s.search(ser);


       }

       else if(ch==3){
  cout<<"If want to delete element \n";

cout<<"Enter roll to deleted ";
int r;
cin>>r;

s.del(r);

       }
       else if(ch==4){
        cout<<"If want to display element \n";
        s.display(n);

       }

 




 






}}