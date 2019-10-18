#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int main(){
fstream fio;
map <int,string> code;
map <int,string>::iterator itr;
char ch;
string t="";
int i=1,num;
fio.open("compress.txt",fstream::in);
while(t!="$"){
    fio.get(ch);
       // cout<<ch;
       t=ch;

        while(t!="Z" && t!="$"){
                //cout<<t;
             code.insert(pair<int,string>(i,t));
            i++;
        fio.get(ch);
        t=ch;
        }

        fio.get(ch);
        t=ch;
        num=ch-48;
        string sc;
         sc="";
        while (t!="$")
        {
         itr=code.find(num);
         cout<<itr->second;
         if(sc!=""){
        code.insert(pair<int,string>(i,sc+itr->second[0]));
        i++;
         }
        fio.get(ch);
        t=ch;
         num=ch-48;
         sc=itr->second;
        }

    }
cout<<"\n";
    for (itr = code.begin(); itr != code.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    fio.close();
return 0;}
