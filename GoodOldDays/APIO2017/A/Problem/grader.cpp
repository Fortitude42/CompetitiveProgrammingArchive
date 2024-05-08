#include "rainbow.h"
using namespace std;
#include <iostream>
#include <stdio.h>

static int R, C, M, Q;
static int sr, sc;
static char S[100000 + 5];

int main() {
	freopen(".in", "r", stdin);
    scanf("%d %d %d %d", &R, &C, &M, &Q);
    scanf("%d %d", &sr, &sc);
    if (M > 0) {
        scanf(" %s ", S);
    }

    init(R, C, sr, sc, M, S);

    int query;
    for (query = 0; query < Q; query++) {
        int ar, ac, br, bc;
        scanf("%d %d %d %d", &ar, &ac, &br, &bc);
        printf("%d\n", colour(ar, ac, br, bc));
//        cerr << colour(ar, ac, br, bc) << endl;
    }

    return 0;
}

