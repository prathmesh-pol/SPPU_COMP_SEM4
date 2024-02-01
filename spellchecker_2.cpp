#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string word;
    string meaning;
    Node* next;

    public:
    Node(){
        word = ""; meaning = ""; next = NULL;
    }

    Node(string f,string s){
        this->word = f;
        this->meaning = s;
        next = NULL;
    }
};

class hashing : public Node{
    public:
    Node* record[10];
    
    hashing(){
        for(int i=0;i<10;i++){
            record[i] = NULL;
        }
    }

    int hashfunc(string s){
        int val = 0;
        for(int i=0;i<s.length();i++){
            val+=(s[i]-'a'+1);
        }

        return val;
    }

    void insert(string s,string t){
        int index = (hashfunc(s))%10;
        if(record[index] == NULL){
            record[index] = new Node(s,t);
        }else{
            Node* temp = record[index];
            record[index] = new Node(s,t);
            record[index]->next = temp;
        }
    }
    
    void search(string s){
        int index = hashfunc(s)%10;
        Node* temp = record[index];
        while(temp->word!=s and temp!=NULL){
            temp = temp->next;
        }

        if(temp!=NULL){
            cout<<"Word Found : " << s <<" Meaning is : "<<temp->meaning <<" ";
        }else{
            cout<<"Not Found ";
        }

        cout << endl;
    }

    void display(){
        cout << "Dictionary Contents are : " << endl;
        for(int i=0;i<10;i++){
            cout << "Index : "<<i+1<<endl;
            Node * temp = record[i];
            while(temp!=NULL){
                cout <<" "<<temp->word<<" "<<temp->meaning<<" ";
                temp=temp->next;
                cout<<endl;
            }
            cout<<endl;
        }
    }
};

int main(){
    hashing obj;
    
    ifstream infile("Text.txt");
    string word,meaning;

    while(infile >> word >> meaning){
        obj.insert(word,meaning);
    }

    obj.display();
}
