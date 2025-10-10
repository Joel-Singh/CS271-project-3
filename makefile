test_hashtable: test_hashtable.cpp
	g++ -I$$HOME/local/include/cryptopp -L$$HOME/local/lib/ -o test_hashtable test_hashtable.cpp -lcryptopp

clean:
	rm -f *.o
