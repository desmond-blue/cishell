#include <stdio.h>

/* boot camp */

uint8_t CountBits(uint32_t x) {
    uint8_t num_bits = 0;
    while (x) {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}

/* 5.1 computing the parity of a word */
uint8_t Parity(uint64_t x) {
    bool_t result = 0;
    while (x) {
        result ^= 1;
        x &= (x - 1);
    }
    return result;
}

uint8_t ParityLookup(uint64_t x) {
    const uint16_t kWordSize = 16;
    const uint16_t kBitMask = 0xFFFF;
    return  precomputed_parity[x >> (3 * kWordSize)] ^
            precomputed_patiry[(x >> (2 * kWordSize)) & kBitMask] ^
            precomputed_patiry[(x >> kWordSize) & kBitMask] ^
            precomputed_patiry[x & kBitMask];
}

uint8_t ParityGroup(uint64_t x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}

/* 5.2 swap bits */
uint64_t SwapBits(uint64_t x, uint32_t i, uint32_t j) {
    if (((x >> i) & 0x1) != ((x >> j) & 0x1)) {
        uint64_t bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }

    return x;
}

/* 5.3 reverse bits */
uint64_t ReverseBits(uint64_t x) {
    uint16_t kWordSize = 16;
    uint16_t kBitMask = 0xFFFF;
    return  precomputed_reverse[x & kBitMask] << (kWordSize * 3) |
            precomputed_reverse[(x >> kWordSize) & kBitMask] << (kWordSize * 2) |
            precomputed_reverse[(x >> (2 * kWordSize)) & kBitMask] << kWordSize |
            precomputed_reverse[(x >> (3 * kWordSize)) & kBitMask];
}

/* 5.4 Find a closest integet with the same weight */
uint64_t ClosestIntSameBitCoutn(uint64_t x) {
    int kNumUnsignedBits = 64;
    for (int = 0; i < kNumUnsignedBits; i++) {
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
            x ^= (1UL << i) | (1UL << (i + 1));
            return x;
        }
    }

    assert(0, "All bits are 0 or 1");
}

/* 5.5 Compute x*y without arithmetical operators */
uint32_t Multiply(uint32_t x, uint32_t y) {
    uint32_t result = 0;
    while (x) {
        if (x & 1) {
            result = Add(result, y);
        }
        x >>= 1;
        y <<= 1;
    }
}

uint32_t Add(uint32_t a, uint32_t b) {
    uint32_t sum = 0, carryin = 0, k = 1;
    uint32_t temp_a = a, temp_b = b;
    while (temp_a || temp_b) {
        uint32_t ak = a & k, bk = b & k;
        uint32_t carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        sum |= (carryin ^ ak ^ bk);
        carryin = carryout << 1;
        k <<= 1;
        temp_a >>= 1;
        temp_b >>= 1;
    }
}

/* 5.6 Comput x/y*/
un32_t Divide(uint32_t x, uint32_t y) {
    uint32_t result = 0;
    int32_t power = 32;
    uint64_t y_power = (uint64_t)y << power;
    while (x >= y) {
        while (y_power > x) {
            y_power >>= 1;
            --power;
        }

        result += 1U << power;
        x -= y_power;
    }

    return result;
}

/* 5.7 Compute x(power)y*/
double Power(double x, int32_t y) {
    double result = 1.0;
    int64_t power = y;
    if (y < 0) {
        power = -power;
        x = 1.0 / x;
    }
    while (power) {
        if (power & 1) {
            result *= x;
        }
        x *= x;
        power >>= 1;
    }

    return result;
}

/* 5.8 Reverse digits */
int32_t Reverse(int32_t x) {
    int32_t result = 0;
    int32_t remain_x = abs(x);
    while (remain_x) {
        result = result * 10 + remain_x % 10;
        remain_x /= 10;
    }
    return (x < 0) ? -result : result;
}

/* 5.9 Check if a devimal integer is a palindrome */

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    long int x_reverse = 0;
    int x_remaining = x;
    while (x_remaining) {
        x_reverse = (long int)x_reverse * 10 + x_remaining % 10;
        x_remaining /= 10;
    }

    return (x == x_reverse);
}

/* 5.10 Generate uniform random numbers */
int32_t UniformRandom(int32_t lb, int32_t ub) {
    int32_t result = 0;
    int32_t number_of_outcomes = ub - lb + 1;
    do {
        for (int32_t i = 0; (1 << i) < number_of_outcomes; i++) {
            result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= number_of_outcomes);

    return result + lb;
}

/* 5.11 Rectangle intersection */
typedef struct {
    int32_t x,
    int32_t y,
    int32_t width,
    int32_t height
} Rectangle;

bool_t IsIntersect(Rectangle rc1, Rectangle rc2) {
    return rc1.x <= rc2.x + rc2.width && rc1.x + rc1.width >= rc2.x &&
           rc1.y <= rc2.y + rc2.height && rc1.y + rc1.height >= rc2.y;
}

Rectangle IntersectRectangle(Rectangle rc1, Rectangle rc2) {
    if (!IsIntersect(rc1, rc2)) {
        return {0, 0, -1, -1};
    }
    return {max(rc1.x, rc2.x), max(rc1.y, rc2.y),
            min(rc1.x + rc1.width, rc2.x + rc2.width) - max(rc1.x, rc2.x),
            min(rc1.y + rc1.height, rc2.y + rc2.height) - max(rc1.y, rc2.y)}
}