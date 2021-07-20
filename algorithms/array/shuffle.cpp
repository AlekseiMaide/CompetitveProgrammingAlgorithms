
/** 
    Fisher-Yates shuffle in O(N) time.
    Returns a random shuffling of the array.
*/
void shuffle(vector<int>& nums) {
    int N = nums.size();
    srand (time(NULL));

    for (int i = N - 1; i > 0; i--) {
        int pos = rand() % (i + 1);
            
        swap(nums[i], nums[pos]);
    }
}
