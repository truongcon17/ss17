#include <stdio.h>

void nhapChuoi(char* str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void inChuoi(char* str) {
    printf("Chuoi ban nhap: %s\n", str);
}

int demChuCai(char* str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            count++;
        }
        str++;
    }
    return count;
}

int demChuSo(char* str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int demKyTuDacBiet(char* str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9') || (*str == ' '))) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demChuCai(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demChuSo(str));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 6);

    return 0;
}

