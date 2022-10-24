#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <fstream>

using std::cin;

struct Node{
    int date;
    Node* next;
    
};

struct Queue{
    std::string info;
    Queue* next;
};

Queue *head, *tail;
using pQueue = Queue*;

struct CircleNode{
    int data;
    CircleNode* next;
};

struct DoubleNode{
    int date;
    DoubleNode* next;
    DoubleNode* prev;
};

struct NodePrac{
    int data;
    NodePrac* next;
    NodePrac* prev;
};

struct Stack{
    std::string info;
    Stack *next;
};



using PStack = Stack*;



void InitStack(PStack &top){
    top=NULL;
}


void pushStack(PStack &top, std::string x){
    PStack p = new Stack;
    p->info = x;
    p->next = top;
    top=p;
}

//вытаскиваем с удалением:
std::string popStack(PStack &top){
    PStack p=top;
    top = top->next;
    std::string x = p->info;
    p->next = NULL;
    delete p;
    return x;
}

//проверка на пустоту
bool isEmptyStack(PStack &top){
    return (top==NULL);
}

//вытаскиваем и сохраняем ячейку в памяти:
PStack _popStack(PStack &top){
    if(isEmptyStack(top))
        return NULL;
    else{
        PStack p =top;
        top=top->next;
        p->next=NULL;
        return p;
    }
}


void clearStack(PStack &top){
    std::string x;
    while (top) {
        x = popStack(top);
    }
}


void printStack(PStack &top){
    PStack copyStack;
    InitStack(copyStack);
    while (top) {
        std::string x = popStack(top);
        pushStack(copyStack, x);
        std::cout<<x<<" ";
    }
    std::cout<<'\n';
    while (copyStack) {
        pushStack(top, popStack(copyStack));
    }
}


void pushBack(NodePrac *head, int value){
    NodePrac* tmp = new NodePrac;
    tmp->data = value;
    NodePrac *tmpHead = head;
    while (tmpHead->next) {
        tmpHead=tmpHead->next;
    }
    tmpHead->next = tmp;
    tmp->prev = tmpHead;
}



void addAfter(NodePrac* head, int value){
    NodePrac *tmp = new NodePrac;
    tmp->data = value;
    tmp->prev = head;
    NodePrac *p = head->next;
    head->next = tmp;
    if(p!=0)
        p->prev = tmp;
    tmp->next = p;
}

void addList(NodePrac* head, NodePrac* head1){
    NodePrac* p = head1->next;
    head1->next = head;
    head->prev = head1;
    
    NodePrac* t = head;
    while (t->next) {
        t=t->next;
    }
    t->next = p;
    if(p)
        p->prev = t;
    
}

//int main(){
//    NodePrac *head = new NodePrac;
//    int value;
//    cin>>value;
//    while(value!=0){
//        pushBack(head,value);
//        cin>>value;
//    }
//}




void init(struct Node* head, int n){
    head -> date = n;
    head -> next = nullptr; //было NULL
    
}

void InitCircleNode(struct CircleNode* head, int n){
    head -> data = n;
    head -> next = head;
}

void AddElem(struct CircleNode* head, int value){
    CircleNode* tmp = new CircleNode;
    tmp->data = value;
    CircleNode *tmpHead = head;
    do {
        tmpHead=tmpHead->next;
    } while (tmpHead->next!=head);
    tmpHead->next = tmp;
    tmp -> next = head;
}

int popElem(CircleNode* &head, int k){
    for (int i = 1; i<k-1; ++i) {
        head = head->next;
    }
    if (head->next!=head) {
        CircleNode* NewNode = head->next;
        head->next = NewNode->next;
        head = NewNode->next;
        int x = NewNode -> data;
        delete NewNode;
        return x;
    }
    else{
        return head->data;
    }
   
}


Node *addLast(Node *head, int n){
    Node* end = new Node;
    init(end, n);
    while (head->next!=nullptr) {
        head = head -> next;
    }
    head -> next = end;
    end -> next = nullptr;
    return end;
}

void DoubleSort(DoubleNode *head){
    while (head->next!=nullptr) {
        DoubleNode *first = head->next;
        if(head->date > first->date){
            int x = head->date;
            head->date = first->date;
            head = head->next;
            head->date = x;
            first = first->next;
        }
        else{
            head= head->next;
        }
}
}

void Sortirovka(Node *head){
        while (head->next!=nullptr) {
            Node *first = head->next;
            if(head->date > first->date){
                int x = head->date;
                head->date = first->date;
                head = head->next;
                head->date = x;
                first = first->next;
            }
            else{
                head= head->next;
            }
    }
}

void print(Node *head){
    while (head->next != nullptr){
        std::cout<<head->date<<" ";
        head=head->next;
    }
    std::cout<<head->date<<" ";
}

