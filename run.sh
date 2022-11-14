# multi thread run c++ in one thread and rust in another thread
# run c++ and rust in one thread


# start thread
g++ -std=c++11 -o cpp prime.cpp & rustc prime.rs 

wait # wait for all threads to finish


# run c++ and rust in one thread if it exists
if [ -f "cpp" ]; then
    ./cpp & ./main
fi

wait

# remove files
rm cpp main
#if primelist and primes
if [ -f "prime_list.csv" ]; then
    mv prime_list.csv output
fi

if [ -f "primes.csv" ]; then
    mv primes.csv output
fi

