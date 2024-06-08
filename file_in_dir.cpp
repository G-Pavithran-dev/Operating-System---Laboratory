#include<iostream>
#include<dirent.h>
using namespace std;

bool fileexists(char* directory, char* filename)
{
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL)
    {
        cout << "directory not found\n";
        return false;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (string(entry->d_name) == filename)
        {
            closedir(dp);
            return true;
        }
    }

    closedir(dp);
    return false;
}

int main()
{
    char directory[100], filename[100];
    
    cout << "Enter directory: ";
    cin.getline(directory, 100);
    cout << "Enter filename: ";
    cin.getline(filename, 100);

    if(fileexists(directory, filename))
    {
        cout<<"The file exists in directory.";
    }
    else{
        cout<<"The file does not exists in directory";
    }
}