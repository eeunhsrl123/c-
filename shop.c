#include <stdio.h>

int main() {
    int n;  // 상품 개수
    scanf("%d", &n);

    int inStock[100];   // 입고 수량
    int sold[100];      // 판매 수량
    int remain[100];    // 재고 수량

    // 상품별 입고 수량 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &inStock[i]);
    }

    // 상품별 판매 수량 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &sold[i]);
    }

    // 재고 계산
    for (int i = 0; i < n; i++) {
        remain[i] = inStock[i] - sold[i];
    }

    // ID 입력 (1부터 시작)
    int id;
    scanf("%d", &id);

    // 해당 상품 재고 출력

    printf("%d\n", remain[id - 1]);

    // 전체 상품 재고 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", remain[i]);
    }

    return 0;
}
