#include<stdio.h>
#include<stdlib.h>
struct dna{
    int rate;
    int index;
};
int cmp(const void *i, const void *j) {
    struct dna *a, *b;
    a = (struct dna *)i, b = (struct dna *)j;
    if(a->rate != b->rate)
        return a->rate - b->rate;
    return a->index - b->index;
}
int main(){
    int n,m,t;
    char dna_data [101][101];
    scanf("%d", &t);
    while(t--){
    scanf("%d %d",&n,&m);
    struct dna input[101];
    for(int i = 0;i < m;i++){
        scanf("%s",dna_data[i]);
        int sort_rate = 0;
            for(int j = 0; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(dna_data[i][j] > dna_data[i][k]) {
                        sort_rate++;
                    }
                }
            }
        input[i].rate = sort_rate;
        input[i].index = i;
    }
    qsort(input, m, sizeof(struct dna), cmp);
    for(int i = 0 ; i < m; i++){
        puts(dna_data[input[i].index]);
    }
    if(t)
            puts("");
    }
    return 0;
}