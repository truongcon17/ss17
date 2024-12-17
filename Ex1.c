#include<stdio.h>

    void dodaicuamang(int n, int size){
    	for(int i = 0; i < n; i++){
    		size++;
		}
    	printf("Do dai cua mang la %d\n", size);
	}
    
    void tongphantu(int *arrPrt, int tong, int n){
    	for(int i = 0; i < n; i++){
    		tong += *(arrPrt + i);
		}
		printf("Tong cac phan tu cua mang la %d\n", tong);
	}
    
    void phantulonnhat(int n, int *arrPrt){
    	int max = *arrPrt;
		for(int i = 1; i < n; i++){
    		if(*(arrPrt + i) > max){
    			max = *(arrPrt + i);
			}
		}
        printf("Phan tu lon nhat trong mang la %d\n", max);
	}
	
    
    
    
int main(){
	int  *arrPrt;
	int arr[100];
	int n;
	int number;
    int size = 0, tong = 0;
    do{
	
	
	printf("\nMENU\n");
	printf("1. Nhap vao so phan tu va tung phan tu\n");
	printf("2. Hien thi cac phan tu trong mang\n");
	printf("3. Tinh do dai cua mang\n");
	printf("4. Tinh tong cac phan tu trong mang\n");
	printf("5. Hien thi phan tu lon nhat\n");
	printf("6. Thoat\n");
	
	printf("Vui long nhap lua chon cua ban : ");
	scanf("%d", &number);
	
	switch(number){
		
	case 1:	
	printf("Vui long nhap kich thuoc mang : ");
	scanf("%d", &n);
	if( n <= 0 || n > 100){
		printf("Gia tri khong hop le ");
	}else{
		arrPrt = arr; 
		for(int i = 0; i < n; i++){
			printf("Vui long nhap phan tu arr[%d] : ", i + 1);
			scanf("%d", (arrPrt + i));
		}
	}
	break;	
	
	case 2:
		for(int i = 0; i < n; i++ ){
		   printf("\nPhan tu arr[%d] la %d", i + 1, *(arrPrt + i));
	    }
		
	break;	

    case 3:
    	dodaicuamang(n, size);
    
	break;	
    
    case 4:
    	tongphantu(arrPrt, tong, n);
    	
    break;

    case 5:
		phantulonnhat(n, arrPrt); 

	break;
	
	case 6:
		printf("Thoat chuong trinh");
	
	break;
    }
    }while( number != 6);
	
	return 0;
}
/*
MENU

Nh?p vào s? ph?n t? và t?ng ph?n t?
 

Hi?n th? các ph?n t? trong m?ng
 

Tính d? dài m?ng
 

Tính t?ng các ph?n t? trong m?ng
 

Hi?n th? ph?n t? l?n nh?t
 

Thoát         */
