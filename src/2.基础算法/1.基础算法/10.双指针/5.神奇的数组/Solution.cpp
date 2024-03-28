/**
 * https://www.lanqiao.cn/problems/3000/learning/?page=1&first_category_id=1&name=%E7%A5%9E%E5%A5%87%E7%9A%84%E6%95%B0%E7%BB%84
*/
/*
本题有三个难点：
1、前缀数组的使用
    由于本题涉及到数组片段和，故想到使用前缀数组；对于异或同样存在类似的前缀数组
    故还应再设置一个异或数组yh[]，yh[i]保存从yh[0]到yh[i]连续异或的结果
    经过验算发现，对于从a[i]到a[j]的连续异或，等于对yh[i]和yh[j-1]求异或
2、异或性质的理解
    异或的本质是模2加，即不带进位的二进制加法
    若一个序列模2加的结果等于普通加法的结果，说明任意两位都不发生进位
    则对于其任意一个子序列，其模2加的结果同样等于普通加法的结果
    故得到重要结论：若从a[i]异或到a[j]等于从a[i]累加到a[j]，则任取一个子序列，均满足此性质
3、双指针的使用
    得出了如上重要结论后，不难想到双指针在本题的用法：
    若a[j]连续异或到a[i]等于a[j]加到a[i],则计数值直接加上此区间的长度即可，然后右端点i前移一个单位
    否则左端点j前移一个单位继续验证
*/
#include <iostream>
#include <vector>

using ll = long long;

ll solve(const std::vector<ll>& nums)
{
    int n = nums.size();
    std::vector<ll> xor_prefix(n); // 异或前缀数组
    std::vector<ll> add_prefix(n); // 加法前缀数组

    xor_prefix[0] = add_prefix[0] = 0;

    for(int i = 1; i < n; ++i)
    {
        xor_prefix[i] = xor_prefix[i - 1] ^ nums[i];
        add_prefix[i] = add_prefix[i - 1] + nums[i];
    }

    int slow = 0, fast = 0;
    ll cnt = 0;
    while(slow < n && fast < n)
    {
        if(xor_prefix[fast] ^ xor_prefix[slow - 1] == add_prefix[fast] - add_prefix[slow - 1])
        {
            cnt += (fast - slow + 1);
            ++fast;
        }
        else
        {
            ++slow;
        }
    }
    return cnt;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<ll> nums(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::cout << solve(nums) << std::endl;

    return 0;
}