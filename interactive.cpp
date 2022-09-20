/*
  Sample problem : there is a hidden array of N integers. The length is odd. There is a number which appears maximum times in the array. Guess any index with
  the of the array where the number is present in no more than N/2 query.
*/

struct Interactor{
    vector<int> arr;
    int n;
    int majorityElement;
    Interactor(){
        int zeros = 0;
        int ones = 0;
        n = 101;
        for(int i = 0; i <= 100; i++){
            arr.pb(getRandomNumber(0, 1));
        }
        for(int i = 0; i <= 100; i++){
            if(arr[i] == 0)
                zeros++;
            else
                ones++;
        }
        majorityElement = zeros > ones ? 0 : 1;
        assert(sz(arr) == n);
    }
    int queryHandler(int queryNumber){
        assert(queryNumber >= 0 && queryNumber < n);
        if(arr[queryNumber] == majorityElement)
            return 1;
        else
            return 0;
    }
};

Interactor it;
int query(int value){
    cout << "? " << value << endl;
    return it.queryHandler(value);
    // char result;
    // cin >> result;
    // return result;
}
void solve() {
    it = Interactor();
    debug(it.arr);
    int iterations = 0;
    while(true){
        iterations++;
        int index = getRandomNumber(0, it.n - 1);
        if(query(index)){
            cout << index << endl;
            break;
        }
    }
    debug(iterations)
}
