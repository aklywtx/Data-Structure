List Merge( List L1, List L2 ){
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode Temp1 = L1->Next;
    PtrToNode Temp2 = L2->Next;
    PtrToNode Temp = L;
    
    while(Temp1 && Temp2){
        if(Temp1->Data <= Temp2->Data){
            Temp->Next = Temp1;
            Temp1 = Temp1->Next;
            Temp = Temp->Next;
        }else{
            Temp->Next = Temp2;
            Temp2 = Temp2->Next;
            Temp = Temp->Next;
        }
    }
    if(Temp1==NULL) Temp->Next = Temp2;
    if(Temp2==NULL) Temp->Next = Temp1;
    L1->Next = NULL;
    L2->Next = NULL;
    
    return L;
}