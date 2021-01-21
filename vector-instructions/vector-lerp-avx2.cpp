#include <immintrin.h>

void vector_lerp(float* a, float* b, float* c, size_t N, float p) {
    __m256 Vp = _mm256_set1_ps(p);
    __m256 Vq = _mm256_set1_ps(1 - p);
    for (size_t i=0; i < N; i += 8) {
        __m256 Va  = _mm256_loadu_ps(a + i);
        __m256 Vb  = _mm256_loadu_ps(b + i);
        __m256 Vt0 = _mm256_mul_ps(Va, Vp);
        __m256 Vt1 = _mm256_mul_ps(Vb, Vq);
        __m256 Vc  = _mm256_mul_ps(Vt0, Vt1);
        _mm256_storeu_ps(c + i, Vc);
    }

    for (size_t i=(N / 8) * 8; i < N; i++)
        c[i] = (a[i] * p) + (b[i] * (1 - p));
}
