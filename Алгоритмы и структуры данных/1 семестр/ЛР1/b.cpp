#include <iostream>
using namespace std;
int main () {
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    K = K % N;
    if (K<0) {
        K= N+K;
    }

    for (int j=0; j<K; j++ ) {
        int temp= arr[N-1];
        int prev=arr[0];
        for (int i=1; i<N; i++){
            int current= arr[i];
            arr[i]= prev;
            prev=current;
        }
        arr[0]=temp;
    }


    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}