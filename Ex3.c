#include <stdio.h>

void nhapChuoi(char* str) {
    printf("Nhap vao chuoi: ");
    fgets(str, 200, stdin);
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void inChuoiDaoNguoc(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

int demSoTu(char* str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] != ' ' && (i == 0 || str[i - 1] == ' '))) {
            count++;
        }
        i++;
    }
    return count;
}

void soSanhChuoi(char* str1) {
    char str2[200];
    printf("Nhap vao chuoi so sanh: ");
    fgets(str2, 200, stdin);
    int len1 = 0, len2 = 0;

    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }

    if (len1 < len2) {
        printf("Chuoi so sanh dai hon chuoi ban dau.\n");
    } else if (len1 > len2) {
        printf("Chuoi so sanh ngan hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi bang nhau.\n");
    }
}

void inHoaChuoi(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        putchar(str[i]);
        i++;
    }
    printf("\n");
}

void themChuoiVaoCu(char* str) {
    char str2[200];
    printf("Nhap vao chuoi de them: ");
    fgets(str2, 200, stdin);

    int len1 = 0, len2 = 0;
    while (str[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
    }

    for (int i = 0; i < len2; i++) {
        str[len1 + i] = str2[i];
    }
    str[len1 + len2] = '\0';
}

int main() {
    char str[200];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh chuoi voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoiDaoNguoc(str);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoTu(str));
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaChuoi(str);
                break;
            case 6:
                themChuoiVaoCu(str);
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 7);

    return 0;
}

