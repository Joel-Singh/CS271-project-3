test_hashtable_example: test_hashtable_example.cpp
	g++ -I$$HOME/local/include/cryptopp -L$$HOME/local/lib/ -o test_hashtable_example test_hashtable_example.cpp -lcryptopp
test:test_HashTable.o
	g++ -o	test test_HashTable.o

test_HashTable.o: test_HashTable.cpp Element.h Element.cpp
	g++ -c test_HashTable.cpp

clean:
	rm -f *.o
