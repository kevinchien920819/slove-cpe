#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
	int data;
	struct Node * next;
} Node;

typedef struct {
	Node *topPtr;
} Stack;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;



Stack* stackCreate() {
    //make a stack and the last is NULL
    Stack *stack = malloc(sizeof(Stack));
    stack->topPtr = NULL;
    return stack;
}

void Push(Stack* obj, int x) {
    Node* temp  = malloc(sizeof(Node));//make a space for new data
    temp->data = x;//data  = x
    temp->next = obj->topPtr; //point the next pointer to the original pointer
    obj->topPtr = temp;//then replace the first pointer to temp

}

void Pop(Stack* obj) {
    //if the obj has data remove it
    if(obj->topPtr ){
        Node* temp = obj->topPtr;//let temp = original pointer
        obj->topPtr  = temp->next;//let the pointer to the next pointer 
        free(temp);//and free the origin pointer 
    }
}
int Top(Stack* obj) {
    //if the obj has data peek the first data
    if(obj->topPtr)
        return obj->topPtr->data;//return current pointer val(which means the most top element )
    else
        return 0;
}



Queue* queueCreate() {
    Queue *head = malloc(sizeof(Queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}

void EnQueue(Queue* obj, int x) {
   Node *temp = malloc(sizeof(Node));//make a temp linkes list to store the new data
   temp->data = x;//temp data to x
   temp->next = NULL;//temp next point to null

    //not the first data in queue then the next of the buttom data is temp 
   if(obj->rear != NULL){
       obj->rear->next = temp;
       obj->rear = temp;
   }
   else{
        //if the obj is empty we must define where the front and rear pointer is 
        //because there is no data so x is the first and the last data so front and rear pointer will point at temp 
        obj->front = temp;
        obj->rear = temp;
   }

}

int DeQueue(Queue* obj) {
    //check the front has element or not if not return -1
    if(obj->front != NULL){
        //remember the delete element value
        int val = obj->front->data;
        //change the front to next element that means the first value will missing  
        obj->front = obj->front->next;
        //if after dequeue obj will be null then reset the rear pointer
        if(obj->front == NULL)
            obj->rear = NULL;
        //return the delete val
        return val;
         
    }
    else
        return -1;

}

int GetFront(Queue* obj) {
    //get the first element if there has data or return -1
	if(obj->front != NULL){
        return obj->front->data;
    }
    else
        return 0;
}

int GetMax(Queue* obj){
    Node *temp = obj->front;
    int max = temp->data;

    while(temp){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    free(temp);
    return max;
}

void GetMaxAndRemove(Queue *obj,int val){
    Node *temp = obj->front;
    int max = temp->data;
    int max_index = 0;
    int index = 0;
    while(temp){
        if(temp->data > max){
            max = temp->data;
            max_index =  index;
        }
        temp = temp->next;
        index ++;
    }
    temp = obj->front;
    max_index = index - max_index -1;
    //find the previous of the goal node
    for(int i = 0;i<max_index-1;i++){
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp2 = temp2->next;
    temp->next = temp2;
    obj = temp;

}





int main(){

    int n;
    // make a data structure
    Stack *stack = stackCreate();
    Queue *queue = queueCreate();
    Queue *priority_queue = queueCreate();

    //input untill EOF
    while(scanf("%d",&n) != EOF){
        //set three data structure is true and del the wrong one
        bool is_stack,is_queue,is_priority_queue = true;
        for(int i = 0 ;i < n;i++){
            //input action and val
            int act,val;
            scanf("%d %d",&act,&val);
            //action 1 means create new data 
            if(act == 1){
                Push(stack,val);
                EnQueue(queue,val);
                EnQueue(priority_queue,val);
                
            }
            //action 2 means delete the data
            else if(act == 2){
                //if still possible of stack then check is the toppest data = val or not if true pop out it because it still possible of stack
                if(is_stack){
                    if(stack->topPtr!= NULL && Top(stack) == val)
                        Pop(stack);
                    else
                        is_stack = false;
                }
                //if still possible of queue then check is the front data = val or not if true deque it because it still possible of queue
                else if(is_queue){
                    if(queue->front != NULL && GetFront(queue) == val)
                        DeQueue(queue);
                    else
                        is_queue = false;
                }
                //if still possible of priority queue then check is the max data = val or not if get out the max element because it still possible of priority queue
                else if(is_priority_queue){
                    if(priority_queue->front != NULL && GetMax(priority_queue) == val){
                        GetMaxAndRemove(priority_queue,val);
                    }

                }

                
            }
        }
        //if the there has two type of data structure be possible then print not sure
        //if there is no data structure possible print impossible
        if((is_stack && is_queue) || (is_queue && is_priority_queue) || (is_priority_queue && is_stack))
            printf("not sure\n");
        else if(is_queue)
            printf("queue\n");
        else if(is_stack)
            printf("stack\n");
        else if(is_priority_queue)
            printf("priority queue\n");
        else
            printf("impossible\n");
    }
    system("pause");
    return 0;
}