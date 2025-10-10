# CS271 Project 3
Members: Joel and Nana

## Project Structure

Aside from the obvious files, here is the purpose of each file:

`encryption.cpp`: contains the encrypt method wrapping the necessary calls to cryptopp to produce a hex string digest with SHA256. There is additionally a helper function to truncate a digest for integer keys.

`test_complexity_and_load.cpp`: Generates experimental data for the chosen (see `choose_hash_method.cpp`) hash function. The experimental data is used for argument in our analysis.

`choose_hash_method.cpp`: Using macro variables, it determines what hash function to compile into `HashTable`.

`test_hashtable_extended.cpp`: Contains extra tests not in the original example.

`test_hashtable.cpp`: The file all initial example tests are in and our own written tests are `#include`d in.

## Running Tests

```bash
make -B
./test_hashtable
```

## Running usecase example

To run the usecase instead of tests, set the if guard around the main
functions to zero in `test_hashtable.cpp` and the if guard in
`usecase.cpp` to 1. Then run, `make -B && ./test_hashtable` like you
would normally.

## Running Cormen's or Most Significant Bits Method

The method used for hashing in the hashtable is chosen based on defined macro
variables. To run Cormen's or Most Significant Bits Method as the hashtable's
hash function, simply uncomment the right define at the beginning of
`choose_hash_method.cpp`. If `USE_CORMEN` is defined, cormen will be used,
if `USE_MSBM` is defined, MSBP is used, and if `USE_K_MOD_M` is defined, the k
mod m method will be used. Be careful not to have two of the methods defined.

For instance, to obtain the experimental values for Cormen's multiplication
method `USE_CORMEN` was uncommented.
