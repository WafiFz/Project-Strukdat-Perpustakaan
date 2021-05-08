
void buat_queue(Queue& Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

pointer front(Queue Q){
    return Q.head;
}

bool isEmpty(Queue Q){
    if(Q.head==nullptr && Q.tail==nullptr){
        return true;
    }else{
        return false;
    }
}

void enqueue(Queue& Q, pointer pNew){
    pointer pRev  = nullptr;
    pointer pHelp = Q.head;
    if(isEmpty(Q)){
        Q.head = pNew;
        Q.tail = pNew;
    }else{
        while(pNew->prioritas >= pHelp->prioritas){
            if(pHelp->next == nullptr){
                break;
            }
            pRev = pHelp;
            pHelp = pHelp->next;
        }

        if(pHelp == Q.head && pNew->prioritas < pHelp->prioritas){
            pNew->next = pHelp;
            pNew->prev = nullptr;
            Q.head = pNew;
        }else if(pHelp == Q.tail && pNew->prioritas > pHelp->prioritas){
            pHelp->next = pNew;
            pNew->prev = pHelp;
            Q.tail = pNew;
        }else{
            pRev->next = pNew;
            pNew->prev = pRev;
            pNew->next = pHelp;
            pHelp->prev = pNew;
        }
    }
}

void dequeue(Queue& Q, pointer pDel){
    if(isEmpty(Q)){
        pDel = nullptr;
    }else if(Q.head->next == nullptr){
        pDel = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
    }else{
        pDel = Q.head;
        Q.head = Q.head->next;
        pDel->next = nullptr;
    }
}