#include <stdio.h>

void arabicToRoman(int num) {
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};


    for (int i = 0; num > 0; i++) {
        while (num >= arabic[i]) {
            printf("%s", roman[i]);
            num -= arabic[i];
        }
    }

    printf("\n");
}

int main() {
    int inPut;

    //Enter an Arabic numeral (1-3999)
    scanf("%d", &inPut);

    arabicToRoman(inPut);

    return 0;
}
