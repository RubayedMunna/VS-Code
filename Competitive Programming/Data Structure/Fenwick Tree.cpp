#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
ll getSum(ll BITree[], ll index)
{
	ll sum = 0;
	index = index + 1;

	while (index>0)
	{

		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(ll BITree[], ll n, ll index, ll val)
{

	index = index + 1;
	while (index <= n)
	{
        BITree[index] += val;
	index += index & (-index);
	}
}

ll *constructBITree(ll arr[], ll n)
{
	ll *BITree = new ll[n+1];
	for (ll i=1; i<=n; i++)
		BITree[i] = 0;


	for (ll i=0; i<n; i++)
		updateBIT(BITree, n, i, arr[i]);
	return BITree;
}

int main()
{
    
	ll n;
	cout << "Enter The Number of Elememnts: ";
	cin >> n;
	ll freq[n + 10];
	cout << "Enter the Elements: ";
	for (ll i = 0; i < n;i++)
	{
		cin >> freq[i];
	}
	ll *BITree = constructBITree(freq, n);

	cout << "Enter The Number of Query: ";
	ll query;
	cin >> query;
	cout << "Enter 1 to Update and 2 to get Range Sum " << N;
	while (query--)
	{
		ll type;
		cin >> type;
		if(type==1)
		{
			cout << "Enter Index and Value: ";
			ll idx, val;
			cin >> idx >> val;
			updateBIT(BITree, n, idx, val);
		}
		else if(type==2)
		{
			cout << "Range of RSQ: ";
			ll left, right;
			cin >> left >> right;
			cout << "Sum: " << getSum(BITree, right) - getSum(BITree, left - 1) << N;
		}
		else 
		{

			cout << "Invalid Query Type!" << N;
		}
	}
    return 0;
}


