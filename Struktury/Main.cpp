//#include <iostream>
//using namespace std;

// Struktura to klasa w której wszystkie domniemane sk³adniki s¹ publiczne.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int x;
  struct node *next;
};

int main()
{
    /* This won't change, or we would lose the list in memory */
    struct node *root;       
    /* This will point to each node as it traverses the list */
    struct node *conductor;  

    root = reinterpret_cast<node *>(malloc( sizeof(struct node) ));  
    root->next = 0;   
    root->x = 12;
    conductor = root; 
    if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
        }
    }
    /* Creates a node at the end of the list */
    conductor->next = reinterpret_cast<node *>(malloc( sizeof(struct node) ));  

    conductor = conductor->next; 

    if ( conductor == 0 )
    {
        printf( "Out of memory" );
        return 0;
    }
    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;

	getchar();
    return 0;
}
