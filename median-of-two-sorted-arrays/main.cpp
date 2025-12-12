class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) nums1.swap(nums2);
        int l1 = 0, r1 = nums1.size() - 1, l2 = 0, r2 = nums2.size() - 1;
        while (r2 - l2 + 1 > 2) {
            int m2 = (l2 + r2) / 2;
            int m1 = (l1 + r1) / 2;
            int cut = (r2 - l2) / 2;
            if (nums2[m2] < nums1[m1]) {
                l2 += cut;
                r1 -= cut;
            } else {
                r2 -= cut;
                l1 += cut;
            }
        }
        vector<int> v;
    int len1 = r1 - l1 + 1;
    int mid1 = l1 + len1 / 2;

    if (len1 % 2 == 1) { // 取中间 5 个
        for (int i = max(l1, mid1 - 2); i <= min(r1, mid1 + 2); ++i) v.push_back(nums1[i]);
    } else {             // 取中间 6 个
        for (int i = max(l1, mid1 - 3); i <= min(r1, mid1 + 2); ++i) v.push_back(nums1[i]);
    }

    for (int i = l2; i <= r2; ++i) v.push_back(nums2[i]);

    sort(v.begin(), v.end());

    int n = (int)v.size();
    return (n % 2) ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }

};