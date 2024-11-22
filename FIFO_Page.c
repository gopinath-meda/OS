//FIFO Page Replacement
#include <stdio.h>  
int main()  
{   
    int pageFaults = 0,frames,m, n, s, pages,i;
    printf("Enter number of frames: ");  
    scanf("%d", &frames);  
    printf("Enter number of pages: ");  
    scanf("%d", &pages);  
    int incomingStream[pages];
    printf("Enter reference string: ");  
    for (i = 0; i <pages; ++i) 
        scanf("%d", &incomingStream[i]);  
       printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 \t Frame 4 ");  
    int temp[ frames ];  
    for(m = 0; m < frames; m++)  
        temp[m] = -1;  
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))  
            temp[m] = incomingStream[m];   
        else if(s == 0)  
            temp[(pageFaults - 1) % frames] = incomingStream[m];   
        printf("\n");  
        printf("%d\t\t\t\t",incomingStream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf(" %d\t\t\t\t", temp[n]);  
            else  
                printf(" - \t\t\t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}  