void print(NodePrac *head){
    while (head->next != nullptr){
        std::cout<<head->data<<", ";
        head=head->next;
    }
    std::cout<<head->data<<" ";
}

void initQueue(pQueue &head, pQueue &tail){
    head = NULL;
    tail = NULL;
}

//добавление элемента в конец очереди
void pushQueue(pQueue &tail, std::string x){
    Queue *q = new Queue;
    q->info = x;
    q->next = tail;
    tail = q;
}

//Создание первого элемента в очереди
void firsQueue(pQueue &head, pQueue &tail, std::string x){
    Queue *q = new Queue;
    q -> info = x;
    q->next = NULL;
    tail = q;
    head = q;
}
//проверка на пустоту
bool isEmptyQueue(pQueue head){
    return(head==NULL);
}
//удаление
std::string popQueue(pQueue& tail, pQueue &head){
    std::string x = head->info;
    if(head == tail){
        delete tail;
        initQueue(head, tail);
    }
    else{
        Queue * temp = tail;
        while (temp ->next != head)
            temp = temp ->next;
        head = temp;
        temp = head->next;
        head->next = NULL;
        delete temp;
    }
    return x;
}

void Task1(){
    int count;
    cin>>count;
    Node *begin = new Node;
    int n;
    cin>>n;
    init(begin, n);
    for(int i = 1; i < count; ++i){
        int x;
        cin>>x;
        addLast(begin, x);

    }
    print(begin);
    std::cout<<std::endl;
    std::cout<<std::endl;
    Sortirovka(begin);
    print(begin);
    std::cout<<std::endl;
}

void DInit(struct NodePrac* head, int n){
    head -> data = n;
    head -> next = nullptr;
    head -> prev = nullptr;
}

int composition(NodePrac* head) {
    NodePrac* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    int result = 0;
    while (head) {
        result += head->data * tail->data;
        head = head->next;
        tail = tail->prev;
    }
    return result;
}



void Task2(){
    NodePrac* Node = new NodePrac;
    std::cout<<"Vvedite n\n";
    int n;
    cin>>n;
    DInit(Node, rand()%10+1);
    for(int i = 0;i<n-1;++i)
        pushBack(Node, rand()%10+1);
    print(Node);
    std::cout<<"\n"<<composition(Node)<<'\n';
}


std::vector<std::string> SplitIntoWords(const std::string& text)
{
    std::vector<std::string> words;
    std::string word;
    for (const char c : text)
    {
        if (c == ' ')
        {
            if (word != "")
            {
                words.push_back(word);
                word = "";
            }
        }
        else
        {
            word += c;
        }
    }
    words.push_back(word);
    return words;
}


void Task3(){
    // 8 2 5 * + 1 3 2 * + 4 - /
    PStack Stack = new struct Stack;
    InitStack(Stack);
    std::string s;
    getline(cin, s);
    std::vector<std::string> numbers = SplitIntoWords(s);
    for (int i = 0; i< numbers.size();++i){
        if (numbers[i] != "*" && numbers[i] != "+" && numbers[i] != "-" && numbers[i] != "/") {
            pushStack(Stack, numbers[i]);
        }
        else{
            if (numbers[i] == "*")
                pushStack(Stack, std::to_string(stoi(popStack(Stack))*stoi(popStack(Stack))));
            if (numbers[i] == "+")
                pushStack(Stack, std::to_string(stoi(popStack(Stack))+stoi(popStack(Stack))));
            if (numbers[i] == "-"){
                int x1 = stoi(popStack(Stack));
                int x2 = stoi(popStack(Stack));
                pushStack(Stack, std::to_string(x2-x1));
                
            }
            if (numbers[i] == "/"){
                int x1 = stoi(popStack(Stack));
                int x2 = stoi(popStack(Stack));
                pushStack(Stack, std::to_string(x2/x1));
                
            }
        }
    }
        
    printStack(Stack);
    clearStack(Stack);
}

CircleNode* DelElem(CircleNode* head, int n){
    CircleNode* temp = head;
    bool flag = true;
    CircleNode* result = new CircleNode;
    if(n==1)
        return temp;
    else{
        while (temp->next!=temp) {
            for (int i = 1; i<n-1; ++i)
                temp = temp->next;
            if (flag) {
                InitCircleNode(result, temp->next->data);
                flag = false;
            }
            else
                AddElem(result, temp->next->data);
//            delAfter(temp);
            temp = temp -> next;
        }
        AddElem(result, temp->next->data);
        return result;
    }
}

void print(CircleNode* head){
    while(head->next!=NULL){
        std::cout<< head->data <<" ";
        head=head->next;
    }
}

