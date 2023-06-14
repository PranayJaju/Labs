#include<stdio.h>
#include<stdlib.h>
int q[50];
int front = -1;
int rear = -1;
int dq(){
if(front == -1) return -1;
else return q[front++];
}
void queue(int n){
if(n==49) printf("FULL");
else q[++rear]=n;
if(front == -1) front++;
}
void main(){
int AM[6][6]= {{0, 1, 1, 0, 0, 0},
{1, 0, 0, 0, 1, 0},
{1, 0, 0, 1, 1, 1},
{0, 0, 1, 0, 0, 1},
{0, 1, 1, 0, 0, 1},
{0, 0, 1, 1, 1, 0}};
int vis[6]={0,0,0,0,0,0};
int ver = 2;
queue(ver);
while(front<=rear){
ver = dq();
printf("%d ",ver);
vis[ver]=1;
for(int i=0; i<6; i++){
if(!vis[i] && AM[ver][i]){
queue(i);
vis[i]=1;
}
}
}
}

