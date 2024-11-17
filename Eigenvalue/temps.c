// double** matAdd(double** A, double** B, int m, int n){
//     double** C = createMat(m, n);

//     for(int i=0; i<m; i++){
//         for(int j=0;j<n;j+=8){
//             __m256d m0 = _mm256_setzero_pd();
//             __m256d m1 = _mm256_broadcast_pd(A[i]+j);
//             __m256d m2 = _mm256_broadcast_pd(B[i]+j);
//             __m256d m3 = _mm256_add_pd(m1, m2);
//             _mm256_store_pd(C[i]+j, m0);
//         }
//     }
//     return C;
// }

// double** malMul(double** A, double** B, int m, int p, int n){
//     double** C = createMat(m, n);

//     for(int i=0;i<m;i+=8){
//         for(int j=0;j<n;j++){
//             __m256d m0 = _mm256_setzero_pd();
//             for(int k=0;k<p;k++){
//                 __m256d m1 = _mm256_broadcast_pd(A[i]+k);
//                 __m256d m2 = _mm256_load_pd(B[k]+j);
//                 __m256d m3 = _mm256_mul_pd(m1, m2); 
//                 m0 = _mm256_add_pd(m0, m3);
//             }
//             _mm256_store_ps(C[i]+j,m0);
//         }
//     }

//     return C;
// }

// double** scaleMat(double** A, double c, int m, int n){
//     double** C = createMat(m, n);

//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j+=8){
//             __m256d m0 = _mm256_setzero_pd();
//             __m256d m1 = _mm256_broadcast_pd(A[i]+j);
//             __m256d m2 = _mm256_load_pd(&c);
//             m0 = _mm256_mul_pd(m1, m2);
//             _mm256_store_ps(C[i]+j, m0);
//         }
//     }

//     return C;
// }

// double complex** createMat(int m, int n){
//     double complex** A;
//     A = malloc(m * sizeof(double*));
//     for(int i=0;i<m;i++){
//         A[i] = malloc(n * sizeof(double));
//     }
//     return A;
// }

// #pragma omp parallel num_threads(4)
// double complex** matAdd(double complex** A, double complex** B, int m, int n){
//     double complex** C = createMat(m, n);
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             C[i][j] = A[i][j] + B[i][j];
//         }
//     }

//     return C;
// }

// #pragma omp parallel num_thread(4)
// double complex** matMul(double complex** A, double complex** B, int m, int p, int n){
//     double complex ** C = createMat(m, n);
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++) C[i][j] = 0;
//     }

//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<p;j++){
//             for(int k=0;k<n;k++) C[i][k] += A[i][j] * B[j][k];
//         }
//     }

//     return C;
// }

// #pragma omp parallel num_threads(4)
// double complex** eye(int m){
//     double complex ** e = createMat(m, m);
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<m;j++){
//             if(i==j) e[i][j] = 1;
//             else e[i][j] = 0;
//         }
//     }

//     return e;
// }

// #pragma omp parallel num_threads(4)
// double complex** zeros(int m, int n){
//     double complex** C = createMat(m,n);

//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++) C[i][j] = 0;
//     }

//     return C;
// }

// #pragma omp parallel num_threads(4)
// double complex** transpose(double complex** A, int m, int n){
//     double complex** C = createMat(n, m);
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             C[j][i] = A[i][j];
//         }
//     }

//     return C;
// }

// #pragma omp parallel num_threads(4)
// double complex** getCol(double complex** A, int m, int k){
//     double complex** C = createMat(m,1);

//     #pragma omp for
//     for(int i=0;i<m;i++){
//         C[i][0] = A[i][k];
//     }

//     return C;
// }

// #pragma omp parallel num_threads(4)
// double complex norm(double complex** A, int m){
//     double complex n = 0;
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         n+=A[i][0]*conj(A[i][0]);
//     }
//     return csqrt(n);
// }

// #pragma omp parallel num_threads(4)
// double complex** inner(double complex** A, double complex** B, int m){
//     double complex C = 0;
    
//     #pragma omp for
//     for(int i=0;i<m;i++){
//         C += A[i][0] * B[i][0];
//     }
// }

// #pragma omp parallel num_threads(4)
// double complex** scale(double complex** A, double complex x, int m, int n){
//     double complex** C = createMat(m ,n);

//     #pragma omp for
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             C[i][j] = x * A[i][j];
//         }
//     }

//     return C;
// }