void Task4(){
    int k;
    std::cout<<"Введите к-тый элемент\n";
    cin>>k;
    CircleNode* Node = new CircleNode;
    InitCircleNode(Node, 1);
    for (int i = 2; i<6; ++i) {
        AddElem(Node,i);           // 1 2 3 4 5
    }
    while (Node->next != Node ) {
        std::cout<<popElem(Node,k)<<" "; //  3 1 5 2 4
    }
    std::cout<<Node->data;
//    DelElem(Node, k);
//    print(Node);
    
}


void Task5(){
    //8 2 5 * + 1 3 2 * + 4 - /
    PStack Stack = new struct Stack;
    InitStack(Stack);
    std::string s;
    getline(cin, s);
    std::vector<std::string> numbers = SplitIntoWords(s);
    for(auto i : numbers){
        if (i!="*" && i!="+"&&i!="-"&&i!="/") {
            pushStack(Stack, i);
        }
        else{
            if (i == "*") {
                std::string x1 = popStack(Stack);
                std::string x2 = popStack(Stack);
                std::string str = "("+x2+"*"+x1+")";
                pushStack(Stack, str);
            }
            if (i == "+") {
                std::string x1 = popStack(Stack);
                std::string x2 = popStack(Stack);
                std::string str = "("+x2+"+"+x1+")";
                pushStack(Stack, str);
            }
            if (i == "-") {
                std::string x1 = popStack(Stack);
                std::string x2 = popStack(Stack);
                std::string str = "("+x2+"-"+x1+")";
                pushStack(Stack, str);
            }
            if (i == "/") {
                std::string x1 = popStack(Stack);
                std::string x2 = popStack(Stack);
                std::string str = "("+x2+"/"+x1+")";
                pushStack(Stack, str);
            }
        }
    }
    printStack(Stack);
    clearStack(Stack);
}

std::string postfix(std::string giv) {
    std::string x, y, res = "";
    bool flag = true;
    Stack* top = new Stack;
    for (int i = 0; i < giv.size(); i++) {
        x = "";
        x.push_back(giv[i]);
        if (x == "+" || x == "-" || x == "*" || x == "/") {
            while (top && top->info != "(" && ((x == "*" || x == "/") && (top->info == "*" || top->info == "/") || x == "+" || x == "-"))
                res += popStack(top) + " ";
            pushStack(top, x);
        }
        else if (x == "(") {
            if (flag) {
                InitStack(top);
                pushStack(top, x);
                flag = false;
            }
            else
            pushStack(top, x);
        }
        else if (x == ")") {
            bool f = true;
            y = popStack(top);
            while (y != "(" && f) {
                res += y + " ";
                
                if(top){
                    y = popStack(top);
                }
                if (!top) {
                    f = false;
                }
                
            }
        }
        else if (x != " ") {
            res += x + " ";
        }
    }
    while (top)
        res += popStack(top);
    return res;
}

void Task6(){
//    ( ( 8 + ( 2 * 5 ) ) / ( ( 1 + ( 3 * 2 ) ) - 4 ) ) == 8 2 5 * + 1 3 2 * + 4 - /
    std::cout<<"Введите выражение: ";
    PStack Stack = new struct Stack;
    InitStack(Stack);
    std::string s;
    getline(cin, s);
    std::cout<<postfix(s);
//    std::vector<std::string> numbers = SplitIntoWords(s);
//    std::vector<std::string> result;
//    int i = 0;
//    int id = 0;
//    int count = 0;
//    bool flag = false;
//    while(i!=numbers.size()-1){
//        std::vector<std::string>copy = numbers;
//
//        while (numbers[i+1]!=")") {
//            if (numbers[i] == "("){
//                count++;
//                id = i;
//                flag = true;
//            }
//            ++i;
//        }
//        count = 0;
//        if (flag == true) {
//            pushStack(Stack,numbers[id+1]);
//            pushStack(Stack,numbers[id+3]);
//            pushStack(Stack,numbers[id+2]);
//            for (int j = 0; j<5; ++j) {
//                numbers.erase(numbers.begin()+id);
//            }
//            flag = false;
//        }
//    }
//    printStack(Stack);
//    clearStack(Stack);
    
}

//void Task7(){
//    std::ifstream Fin("text.txt");
//    pQueue *head, *tail;
//    initQueue(head, tail);
//    int n;
//    cin>>n;
//    while (!Fin.eof()) {
//        std::string s;
//        getline(Fin,s);
//        std::vector<std::string> words = SplitIntoWords(s);
//        for (int i = 0; i<words.size(); ++i) {
//            if (words[i].length()<n) {
//                pushQueue(tail, words[i]);
//            }
//        }
//    }
//}


int main() {
    setlocale(LC_ALL, "Russian");
    //Task1();
    // Task2();
//    Task3();
//    Task4();
//    Task5();
//    Task6();
//    Task7();
    
    
    return 0;
}



