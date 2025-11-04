#include <stdio.h>
#include <string.h>

#define SIZE 5
#define LEN 50  

int main() {
    int store[SIZE] = {0};
    int sold[SIZE] = {0};
    int remain[SIZE] = {0};
    int price[SIZE] = {0};
    int totalSales[SIZE] = {0};

    char productName[SIZE][LEN] = {"상품1", "상품2", "상품3", "상품4", "상품5"}; 
    int totalIn = 0;
    int totalSold = 0;

    int menu;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 저장, 6. 불러오기, 7. 종료)\n> ");
        scanf("%d", &menu);

        if (menu == 1) {
            int id, in, p;
            printf("입고할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) continue;
            printf("%s의 입고 수량 입력: ", productName[id - 1]);
            scanf("%d", &in);
            store[id - 1] += in;
            remain[id - 1] += in;
            totalIn += in;
            if (price[id - 1] == 0) {
                printf("%s의 판매가격 입력: ", productName[id - 1]);
                scanf("%d", &p);
                price[id - 1] = p;
            }
            printf("%s 입고 완료! (현재 재고: %d, 가격: %d원)\n", productName[id - 1], remain[id - 1], price[id - 1]);

        } else if (menu == 2) {
            int id, out;
            printf("판매할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) continue;
            if (remain[id - 1] == 0) {
                printf("%s (ID %d) : 재고가 없습니다!\n", productName[id - 1], id);
                continue;
            }
            printf("%s의 판매 수량 입력: ", productName[id - 1]);
            scanf("%d", &out);
            if (remain[id - 1] >= out) {
                sold[id - 1] += out;
                remain[id - 1] -= out;
                totalSold += out;
                totalSales[id - 1] += out * price[id - 1];
                printf("%s 판매 완료! (남은 재고: %d, 총매출: %d원)\n", 
                       productName[id - 1], remain[id - 1], totalSales[id - 1]);
            } else {
                printf("%s (ID %d) : 재고부족!\n", productName[id - 1], id);
            }

        } else if (menu == 3) {
            int id;
            printf("조회할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) continue;
            printf("\n[개별 상품 현황]\n");
            printf("ID %d\n상품명: %s\n가격: %d원\n재고: %d\n판매량: %d\n총매출: %d원\n",
                   id, productName[id - 1], price[id - 1], remain[id - 1],
                   sold[id - 1], totalSales[id - 1]);

        } else if (menu == 4) {
            int totalAll = 0;
            printf("\n[전체 상품 현황]\n");
            for (int i = 0; i < SIZE; i++) {
                printf("ID %d | 상품명: %-6s | 가격: %5d원 | 재고: %3d | 판매량: %3d | 매출: %6d원\n",
                       i + 1, productName[i], price[i], remain[i], sold[i], totalSales[i]);
                totalAll += totalSales[i];
            }
            printf("전체 총매출 합계: %d원\n", totalAll);

        } else if (menu == 5) {  // 🔹 바이너리 저장
            FILE *fp = fopen("product_data.dat", "wb");
            if (fp == NULL) {
                printf("파일 저장 실패!\n");
                continue;
            }
            fwrite(productName, sizeof(productName), 1, fp);
            fwrite(price, sizeof(price), 1, fp);
            fwrite(store, sizeof(store), 1, fp);
            fwrite(sold, sizeof(sold), 1, fp);
            fwrite(remain, sizeof(remain), 1, fp);
            fwrite(totalSales, sizeof(totalSales), 1, fp);
            fclose(fp);
            printf("상품정보가 바이너리 파일에 저장되었습니다.\n");

        } else if (menu == 6) {  // 🔹 바이너리 불러오기
            FILE *fp = fopen("product_data.dat", "rb");
            if (fp == NULL) {
                printf("파일 불러오기 실패! (파일 없음)\n");
                continue;
            }
            fread(productName, sizeof(productName), 1, fp);
            fread(price, sizeof(price), 1, fp);
            fread(store, sizeof(store), 1, fp);
            fread(sold, sizeof(sold), 1, fp);
            fread(remain, sizeof(remain), 1, fp);
            fread(totalSales, sizeof(totalSales), 1, fp);
            fclose(fp);
            printf("상품정보가 바이너리 파일에서 불러와졌습니다.\n");

        } else if (menu == 7) {
            printf("프로그램을 종료합니다.\n");
            break;

        } else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
