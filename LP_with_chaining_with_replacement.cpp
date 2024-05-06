#include<bits/stdc++.h>
using namespace std;

struct rec{
    int key;
    int chain;
};

class Hashing
{
    public:
    rec hashtable[10];
    Hashing()
    {
        for(int i=0;i<10;i++)
        {
            hashtable[i].key=-1;
            hashtable[i].chain=-1;
        }
    }
    void insert(int r);
    void display();
    int endOfChain(int,int);
    int vacantPos(int);
    bool searching(int);
};

int Hashing::endOfChain(int tmp,int index)
{
    while(tmp!=-1)
    {
        index=tmp;
        tmp=hashtable[tmp].chain;         
    }
    return index;
}
int Hashing::vacantPos(int nxt)
{
    int gvn=nxt;
    while(hashtable[nxt].key!=-1)
    {
        nxt=(nxt+1)%10;
        if(nxt==gvn)
        {
            cout<<"Table full !"<<endl;
            return -1;
        }
    }
    return nxt;
}

void Hashing::insert(int r)
{
   static int elements=0;
    if(elements>10)
    {
        cout<<"Table FULL, element cannot be inserted !"<<endl;
        return;
    }
    elements++;
    int ind=r%10;
    if(hashtable[ind].key==-1)
    {
        hashtable[ind].key=r;
    }
    else if(hashtable[ind].key!=-1 && (hashtable[ind].key)%10==r%10)
    {
        int tmp=hashtable[ind].chain;
        int nxt=-1;                    
        int index=r%10;                
        int last_chain=endOfChain(tmp,index);
        nxt=vacantPos(last_chain);
        if(nxt!=-1)
        {
           hashtable[nxt].key=r;
           hashtable[last_chain].chain=nxt;
        }
        return;
    }
    else
    {
        int prev_index=ind;
        int prev_value=hashtable[ind].key;     //storing previous value of key and chain
        int prev_chain=hashtable[ind].chain;
        int strt=prev_value%10;
        while(hashtable[strt].chain!=prev_index && hashtable[strt].chain!=-1)
        {
            strt=hashtable[strt].chain;
        }

        hashtable[ind].key=r;                  //replacing with new key 
        hashtable[ind].chain=-1;
        ind=(ind+1)%10;
        int nxt=vacantPos(ind);
        if(nxt!=-1)
        {            
            hashtable[nxt].key=prev_value;     //inserting the previous element in an empty position if any
            hashtable[nxt].chain=prev_chain;
        }
        if(hashtable[strt].chain!=-1)hashtable[strt].chain=nxt; //changing the previous chain
    }
}
bool Hashing::searching(int r)
{
    int ind=r%10;
    while(hashtable[ind].key!=-1 && (hashtable[ind].key)%10!=r%10)
    {
        ind=(ind+1)%10;
        if(hashtable[ind].key==r)return true;
        if(ind==r%10) return false;
    }
    if(hashtable[ind].key==-1)return false;
    else
    {
        int fd;
        while(hashtable[ind].chain!=-1)
        {
           if(hashtable[ind].key==r)return true;
           ind=hashtable[ind].chain;
        }
        if(hashtable[ind].key==r)return true;
    }
    return false;
}

void Hashing::display()
{
    for(int i=0;i<10;i++)
    {
        cout<<"Index :"<<i<<" "<<"Roll No :"<<hashtable[i].key<<" "<<"Chain :"<<hashtable[i].chain<<endl;
    }
}

int main()
{
    Hashing hs;
    hs.insert(131);
    hs.insert(13);
    hs.insert(14);
    hs.insert(31);
    hs.insert(51);
    hs.insert(16);
    hs.insert(71);
    hs.insert(33);
    hs.insert(22);
    hs.insert(12);
    hs.insert(77);
    hs.insert(44);

    hs.display();
       
}