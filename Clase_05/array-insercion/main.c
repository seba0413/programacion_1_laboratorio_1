#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5] = {5,2,3,9,0};
    int size = 5;
    int i;
    insertion(array, size);
    for(i=0; i<size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;

}

void insertion(int data[], int len)
{
    int i,j;
    int temp;
    for(i=1; i<len;i++)
    {
        temp = data[i];
        j= i - 1;
        while(j>=0 && temp<data[j]) //temp<data
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp; //insercion
    }
}
