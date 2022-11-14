use std::vec::Vec;
use std::io::Write;
use std::fs::File;
// record the time
fn prime(n: u32) -> Vec<u32> {
    let mut primes: Vec<u32> = Vec::new();
    let mut i = 2;
    while primes.len() < n as usize {
        let mut is_prime = true;
        for p in &primes {
            if i % p == 0 {
                is_prime = false;
                break;
            }
        }
        if is_prime {
            primes.push(i);
        }
        i += 1;
    }
    primes
}
//write the result to a file
fn main() {
    // record the time
    let start = std::time::Instant::now();
    let primes = prime(10000);
    let mut file = File::create("output/primes.txt").unwrap();
    for p in &primes {
        file.write_all(format!("{} ", p).as_bytes()).unwrap();
    }
    println!("Time elapsed: {:?}", start.elapsed());

}



