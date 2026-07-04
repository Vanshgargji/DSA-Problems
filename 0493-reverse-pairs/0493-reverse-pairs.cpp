class Solution {
public:
    int merge(vector<int> &a, int low, int mid, int high){
        int cnt = 0;
        int l = low, r = mid+1;

        vector<int> temp;

        while(l <= mid && r <= high){
            if(a[l] <= 1LL * 2 * a[r]){
                l++;
            }
            else{
                cnt += mid - l + 1;
                r++;
            }
        }

        l = low, r = mid+1;

        while(l <= mid && r <=high){

            if(a[l] <= a[r]){
                temp.push_back(a[l]);
                l++;
            }
            else{
                temp.push_back(a[r]);
                r++;
            }
        }

        while(l <= mid){
            temp.push_back(a[l]);
            l++;
        }

        while(r <= high){
            temp.push_back(a[r]);
            r++;
        }

        for(int i=low; i<=high; i++){
            a[i] = temp[i-low];
        }

        return cnt;
    }

    int mergeSort(vector<int> &a, int low, int high){
        int cnt  = 0;

        if(low >= high) return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(a, low, mid);
        cnt += mergeSort(a, mid+1, high);
        cnt += merge(a, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};