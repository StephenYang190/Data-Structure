//
// Created by 97927 on 2019/12/22.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include "my_BrotherTree.h"
#include <string>
#include "function.h"

using namespace std;
//#define YTD

bool sysControl()//choices
{
    std::string str[9]{"1.Assign a people",
                       "2.Delete a people",
                       "3.Show a people's information",
                       "4.Change a people's information",
                       "5.Show a layer all people' information",
                       "6.Show all people",
                       "7.Two people's relationship",
                       "8.Show as borndate",
                       "Enter q to quit"};
    for(int i = 0;i < 9;i++)
    {
        cout<<str[i]<<endl;
    }
    return true;
}
//change choices
bool changeInformation(my_BrotherTree_plus &root_tree,std::string nm)
{
    std::string str[8]{"Which information do you want to change : ",
                       "1.name",
                       "2.borndate",
                       "3.address",
                       "4.mariage",
                       "5.alive",
                       "6.deathdate",
                       "Enter q to quit"};
    for(int i = 0;i < 8;i++)
    {
        cout<<str[i]<<endl;
    }
    int choise;
    cin>>choise;
    cin.ignore();
    //input error
    if(cin.fail())
    {
        cin.clear();
        return false;
    }

    switch (choise){
        case 1 :
        {
            string nm_new = getString("new name");
            root_tree.setNames(nm,nm_new);
        }
        break;
        case 2 :
        {
            std::string born = getString("borndate");
            root_tree.setBorn(nm,born);
        }
        break;
        case 3 :
        {
            std::string add = getString("address");
            root_tree.setAddress(nm,add);
        }
        break;
        case 4 :
        {
            cout<<"marriaged ?(1 for yes)"<<endl;
            int judge = getInt("answer");
            root_tree.setMar(nm,judge == 1);
        }
        break;
        case 5 :
        {
            cout<<"still alive ?(1 for yes)"<<endl;
            int judge = getInt("answer");
            root_tree.setLive(nm,judge == 1);
        }
        case 6 :
        {
            std::string death = getString("deathdate(q to quit)");
            if(death == "q")
                break;
            root_tree.setDeathdate(nm,death);
        }
        break;
    }

    return true;
}
//carry out the choices
bool carryOutControl(my_BrotherTree_plus &root_tree,int n)
{
    switch(n) {
        case 1 :
        {
            //get information of the people
            std::string name = getString();
            std::string born = getString("borndate");
            std::string add = getString("address");
            bool lv;
            bool mar;
            cout<<"still alive ?(1 for yes)"<<endl;
            int judge = getInt("answer");
            std::string death;
            if(judge != 1)
            {
                lv = false;
                death = getString("deathdate");
            } else{
                lv = true;
            }
            cout<<"marriaged ?(1 for yes)"<<endl;
            judge = getInt("answer");
            mar = judge == 1;
            std::string pa = getString("parent");
            my_BrotherTree_plus * p = new my_BrotherTree_plus(name,born,add,mar,lv,death);
            //assign to pa
            root_tree.assign(p,pa);
        }
        break;
        case 2 :
        {
            std::string name = getString();
            //delete a people
            root_tree.deletePeople(name);
        }
        break;
        case 3 :
        {
            std::string name = getString();
            //show a people all information
            root_tree.find(name);
        }
        break;
        case 4 :
        {
            std::string name = getString();
            //change information
            changeInformation(root_tree,name);
        }
        break;
        case 5 :
        {
            int layer = getInt("layer");
            //show nth layer all people
            root_tree.showTreeLayer(layer);
        }
        break;
        case 6 :
        {
            root_tree.showAll();
        }
        break;
        case 8 :
        {
            root_tree.showBron();
        }
            break;
        case 7 :
        {
            string nm_new1 = getString("name1");
            string nm_new2 = getString("name2");
            switch (root_tree.relationship(nm_new1,nm_new2)){
                case 1 :
                {
                    cout<<nm_new2<<" is "<<nm_new1<<" parent"<<endl;
                }
                    break;
                case 2 :
                {
                    cout<<nm_new1<<" is "<<nm_new2<<" parent"<<endl;
                }
                    break;
                case 3 :
                {
                    cout<<nm_new2<<" is "<<nm_new1<<" grandparent"<<endl;
                }
                    break;
                case 4 :
                {
                    cout<<nm_new1<<" is "<<nm_new2<<" grandparent"<<endl;
                }
                    break;
                case 5 :
                {
                    cout<<nm_new1<<" is "<<nm_new2<<" brother"<<endl;
                }
                break;
                default:{
                    cout<<"Do not have relationship."<<endl;
                }
            }
        }
    }
}
#ifndef YTD
int main()
{
    /*std::string fileName = getString("filename");
    fileName += ".txt";*/
    my_BrotherTree_plus root_tree("familyin.txt");
    while(1)
    {
        //clear screen
        system("clear");
        sysControl();
        int choise;
        cin>>choise;
        cin.ignore();
        //enter below the range
        if(cin.fail())
        {
            cin.clear();
            break;
        }
        carryOutControl(root_tree,choise);
        //system pause
        system("read -p 'Press Enter to continue...' var");
    }
    //out to file
    root_tree.outToFile();

    return 0;
}

#endif