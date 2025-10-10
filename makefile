test_hashtable_example: test_hashtable_example.cpp
	g++ -I$$HOME/local/include/cryptopp -L$$HOME/local/lib/ -o test_hashtable_example test_hashtable_example.cpp -lcryptopp

clean:
	rm -f *.o
