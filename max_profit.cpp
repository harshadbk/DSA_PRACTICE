#include<iostream>
using namespace std;

void max_profit(int prices [],int size){
    int bestBuy = prices[0];
    int maxProfit = 0;
    for(int i=1;i<size;i++){
        if(prices[i]>bestBuy){
          maxProfit = max(maxProfit,prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy,prices[i]);
    }
    cout << maxProfit;
};

int main(){
    int prices [] = {7,1,2,6,4,3};
    int size = 6;
    max_profit(prices,size);
    return 0;
}