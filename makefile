test_hashtable_example: test_hashtable_example.cpp
	g++ -I$HOME/local/include -L$HOME/local/lib -o test_hashtable_example test_hashtable_example.cpp

test_hastable_example.o: test_hastable_example.cpp Element.h Element.cpp
	g++ -c test_hashtable_example.cpp

clean:
	rm -f *.o
