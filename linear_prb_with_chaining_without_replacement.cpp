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
    while(hashtable[nxt].key!=-1)
    {
        nxt=(nxt+1)%10;
    }
    return nxt;
}

void Hashing::insert(int r)
{
   static int elements=0;
   elements++;
    if(elements>10)
    {
        cout<<"Table FULL, element cannot be inserted !"<<endl;
        elements--;
        return;
    }
    
    int ind=r%10;
    if(hashtable[ind].key==-1)
    {
        hashtable[ind].key=r;
    }
    else if(hashtable[ind].key!=-1 && (hashtable[ind].key)%10==ind)
    {
        int tmp=hashtable[ind].chain;
        int nxt=-1;                    //temporary variable 
        int index=r%10;                // stores the last index where chain of the same hash value ends
        while(tmp!=-1)
        {
            index=tmp;
            tmp=hashtable[tmp].chain;         
        }
        nxt=index;
        // nxt=endOfChain(tmp,index);
        while(hashtable[nxt].key!=-1)
        {
            nxt=(nxt+1)%10;
        }
        hashtable[nxt].key=r;
        hashtable[index].chain=nxt;
    }
    else
    {
        int st=ind;
        while(hashtable[st].key!=-1 && hashtable[st].key%10!=r%10)
        {
            st=(st+1)%10;
        }
        if(hashtable[st].key==-1)
        {
            hashtable[st].key=r;
        }
        else if(hashtable[st].key%10==r%10)
        {
            int index=st;
            int tmp=hashtable[st].chain;
            while(tmp!=-1)
            {
                index=tmp;
                tmp=hashtable[tmp].chain;
                
            }
            int nxt=index;
            while(hashtable[nxt].key!=-1)
            {
                nxt=(nxt+1)%10;
            }
            hashtable[nxt].key=r;
            hashtable[index].chain=nxt;
        }
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
    hs.insert(44);
    hs.display();
    cout<<hs.searching(12)<<endl;    //element not present at correct hash index 
    cout<<hs.searching(33)<<endl;    //element present in chain at correct hash index
    cout<<hs.searching(32)<<endl;    //element not in chain
    cout<<hs.searching(16)<<endl;    //element at correct hash index
}