# include<stdio.h>
# include<stdlib.h>
# define C 7 

struct node{
    int data;
    struct node * link ;
};


int display(struct node * p){
    
    struct node * temp = p;
    while(temp != NULL){
        printf("%d \n",temp->data);
        temp=temp-> link;
    }
    
    
}


int beginning(struct node** s){
    
    struct node* t = (struct node*)malloc(sizeof(struct node)) ;
    int x ;
    printf("enter the value : ");
    scanf("%d",&x);
    
    t -> data = x;
    t -> link = *s;
    *s = t;
    
}

int pop(struct node ** st){
    
    struct node * h = *st ;
    *st = h -> link ;
    free(h);
    
    
}






int main(){
    
    struct node * start = NULL , *temp , *newnode;
    int n ,i , value ;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    
    for(i = 0 ; i<n ; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("the allocation failed \n");
            
        
    }
    printf("enter the data of %d  ",i+1);
    scanf("%d",&value);
    
    newnode -> data= value;
    newnode -> link= NULL;
    
    if (start == NULL){
        start = newnode;
        temp = start;
    }else{
        temp -> link = newnode;
        temp = newnode;
    }
    
    
    
    
    }
    display(start);
    printf("\n");
    beginning(&start);
    printf("\n");
    display(start);
    pop(&start);
    printf("\n");
    display(start);
    return 0;
}