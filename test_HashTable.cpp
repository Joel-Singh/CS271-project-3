/*
====================================================
Project 3: Smushed Universes (Hash Table Implementaion)
Written by: Nana K. Amo-Mensah and Joel Singh
Date Updated: 10.07.2025
Description: HashTable Tester

Cases
1. Testing with different data types (bool, int, string, char)
2. How do the methods handle non-numeric keys? -- error message
3. What would happen if we try to create a HashTable with 0/neg. size?
=====================================================
*/

#include <iostream>
#include <string>
#include "Element.h"
#include "HashTable.h"
//#include "usecase.cpp"
using namespace std;

//===============================================
//  Global variables for testing HashTable Class
//===============================================
HashTable<int> htInt(5);
HashTable<char> htChar(3);
HashTable<string> htString(4);
HashTable<bool> htBool(2);

void test_get_key()
{
    try
    {
        Element<int> elemInt;
        Element<bool> elemBool;
        Element<string> elemString;
        Element<char> elemChar;

        if (elemInt.get_key() != -1)
        {
            cout << "Expected key = -1 but got: " << elemInt.get_key()<<" Try again!"<<endl;
        } 
        if (elemBool.get_key() != -1){
            cout << "Expected key = -1 but got: " << elemBool.get_key()<<" Oh no!"<<endl;
        } 
        if (elemChar.get_key() != -1){
            cout << "Expected key = -1 but got: " << elemChar.get_key()<<" Too bad!"<<endl;
        }
        if (elemString.get_key() != -1){
            cout << "Expected key = -1 but got: " << elemString.get_key()<<" So sad!"<<endl;
        }

        Element<int> elemInt1(86, 5);
        Element<bool> elemBool1(0, 19);
        Element<string> elemString1("dataByte", 732);
        Element<char> elemChar1('a', 212);

        if (elemInt1.get_key() != 5)
        {
            cout << "Expected key = 5 but got: " << elemInt1.get_key()<<" Try again!"<<endl;
        } 
        if (elemBool1.get_key() != 19){
            cout << "Expected key = 19 but got: " << elemBool1.get_key()<<" Oh no!"<<endl;
        } 
        if (elemChar1.get_key() != 212){
            cout << "Expected key = 212 but got: " << elemChar1.get_key()<<" Too bad!"<<endl;
        } 
        if (elemString1.get_key() != 732){
            cout << "Expected key = 732 but got: " << elemString1.get_key()<<" So sad!"<<endl;
        }
        
    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data(){
     try
    {
        Element<int> elemInt;
        Element<bool> elemBool;
        Element<string> elemString;
        Element<char> elemChar;

        if (elemInt.get_data() != 0)
        {
            cout << "Expected data = 0 but got: " << elemInt.get_key()<<" Try again!"<<endl;
        } 
        if (elemBool.get_data() != 0){
            cout << "Expected data = 0/False but got: " << elemBool.get_key()<<" Oh no!"<<endl;
        } 
        if (elemChar.get_data() != '\0'){
            cout << "Expected data = empty char but got: " << elemChar.get_key()<<" Too bad!"<<endl;
        }
        if (elemString.get_data() != ""){
            cout << "Expected data = empty string but got: " << elemString.get_key()<<" So sad!"<<endl;
        }

        Element<int> elemInt1(86, 5);
        Element<bool> elemBool1(0, 19);
        Element<string> elemString1("dataByte", 732);
        Element<char> elemChar1('a', 212);

        if (elemInt1.get_data() != 86)
        {
            cout << "Expected data = 86 but got: " << elemInt1.get_data()<<" Try again!"<<endl;
        } 
        if (elemBool1.get_data() != 0){
            cout << "Expected data = 0 but got: " << elemBool1.get_data()<<" Oh no!"<<endl;
        } 
        if (elemChar1.get_data() != 'a'){
            cout << "Expected data = a but got: " << elemChar1.get_data()<<" Too bad!"<<endl;
        } 
        if (elemString1.get_data() != "dataByte"){
            cout << "Expected data = dataByte but got: " << elemString1.get_data()<<" So sad!"<<endl;
        }
        
    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_insert(){
    try{
        HashTable<int> htInt(-20); 
    }
    catch(exception &e){
        cerr << "Correctly handles cases where size < 0"<<e.what() << endl;
    }

    try{
        htInt.insert(89, 201);
        htInt.insert(91982, 91);
        htInt.insert(-12120, 212);
        htInt.insert(812, 0);
        if(htInt.to_string() !="0: (812,0) \n1: (91982,91) (89,201) \n2: (-12120,212) \n3: \n4: \n"){
            cout << "Expected result from insertion: \n0: (812,0) \n1: (91982,91) (89,201)  \n2: (-12120,212) \n3: \n4: \n"<<endl;
            cout << "But got: \n" << htInt.to_string()<<endl;
        }

        htChar.insert('a', 192);
        htChar.insert('b', 2212);
        htChar.insert('x', 9239);
        if(htChar.to_string() !="0: (a,192) \n1: (b,2212) \n2: (x,9239) \n"){
            cout << "Expected result from insertion: \n0: (a, 192) \n1: (b, 2212) \n2: (x, 9239) \n"<<endl;
            cout << "But got: \n" << htChar.to_string()<<endl;
        }

        htString.insert("Hello World", 0);
        htString.insert("Nice day", 1);
        htString.insert("Bounty Hunter for life", 2);
        htString.insert("To inifinity and beyond", 3);
        if(htString.to_string() !="0: (Hello World,0) \n1: (Nice day,1) \n2: (Bounty Hunter for life,2) \n3: (To inifinity and beyond,3) \n"){
            cout << "Expected result from insertion: \n0: (Hello World,0) \n1: (Nice day,1) \n2: (Bounty Hunter for life,2) \n3: (To inifinity and beyond,3) \n"<<endl;
            cout << "But got: \n" << htString.to_string()<<endl;
        }

        htBool.insert(981, 0);
        htBool.insert(0, 29);
        if(htBool.to_string() !="0: (1,0) \n1: (0,29) \n"){
            cout << "Expected result from insertion: \n0: (1, 0) \n1: (0, 29) \n"<<endl;
            cout << "But got: \n" << htBool.to_string()<<endl;
        }

    }catch(exception &e){
        cerr << "Error inserting into the HashTable"<<endl;
    }
    
}

void test_remove(){
    try{
        htInt.remove(-12120, 212);
        if(htInt.to_string() !="0: (812,0) \n1: (91982,91) (89,201) \n2: \n3: \n4: \n"){
            cout << "Expected result from insertion: \n0: (812,0) \n1: (91982,91) (89,201)  \n2: \n3: \n4: \n"<<endl;
            cout << "But got: \n" << htInt.to_string()<<endl;
        }

        htChar.remove('x', 9239);
        if(htChar.to_string() !="0: (a,192) \n1: (b,2212) \n2: \n"){
            cout << "Expected result from insertion: \n0: (a, 192) \n1: (b, 2212) \n2: \n"<<endl;
            cout << "But got: \n" << htChar.to_string()<<endl;
        }

        htString.remove("Bounty Hunter for life", 2);
        if(htString.to_string() !="0: (Hello World,0) \n1: (Nice day,1) \n2: \n3: (To inifinity and beyond,3) \n"){
            cout << "Expected result from insertion: \n0: (Hello World,0) \n1: (Nice day,1) \n2: \n3: (To inifinity and beyond,3) \n"<<endl;
            cout << "But got: \n" << htString.to_string()<<endl;
        }

        htBool.remove(0, 29);
         if(htBool.to_string() !="0: (1,0) \n1: \n"){
            cout << "Expected result from insertion: \n0: (1, 0) \n1: \n"<<endl;
            cout << "But got: \n" << htBool.to_string()<<endl;
        }
    }
    catch (exception &e){
        cerr << "Error removing from HashTable"<<endl;
    }
}

void test_member(){
    if(htInt.member(89, 201) != true){
        cout << "Expected: 1 but got: "<<htInt.member(89, 201)<<endl;
    }
    if(htChar.member('6', 7) != false){
        cout << "Expected: 0 but got: " << htChar.member('6', 7)<<endl;
    }
    if(htString.member("Fly like a bird", 91) != false){
        cout << "Expected: 0 but got: " << htString.member("Fly like a bird", 91)<<endl;
    }
    if(htBool.member(981, 0) != true){
        cout << "Expected: 1 but got:" << htBool.member(981, 0)<<endl;
    }
}

int main (void ){
    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();

    /*
    test_member();
    test_login();
    */

    cout << "Cases Passed!";

    return 0;
}