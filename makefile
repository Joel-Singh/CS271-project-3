test_hashtable_example: test_hashtable_example.cpp
	g++ -I$HOME/local/include -L$HOME/local/lib -o crypto test_hashtable_example.cpp -lcryptopp
