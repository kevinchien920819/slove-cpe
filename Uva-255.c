#include<stdio.h>
#include<stdlib.h>

struct position{
    int x;
    int y;
};

int main(){
    char map[8][8] = {0};
    int king,queen,queen_next;
    while(scanf("%d %d %d",&king,&queen,&queen_next) != EOF){
        if(king == queen){
            printf("Illegal state\n");
            continue;
        }
        else if(king == queen_next){
            printf("Illegal move\n");
            continue;    
        }
        struct position kingpos = {king % 8, king / 8} ;
        struct position queenpos= {queen % 8, queen / 8} ;
        int nextx,nexty;
        nextx = queen_next % 8;
        nexty = queen_next / 8;
        if(nextx++ == kingpos.x || nextx-- == kingpos.x || nexty++ == kingpos.y || nexty-- == kingpos.y){
            printf("Move not allowed\n");
            continue;
        }
        int legal[62] = {0}; 
        
    }
}