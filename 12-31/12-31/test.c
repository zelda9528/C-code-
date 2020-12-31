#define _CRT_SECURE_NO_WARNINGS 1

typedef struct {
	int front;  //队首元素
	int rear;   //队尾元素的下一个位置
	int size;      //有效元素个数
	int* data;  //存放元素的连续空间的首地址
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->data = (int *)malloc(sizeof(int) * (k + 1));
	cq->size = k;
	cq->front = cq->rear = 0;   //0~k都可以
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	//判断循环队列满的条件：(rear+1)%空间长度==front d
	return (obj->rear + 1) % (obj->size + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))       //若队伍已满，无法入队
		return false;
	//队尾入队
	obj->data[obj->rear++] = value;
	//判断队尾是否越界
	if (obj->rear == obj->size + 1)
		obj->rear = 0;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//若队列为空，不能出队
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front++;

	//判断队首是否越界
	if (obj->front == obj->size + 1)
		obj->front = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	//队尾元素再rear索引的前一个位置，如果rear为0，
	//则队尾元素在数组的最后一个位置
	if (obj->rear == 0)
		return obj->data[obj->size];
	else
		return obj->data[obj->rear - 1];
}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/