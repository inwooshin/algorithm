#include <iostream>

using namespace std;

int main(void) {

    //고정 비용 - fixedCost, 가변 비용 - var(iable)Cost
    long long fixedCost = 0, varCost = 0;
    //판매 가격 - salePrice, 수익 - revenue;
    long long salePrice = 0;

    cin >> fixedCost >> varCost >> salePrice;

    if (varCost >= salePrice) {
        cout << -1;
        return 0;
    }

    cout << fixedCost / (salePrice - varCost) + 1;
    
    return 0;
}