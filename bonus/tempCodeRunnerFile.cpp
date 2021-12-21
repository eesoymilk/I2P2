 = MinOptUB(psum, n - i, m);
        // LL S_tmp = A * i + B * ub;   // LL
        // if (S < S_tmp) {
        //     S = S_tmp;
        //     int min = a[ub].first;
        //     sol = a;
        //     for (i = 1; i < ub; i++)
        //         sol[i].first = min;
        // }