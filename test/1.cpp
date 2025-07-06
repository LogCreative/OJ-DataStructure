#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun(void* vp1, void* vp2, int size){char* buffer =(char*)malloc(size);memcpy(buffer, vp1, size);memcpy(vp1, vp2, size);memcpy(vp2, buffer, size);}
int main(){
char str1[]= "love";
char str2[]= "nowcoder";
fun(str1, str2, sizeof(char*));
printf("%s,", str1);
printf("%s\n", str2);
return 0;
}