#include <iostream>
#include <cstdlib>

using namespace std;


// 双向链表
typedef struct T {
    int v;
    T *last;
    T *next;
} List;

void display(List *p) {
    if (p && p->v) {
        cout << p->v << " ";
        display(p->next);
    }else{
        cout<<endl;
    }
}

int N, M;
List *p[1005];  // 每个人一个指针，直接点名

int main(void) {
    cin >> N >> M;

    // 队首
    List *head = (List *) malloc(sizeof(List));
    head->v = 0;

    // 真正的队伍
    List *tail = head;
    for (int i = 1; i <= N; i++) {
        p[i] = (List *) malloc(sizeof(List));
        p[i]->v = i;
        p[i]->last = tail;
        tail->next = p[i];
        tail = tail->next;
    }
    tail = (List *) malloc(sizeof(List));

    // 队尾
    tail->v = 0;
    tail->last = p[N];
    p[N]->next = tail;

    // 开始移动
    int n, m;
    while (M-- > 0) {
        cin >> n >> m;

        List *olast = p[n]->last;
        List *onext = p[n]->next;

        // 出队
        olast->next = onext;
        onext->last = olast;

        // 查找位置
        List *nlast = olast;
        List *nnext = onext;
        if (m < 0) {
            m = -m;
            while (m-- > 0) {
                nlast = nlast->last;
                nnext = nnext->last;
            }
        } else {
            while (m-- > 0) {
                nlast = nlast->next;
                nnext = nnext->next;
            }
        }

        // 入队
        nlast->next = p[n];
        p[n]->last = nlast;
        p[n]->next = nnext;
        nnext->last = p[n];
    }

    display(head->next);

    return 0;
}