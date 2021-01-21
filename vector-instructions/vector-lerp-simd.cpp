void vector_lerp(float* a, float* b, float* c, size_t N, float p) {
    auto Vp = vector_broadcast(p);     // Vp = [p,...,p]
    auto Vq = vector_broadcast(1 - p); // Vq = [1-p,...,1-p]
    for (size_t i=0; i < N; i += 8) {
        auto Va  = vector_load(a + i);
        auto Vb  = vector_load(b + i);
        auto Vt0 = vector_mul(Va, Vp); // a * p
        auto Vt1 = vector_mul(Vb, Vq); // b * (1 - p)
        auto Vc  = vector_add(Vt0, Vt1);
        vector_store(c + i, Vc);
    }

    for (size_t i=(N / 8) * 8; i < N; i++)
        c[i] = (a[i] * p) + (b[i] * (1 - p));
}
