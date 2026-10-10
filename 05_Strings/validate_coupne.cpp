#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool validatecoupons(string coupon);
bool validateindustries(string industries);

void validatcoupon(vector<string> &coupons, vector<string> &industries, vector<bool> isvalid)
{
    vector<pair<string, string>> validpair;
    for (int i = 0; i < coupons.size(); i++)
    {
        if (validatecoupons(coupons[i]) && validateindustries(industries[i]) && isvalid[i])
        {
            validpair.push_back({coupons[i], industries[i]});
        }
    }

    sort(validpair.begin(), validpair.end());

    vector<string> ans;

    for (auto &s : validpair)
    {
        ans.push_back(s.first);
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}

bool validatecoupons(string coupon)
{
    if (coupon.length() < 0)
        return false;
    for (char ch : coupon)
    {
        if (!(isalnum(ch) || ch == '_'))
            return false;
    }
    return true;
}

bool validateindustries(string industries)
{
    return industries == "electronics" ||
           industries == "grocery" ||
           industries == "pharmacy" ||
           industries == "restaurant";
}

int main()
{
    vector<string>  coupons = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> indus = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isactive = {true,true,true,true};
    validatcoupon(coupons,indus,isactive);
    return 0;
}