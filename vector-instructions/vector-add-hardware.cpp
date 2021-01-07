Va = vector_load(a);     // Va holds 8 elements
Vb = vector_load(b);     // ... likewise Vb
Vc = vector_add(Va, Vb); // execute 8 additions
vector_store(c, Vc);     // save 8 elements from Vc
