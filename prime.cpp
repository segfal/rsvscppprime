#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <chrono>

using namespace std;
using namespace std::chrono;



int primes(int n)
{
    int i, j;
    int count = 0;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            count++;
        }
    }
    return count;
}


vector<int> prime_list(int n)
{
    int i,j;
    vector<int> prime_list;
    //write primes to csv file
    fstream file;
    file.open("output/prime_list.csv", ios::out);
    
    for(i = 2; i <= n; i++)
    {
        prime_list.push_back(i);
        //convert i to string
        stringstream ss;
        ss << i;
        string str = ss.str();
        file << str << ",";
    }
    file.close();
    return prime_list;
}


int main()
{
    int n;

    n = 10000;
    auto start = high_resolution_clock::now();
    vector<int> primesnum = prime_list(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " seconds" << endl;
    return 0;

}
