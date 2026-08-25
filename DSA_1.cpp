#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
void bubblesort(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}
void selectionsort(int arr[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    int min=i;
    for(int j=i+1;j<n;j++)
    {
      if(arr[min]>arr[j])
      {
      min = j;
      }
    }
    swap(arr[i],arr[min]);
  }
}
void merge(int arr[],int l,int mid,int r)
{
  int temp[100];
  int i=l,k=l,j=mid+1;
  while(i<=mid && j<=r)
  {
  if(arr[i]<arr[j])
  {
    temp[k]=arr[i];
    i++;
    k++;
  }
  else
  {
    temp[k]=arr[j];
    j++;
    k++;
  }
  }
  while(i<=mid)
  {
    temp[k]=arr[i];
    i++;k++;
  }
  while(j<=r)
  {
    temp[k]=arr[j];
    j++;k++;
  }
  
  for(int z=l;z<=r;z++)
  {
    arr[z]=temp[z];
  }
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        
    }
    i++;
     swap(arr[i],arr[e]);
     return i;
}    
void quicksort(int arr[],int s,int e)
{
    if(s<e)
    {
        int pivotindex= partition(arr,s,e);
        quicksort(arr,s,pivotindex-1);
        quicksort(arr,pivotindex+1,e);
    }
}  
int binarysearch(int arr[],int n,int target)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int linearsearch(int arr[],int n,int key)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]==key)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
    int n;
    cout<<"Enter size of your array: ";
    cin>>n;
    int array[n];
    cout<<"Enter Elements of array: ";
    for(int x=0;x<n;x++)
    {
      cin>>array[x];
    }
    int choice;
    cout<<"Sorting Options:\n 1.MergeSort\n 2.QuickSort\n 3.Bubble Sort\n 4.Selection Sort\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        mergesort(array,0,n-1);
        break;
        case 2:
        quicksort(array,0,n-1);
        break;
        case 3:
        bubblesort(array,n);
        break;
        case 4:
        selectionsort(array,n);
        break;
    }
    cout<<"{";
    for(int y=0;y<n;y++)
    {
        cout<<array[y]<<",";
    }
    cout<<"}";
    int s;
    cout<<"\nEnter element you want to search: ";
    cin>>s;
    int sch;
    cout<<"Searching Options:\n 1.Binary Search \n 2.Linear Search \n";
    cout<<"Enter your choice: ";
    cin>>sch;
    switch(sch)
    {
      case 1:
      {
      int bin= binarysearch(array,n,s);
      if(bin==-1)
      {
        cout<<"Element not present";
      }
      else
      {
          cout<<"Your element is at Index: "<<bin<<endl;
      }
     }
      case 2:
      {
      int r= linearsearch(array,n,s);
      if(r==-1)
      {
        cout<<"Element not present";
      }
      else
      {
        cout<<"Your element is at Index: "<<r<<endl;
      }
     }
    }

}