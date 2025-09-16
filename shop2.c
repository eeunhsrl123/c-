#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int n;  // 상품 개수
    scanf("%d", &n);

    int store[SIZE];   // 입고 수량
    int sold[SIZE];      // 판매 수량
    int remain[SIZE];    // 재고 수량

    int totalIn = 0; //총 입고량
    int totalSold = 0; //총 판매량

    // 상품별 입고 수량 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &store[i]);
        totalIn += store[i];
    }

    // 상품별 판매 수량 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
        totalSold += sold[i];
    }

    // 재고 계산
    for (int i = 0; i < n; i++) {
        remain[i] = store[i] - sold[i];
    }

    // 1. 전체 재고 출력
    printf("재고수량 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", remain[i]);
    }
    printf("\n");

    // 2. 총 판매량 및 판매율
    double rate = (double) totalSold / totalIn * 100;
    printf("총 판매량 : %d (판매율 %.2f%%)\n", totalSold, rate);

    // 3. 최대 판매량, 최소 판매량
    int maxSold = sold[0], minSold = sold[0];
    int maxID = 1, minID = 1;
    for (int i = 1; i < n; i++) {
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

    // 4. 재고 부족(2 이하) 상품 출력
    for (int i = 0; i < n; i++) {
        if (remain[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, remain[i]);
        }
    }

    return 0;
}
