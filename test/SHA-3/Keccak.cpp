#include "keccak.h"
#include <cstring>
#include <cstdio>
 
uint64_t Keccak::rot(uint64_t num, int offset) {
    if (offset == 0) {
        return num;
    }
    return (num << offset) | (num >> (64 - offset));
}
 
void Keccak::theta(uint64_t input[MAT][MAT], uint64_t output[MAT][MAT]) {
    for (int i = 0; i < MAT; ++i) {
        theta_C[i] = 0x0;
        for (int j = 0; j < MAT; ++j) {
            theta_C[i] ^= input[i][j];
        }
    }
 
    for (int i = 0; i < MAT; ++i) {
        theta_D[i] = theta_C[(i - 1 + MAT) % MAT] ^ rot(theta_C[(i + 1) % MAT], 1);
    }
 
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            output[i][j] = input[i][j] ^ theta_D[i];
        }
    }
}
 
void Keccak::rho_pi(uint64_t input[MAT][MAT], uint64_t output[MAT][MAT]) {
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            output[j][(2 * i + 3 * j) % MAT] = rot(input[i][j], R_CONS[i][j]);
        }
    }
    // printf("%lld\n", output[0][0]);
}
 
void Keccak::chi(uint64_t input[MAT][MAT], uint64_t output[MAT][MAT]) {
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            output[i][j] = input[i][j] ^ ((~input[(i + 1) % MAT][j]) & input[(i + 2) % MAT][j]);
        }
    }
}
 
void Keccak::iota(uint64_t input[MAT][MAT], int round) {
    input[0][0] ^= RC[round];
}
 
void Keccak::keccak_f(int round) {
    theta(after_f, after_theta);
    rho_pi(after_theta, after_rho_pi);
    chi(after_rho_pi, after_f);
    iota(after_f, round);
}
 
uint8_t* Keccak::encrypt(uint8_t *seq, int seq_len) {
    uint8_t *pad_seq;
    int block;
    int pad_zero = 0;
    if ((seq_len + MIN_PAD) % r != 0) {
        pad_zero = r - (seq_len + MIN_PAD) % r;
    }
    block = (seq_len + MIN_PAD + pad_zero) / r;
    pad_seq = new uint8_t[seq_len + MIN_PAD + pad_zero];
    memcpy(pad_seq, seq, seq_len);
    pad_seq[seq_len] = P;
    if (pad_zero > 0) {
        memset(pad_seq + seq_len + 1, 0, pad_zero);
    }
    pad_seq[seq_len + MIN_PAD + pad_zero - 1] |= 0x80;
 
    for (int i = 0; i < MAT; ++i) {
        for (int j = 0; j < MAT; ++j) {
            after_f[i][j] = 0;
        }
    }
 
    for (int i = 0; i < block; ++i) {
        int pos = 0;
        for (int j = i * r; j < (i + 1) * r; j += 8) {
            uint64_t t = 0;
            for (int k = j + 7; k >= j; --k) {
                t = (t << 8) | pad_seq[k];
            }
            after_f[pos % MAT][pos / MAT] ^= t;
            pos++;
        }
        for (int j = 0; j < nr; ++j) {
            keccak_f(j);
        }
    }
 
    for (int i = 0; i < output_len; ) {
        for (int j = 0; j < 8; ++j) {
            result[i] = after_f[(i / 8) % MAT][(i / 8) / MAT] & 0xff;
            after_f[(i / 8) % MAT][(i / 8) / MAT] >>= 8;
            i++;
            if (i >= output_len) {
                break;
            } 
        }
    }
    return result;
}
