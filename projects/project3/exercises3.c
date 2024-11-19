#include "exercises3.h"

void soru01(const char* s, int frequencies[26]){
	for (int i = 0; i < 26; i++) {
        frequencies[i] = 0;
    }

	while(*s){
		char mychar = *s;

		int isChar = 0;

		if(mychar >= 'A' && mychar <= 'Z'){
			isChar = 1;
			mychar = mychar + 32;
		}
		else if(mychar >= 'a' && mychar <= 'z'){
			isChar = 1;
		}
		else{
			isChar = 0;
		}

		if(isChar == 1){
			mychar = mychar - 'a';
			frequencies[mychar] = frequencies[mychar] + 1;
		}

		s++;
	}
}

int soru02(const int* A, int size, int* evens, int* odds){
	int evenCount = 0;  
    int oddCount = 0;  

    for (int i = 0; i < size; i++) {
        if (A[i] % 2 == 0) { 
            evens[evenCount++] = A[i]; 
        } else { // Tek sayılar
            odds[oddCount++] = A[i]; 
        }
    }

    return evenCount; 
}

void soru03(const int* A1, int size1, const int* A2, int size2, int* B){
	int length = size1+size2;

	int index1 = 0;
	int index2 = 0;

	for(int i=0; i<length; i++){
		if(index1 >= size1 && index2 < size2){
			B[i] = A2[index2];
			index2++;
		}
		else if(index2 >= size2 && index1 < size1){
			B[i] = A1[index1];
			index1++;
		}
		else if(A1[index1] <= A2[index2]){
			B[i] = A1[index1];
			index1++;
		}
		else{
			B[i] = A2[index2];
			index2++;
		}
	}
}

void soru04(char* s){
	int start = 0;         
    int end = 0;          

    while (s[end] != '\0') {
        end++;
    }
	end--;

    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}

void soru05(int x, char* s, int base){
	if (base < 2 || base > 36) {
        *s = '\0';  
        return;
    }

    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    char temp[36];  
    int index = 0;

    while (x > 0) {
        temp[index++] = digits[x % base];  
        x /= base;  
    }

    int i;
    for (i = 0; i < index; i++) {
        s[i] = temp[index - i - 1];
    }
    s[i] = '\0';  
}

int soru06(char* s1, char* s2){
	while (*s1 && *s2) {
        if (*s1 < *s2) {
            return -1; 
        } else if (*s1 > *s2) {
            return 1;  
        }
        s1++; 
        s2++;
    }

    if (*s1) {
        return 1; 
    } 
	else if (*s2) {
        return -1; 
    }

    return 0;
}

char* soru07(char* s, char c){

	while(*s){ 
		if(*s == c){
			return s;
		}
		s++;
	}
 	
	return NULL;	
}

void soru08(char* s, char c, char** p){
	*p = NULL;

	while(*s){ 
		if(*s == c){
			*p = s;
		}
		s++;
	}
}

void soru09(int A[][SIZE_MAX], const int rowSize, const int colSize, int* minPtr){
	*minPtr = A[0][0]; 

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (A[i][j] < *minPtr) { 
                *minPtr = A[i][j];  
            }
        }
    }
}

void soru10(char* s[], const int size, int* A){

}