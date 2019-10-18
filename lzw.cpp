#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int main(){
fstream fio,com;
map <string,int> code;
map <string,int>::iterator itr;
char ch;
string t="";
int i=1;
fio.open("Akhil.txt",fstream::in);
com.open("compress.txt",fstream::out);
while(t!="$"){
    fio.get(ch);
       // cout<<ch;
        t=ch;
        while(t!="Z" && t!="$"){
                //cout<<t;
                itr=code.find(t);
                if (itr== code.end()){
             code.insert(pair<string,int>(t,i));
             com<<t;
            i++;}
        fio.get(ch);
        t=ch;
        }
         com<<t;
        fio.get(ch);
        t=ch;
        string sc;
         sc=t;
        fio.get(ch);
        t=ch;
        while (t!="$")
        {
        //cout<<sc;
            itr = code.find(sc+t);
            if (itr!= code.end()){
                sc=sc+t;
            }
            else
            {itr = code.find(sc);
                com<<itr->second;
                 code.insert(pair<string,int>(sc+t,i));
                 i++;
                 sc=t;
           }
            fio.get(ch);
            t=ch;
        }
        itr = code.find(sc);
        com<<itr->second;
    }
cout<<"\n";
    for (itr = code.begin(); itr != code.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
     com<<"$";
    com.close();
    fio.close();
        return 0;
}
