
> 2.2.8 LAB  Some actual evaluations – finding the value of π

# 🎓 Lessons Learned

- Changing the exponent variable from `short` to `int` does not increase the storage available for `result`. On Windows/MSVC, even in a 64-bit build, `unsigned long` is typically 4 bytes (32 bits), with a maximum value of `4,294,967,295`. Therefore, \(2^{32}\) (`4,294,967,296`) overflows and wraps to `0`. Confirm with `sizeof(unsigned long)` and `numeric_limits<unsigned long>::max()`; use `unsigned long long` for values through \(2^{63}\).

- On Windows, use `unsigned long long` rather than `unsigned long` when calculating \(2^{32}\) or larger. Windows keeps `unsigned long` at 32 bits—even in a 64-bit program—so its maximum is `4,294,967,295`; \(2^{32}\) overflows and wraps to `0`. `unsigned long long` is 64 bits and correctly holds \(2^{32} = 4,294,967,296\). Verify with `sizeof(unsigned long)` (usually `4`) and `sizeof(unsigned long long)` (`8`).
---



