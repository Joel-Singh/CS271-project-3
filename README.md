# CS271 Project 3
Members: Joel and Nana

To run the usecase instead of tests, set the if guard to zero in
`test_hashtable.cpp` and the if guard in `usecase.cpp` to 1.


## Running Cormen's or Most Significant Bits Method

The method used for hashing in the hashtable is chosen based on defined macro
variables. To run Cormen's or Most Significant Bits Method as the hashtable's
hash functoin, simply uncomment the right define at the beginning of
`choose_hash_method.cpp`. If `USE_CORMEN` is defined, cormen will be used,
if `USE_MSBM` is defined, MSBP is used, and if `USE_K_MOD_M` is defined, the k
mod m method will be used. Be careful not to have two of the methods defined.

For instance, to obtain the experimental values for Cormen's multiplication
method `USE_CORMEN` was uncommented.
