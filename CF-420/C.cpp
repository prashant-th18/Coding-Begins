#include <stdio.h>

float average(int n, int sum);
float percentage(int n, int sum);

int main()
{
    int n, i, marks, sum=0;
    float avg, per;
    printf("\nEnter the number of subjects: ");
    scanf("%d", &n);
    
    for(i=1; i<=n; i++)
    {
        printf("Enter the marks of subject %d: ", i);
        scanf("%d", &marks);
        sum = sum + marks;
    }
    avg = average(n, sum);
    per = percentage(n, sum);
    printf("\nAverage: %.2f", avg);
    printf("\nPercentage: %.2f", per);
    return 0;
}

float average(int n, int sum)
{
    float avg;
    avg = (float)sum/n; // type cast
    return avg;
}
    
float percentage(int n, int sum)
{
    float per;
    per = ((float)sum/(n*100))*100; // 0.562 // 56.2 <- 

    // float * int -> float 
    int * int  > int
    // int * float -> float
    return per;
}