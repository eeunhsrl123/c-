#include <stdio.h>

#define SIZE 5

int main() {
    int store[SIZE] = {0};   // 입고 수량
    int sold[SIZE] = {0};    // 판매 수량
    int remain[SIZE] = {0};  // 재고 수량

    int totalIn = 0;   // 총 입고량
    int totalSold = 0; // 총 판매량

    int menu;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n> ");
        scanf("%d", &menu);

        if (menu == 1) {  
            // 입고
            int choice;
            printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n> ");
            scanf("%d", &choice);

            if (choice == 1) { // 전체 입고
                printf("상품 5개의 입고 수량 입력: ");
                for (int i = 0; i < SIZE; i++) {
                    int in;
                    scanf("%d", &in);
                    store[i] += in;
                    remain[i] += in;
                    totalIn += in;
                }
            } else if (choice == 2) { // 개별 입고
                int id, in;
                printf("상품 ID와 입고수량 입력: ");
                scanf("%d %d", &id, &in);
                if (id >= 1 && id <= SIZE) {
                    store[id - 1] += in;
                    remain[id - 1] += in;
                    totalIn += in;
                }
            }

        } else if (menu == 2) {  
            // 판매
            int choice;
            printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n> ");
            scanf("%d", &choice);

            if (choice == 1) { // 전체 판매
                printf("상품 5개의 판매 수량 입력: ");
                for (int i = 0; i < SIZE; i++) {
                    int out;
                    scanf("%d", &out);
                    if (remain[i] >= out) {
                        sold[i] += out;
                        remain[i] -= out;
                        totalSold += out;
                    } else {
                        printf("상품 ID %d : 재고부족!\n", i + 1);
                    }
                }
            } else if (choice == 2) { // 개별 판매
                int id, out;
                printf("상품 ID와 판매수량 입력: ");
                scanf("%d %d", &id, &out);
                if (id >= 1 && id <= SIZE) {
                    if (remain[id - 1] >= out) {
                        sold[id - 1] += out;
                        remain[id - 1] -= out;
                        totalSold += out;
                    } else {
                        printf("상품 ID %d : 재고부족!\n", id);
                    }
                }
            }

        } else if (menu == 3) {  
            // 상품 현황
            printf("\n재고수량 : ");
            for (int i = 0; i < SIZE; i++) {
                printf("%d ", remain[i]);
            }
            printf("\n");

            double rate = (totalIn == 0) ? 0 : (double) totalSold / totalIn * 100;
            printf("총 판매량 : %d (판매율 %.2f%%)\n", totalSold, rate);

            // 최다/최소 판매 상품
            int maxSold = sold[0], minSold = sold[0];
            int maxID = 1, minID = 1;
            for (int i = 1; i < SIZE; i++) {
                if (sold[i] > maxSold) {
                    maxSold = sold[i];
                    maxID = i + 1;
                }
                if (sold[i] < minSold) {
                    minSold = sold[i];
                    minID = i + 1;
                }
            }
            printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID, maxSold);
            printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID, minSold);

            // 재고 부족 (2 이하)
            for (int i = 0; i < SIZE; i++) {
                if (remain[i] <= 2) {
                    printf("상품 ID %d : 재고부족(%d)\n", i + 1, remain[i]);
                }
            }

        } else if (menu == 4) {  
            // 종료
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
