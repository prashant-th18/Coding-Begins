/**Fermat's little theorem states that if p is a prime number,
 *  then for any integer a, the number a^p − a is an integer multiple of p.
 *  In the notation of modular arithmetic, this is expressed as ->
 *  a ^ p ≡ a ( mod p ) .
 *
 * For example, if a = 2 and p = 7, then 2^7 = 128, and 128 − 2 = 126 = 7 × 18 is an integer multiple of 7.
 *
 * If a is not divisible by p, Fermat's little theorem is equivalent to the statement that
 *  a^(p − 1) − 1 is an integer multiple of p, or in symbols:
 *
 *  a ^ (p − 1) ≡ 1 ( mod p ) .
 *
 *  For example, if a = 2 and p = 7, then 2^6 = 64, and 64 − 1 = 63 = 7 × 9 is thus a multiple of 7.
 * 
 * For proof -> https://en.wikipedia.org/wiki/Proofs_of_Fermat%27s_little_theorem ( Proof as a particular case of Euler's theorem )
 */

/** Another interesting thing!
 * if u, x, y, and z are integers, if u and z are relatively prime, and if
 * 
 * (u * x) % z == (u * y) % z
 * then --> 
 * 
 * x % z == y % z
 */ 