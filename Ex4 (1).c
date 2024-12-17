#include <stdio.h>

int kiemTraSoNguyenTo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int kiemTraSoChan(int n) {
    return n % 2 == 0;
}

void daoNguocMang(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int timKiemPhanTu(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, luaChon, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   5.1. Tang dan\n");
        printf("   5.2. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap %d phan tu:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Cac phan tu la so chan:\n");
                for (int i = 0; i < n; i++) {
                    if (kiemTraSoChan(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < n; i++) {
                    if (kiemTraSoNguyenTo(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 4:
                daoNguocMang(arr, n);
                printf("Mang sau khi dao nguoc:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Lua chon sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                int luaChonCon;
                scanf("%d", &luaChonCon);
                if (luaChonCon == 1) {
                    sapXepTangDan(arr, n);
                    printf("Mang sau khi sap xep tang dan:\n");
                } else if (luaChonCon == 2) {
                    sapXepGiamDan(arr, n);
                    printf("Mang sau khi sap xep giam dan:\n");
                }
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &key);
                int index = timKiemPhanTu(arr, n, key);
                if (index != -1) {
                    printf("Phan tu %d tim thay tai vi tri %d.\n", key, index);
                } else {
                    printf("Phan tu %d khong tim thay.\n", key);
                }
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

