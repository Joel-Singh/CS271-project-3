#include "HashTable.h"
#include "blake2.h"
#include "cryptlib.h"
#include "files.h"
#include "filters.h"
#include "hex.h"
#include <fstream>
#include <stdint.h>
#include <vector>

using namespace std;
using namespace CryptoPP;

template <typename T> bool login(HashTable<T> *ht, T username, string password);
template <typename T> HashTable<T> *create_table(string fname, int m);

string get_hash();
int string_to_int(string str);

#if 0

int main() {
    string username;
    string password;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter psw: ";
    cin >> password;

    HashTable<string> *ht = create_table<string>("logins.csv", 10);
    if (login(ht, username, password)) {
        cout << "Login succesful!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }
}

#endif

//=================================================
// create_table
// Creates a hashtable of username and passwords from the file `fname` with size
// `m`. Hashes the passwords before inserting it into the table.
//
// PARAMETERS:
//  fname: Name of the file to retrieve username and passwords from
//  m: The desired size of the the hashtable
//
// RETURN VALUE:
//  A pointer to the created hashtable
//=================================================
template <typename T> HashTable<T> *create_table(string fname, int m) {
  // Forgot how to read a file, followed this:
  // https://stackoverflow.com/a/51572325
  ifstream file(fname);
  HashTable<T> *hashtable = new HashTable<T>(m);

  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      int comma = line.find(",");
      string username = line.substr(0, comma);
      string password =
          line.substr(comma + 2); // + 2 to get rid of the comma and space

      hashtable->insert(username, encrypt(password));
    }

    file.close();
  } else {
    throw runtime_error("Could not open `" + fname + "`");
  }

  return hashtable;
}

template <typename T>
bool login(HashTable<T> *ht, T username, string password) {
  return ht->member(username, password);
}
