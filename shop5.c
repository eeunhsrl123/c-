#include <stdio.h>
#include <string.h>

#define SIZE 5
#define LEN 50  

int main() {
    int store[SIZE] = {0};   // 입고 수량
    int sold[SIZE] = {0};    // 판매 수량
    int remain[SIZE] = {0};  // 재고 수량
    int price[SIZE] = {0};   // 상품 가격
    int totalSales[SIZE] = {0}; // 총판매금액

    char productName[SIZE][LEN] = {"상품1", "상품2", "상품3", "상품4", "상품5"}; 
    int totalIn = 0;   // 총 입고량
    int totalSold = 0; // 총 판매량

    int menu;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n> ");
        scanf("%d", &menu);

        if (menu == 1) {  
            // 입고
            int id, in, p;
            printf("입고할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) {
                printf("잘못된 ID입니다.\n");
                continue;
            }

            printf("%s의 입고 수량 입력: ", productName[id - 1]);
            scanf("%d", &in);
            store[id - 1] += in;
            remain[id - 1] += in;
            totalIn += in;

            // 가격이 아직 설정되지 않았다면 새로 입력
            if (price[id - 1] == 0) {
                printf("%s의 판매가격 입력: ", productName[id - 1]);
                scanf("%d", &p);
                price[id - 1] = p;
            }

            printf("%s 입고 완료! (현재 재고: %d, 가격: %d원)\n", productName[id - 1], remain[id - 1], price[id - 1]);

        } else if (menu == 2) {  
            // 판매
            int id, out;
            printf("판매할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) {
                printf("잘못된 ID입니다.\n");
                continue;
            }

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
            // 개별 상품 현황
            int id;
            printf("조회할 상품 ID 입력(1~5): ");
            scanf("%d", &id);
            if (id < 1 || id > SIZE) {
                printf("잘못된 ID입니다.\n");
                continue;
            }
            printf("\n[개별 상품 현황]\n");
            printf("ID %d\n상품명: %s\n가격: %d원\n재고: %d\n판매량: %d\n총매출: %d원\n",
                   id, productName[id - 1], price[id - 1], remain[id - 1],
                   sold[id - 1], totalSales[id - 1]);

        } else if (menu == 4) {  
            // 전체 상품 현황
            int totalAll = 0;
            printf("\n[전체 상품 현황]\n");
            for (int i = 0; i < SIZE; i++) {
                printf("ID %d | 상품명: %-6s | 가격: %5d원 | 재고: %3d | 판매량: %3d | 매출: %6d원\n",
                       i + 1, productName[i], price[i], remain[i], sold[i], totalSales[i]);
                totalAll += totalSales[i];
            }
            printf("전체 총매출 합계: %d원\n", totalAll);

        } else if (menu == 5) {  
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
