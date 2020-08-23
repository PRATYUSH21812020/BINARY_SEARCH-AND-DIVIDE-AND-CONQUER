#include<bits/stdc++.h>
using namespace std;
// rahul has a sorted array of numbers from which he has to find a number his friend by mistake rotated the array now rahul has no time to sort it again help him to find 
// the numbers from the rotated array 
int binary_search(vector<int>&v,int start,int end,int number)
{
  // problem on monotonic search space
  while(start<=end)
  {
    int mid=(start+end)/2;
    if(v[mid]==number)
    {
      return mid;
    }
    //case first
    else if(v[start]<=v[end])
    {
      if(number>=v[start] and number<=v[mid])
      {
        end=mid-1;
      }
      else
      {
        start=mid+1;
      }
    }
    //case second
    else if(v[end]>=v[mid])
    {
      if(number>=v[mid] and number<=v[end])
      {
        start=mid+1;
      }
      else
      {
        end=mid-1;
      }
    }
  }
  return -1;
}
int main()
{
  int n;//size of array
  cin>>n;
  int item,number;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
    cin>>item;
    v.push_back(item);
  }
  // binary search on a sorted rotated array
  cin>>number;//number to be searched
  cout<<binary_search(v,0,n-1,number);
}
