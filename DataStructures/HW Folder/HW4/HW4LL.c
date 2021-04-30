typedef struct LLNode
{
    int info;     //int in the linked list node struct
    LLNode *next; //next node in linked list
} LLNode;

void insertNode(LLNode **pHead, int x)
{
    LLNode *inserter;
    inserter = (LLNode *)malloc(sizeof(LLNode));
    inserter->info = x;
    inserter->next = (*pHead)->next;
    (*pHead)->next = inserter;
}



LLNode* deleteNode(LLNode *pHead, int x){ 
        LLNode *ptr; 
        if(pHead == NULL){ 
            return NULL
        } else if (pHead->info==x){ 
            ptr = pHead->next;
            free(pHead);
            return ptr;

        } else{ 
            ptr = deleteNode(pHead->next,x);
            pHead = ptr;
            return pHead;
        } 
}