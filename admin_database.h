#include<iostream>
#include<fstream>
#include<vector>
#include"admin.h"
using namespace std;

class admin_database
{
    public:
        void upload(admin &ad)
        {
            
            ofstream ofile;
            ofile.open("admin",ios::out|ios::app);
            ofile.write((char*)&ad,sizeof(ad));
            ofile.close();
        }
        vector<admin> download()
        {
            vector<admin> data;
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                data.push_back(ad);
            }
            ifile.close();
            return data;
        }
        bool extract(vector<admin> &info)
        {
            if(info.size()==0){cout<<"No data"<<endl;}
            for(int i=0;i<info.size();i++)
            {
                info[i].display();
            }
            cout<<"Total Data : "<<info.size()<<endl;
            cout<<"Return to Menu (y/n) : ";
            char choice;
            cin>>choice;
            if(choice=='y'||choice=='Y')
                return true;
            else
                return false;
        }
        vector<admin> searchbyAdminID(char element[])
        {
            vector<admin> searchRes;
            cout<<"Key :"<<element<<endl; 
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if(strcmp(ad.get_admin_id(),element)==0)
                {
                    searchRes.push_back(ad);
                }
            }
            ifile.close();
            return searchRes;
        }

        vector<admin> searchbyName(char *Name)
        {
            vector<admin> searchRes;
            cout<<"Key : "<<Name<<endl;
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if(strcmp(ad.get_name(),Name)==0)
                {
                    searchRes.push_back(ad);
                }
            }
            ifile.close();
            return searchRes;
            
        }
        bool login(char* uname, char* pass)
        {
            cout<<uname<<" "<<pass<<endl;
            admin ad;
            ifstream ifile;
            ifile.open("admin",ios::in);
            while(ifile.read((char*)&ad,sizeof(ad)))
            {
                if((strcmp(ad.get_username(),uname)==0) && (strcmp(ad.get_password(),pass)==0))
                {
                    return true;
                }
            }
            ifile.close();
            return false;
        }
        bool masterLogin()
        {
            char uname[100], pass[100];
            cout<<"Username : ";
            cin.ignore();
            cin.getline(uname,100);
            cout<<"Password : ";
            cin.getline(pass,100);
            char user[100], password[100];
            strcpy(user, "MASTER@ADMIN");
            strcpy(password,"ADMIN123");

            if(strcmp(uname,user)==0 && strcmp(pass, password)==0)
            {
                cout<<"WELCOME MASTER ADMIN "<<endl<<endl;
                return true;
            }
            cout<<"This is Restricted Access!!"<<endl;
            return false;
        }
};
