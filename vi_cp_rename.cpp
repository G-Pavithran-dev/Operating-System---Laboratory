#include<iostream>
#include<fstream>
using namespace std;

void vi(string src)
{
    ofstream file(src);
    string line;

    while(getline(cin, line))
    {
        if(line == ":wq"){
            break;
        }
        file<<line<<endl;
    }
}

void cp(string src, string dest){

    ifstream file_src(src);
    ofstream file_dest(dest);
    file_dest << file_src.rdbuf();
}

void cat(string src){
    ifstream file(src);
    string line;

    while(getline(file,line))
    {
        cout<<line<<endl;
    }
}

int main() {

    int d;
    while(true) {
        cin>>d;
        if(d == 5)
            break;
        
        else if(d == 1)
            vi("pavithran.txt");

        else if(d == 2)
            cp("pavithran.txt","copy.txt");

        else if(d == 3)
            cat("pavithran.txt");
        
        else if(d == 4)
            rename("pavithran.txt", "pavi.txt");
    }
}
