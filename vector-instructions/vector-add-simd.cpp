void vector_add(float* a, float* b, float* c, size_t N) {
    for (size_t i=0; i < N; i += 8) {
        auto Va = vector_load(a + i);
        auto Vb = vector_load(b + i);
        auto Vc = vector_add(Va, Vb);
        vector_store(c + i, Vc);
    }

    for (size_t i=(N / 8) * 8; i < N; i++)
        c[i] = a[i] + b[i];
}
