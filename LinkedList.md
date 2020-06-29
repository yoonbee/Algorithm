# 연결리스트

---

**연결리스트란?**

구조체를 이용한 데이터 저장 방법 중 하나이다. 배열처럼 동일한 형의 데이터를 여러 개 저장하기 위한 것이지만, 배열과 달리 메모리에서 저장 장소의 이동 없이 요소를 추가하거나 삽입할 수 있다. 리스트의 요소 하나는 데이터 본체와 다음 요소를 가리키는 포인터를 가지고 있는 구조체로 구성되어 있다.



**연결 리스트 작성 방법**

1. 구조체를 준비한다.
	```c
	typedef struct _STRLIST{
		char name[128];
		struct _STRLIST *next;
	}STRLIST;
	```

2. 첫 번째 요소를 만든다. 
   malloc() 함수를 사용해서 새로운 구조체에 대한 메모리를 확보한다.
   next 멤버에는 NULL을 넣는다.

   ```c
   STRLIST *listtop = NULL;	// 첫 번째 요소에 대한 주소를 넣는 포인터 변수
   
   listtop = (STRLIST *)malloc(sizeof(STRLIST));
strcpy(listtop->name, "김윤비");
	listtop->next = NULL;
   ```
   
3. 위와 마찬가지로 malloc() 함수로 다음 요소를 만들고, 앞에서 만든 요소(첫 번째 요소)의 next 멤버에 그 주소를 넣는다.

	```c
	STRLIST *p = NULL	// listtop 이외의 포인터를 선언

	p = (STRLIST *)malloc(sizeof(STRLIST));
	strcpy(p->name, "김해린");
	p->next = NULL;
	listtop->next = p;
   ```



**요소 삽입**

```c
STRLIST *p, *q;

q = listtop->next;
p = (STRLIST *)malloc(sizeof(STRLIST));
strcpy(p->name, "이은진");
p->next = q;
listtop->next = p;
```



**요소 삭제**

```c
STRLIST *p1, *p2;

p1 = listtop->next;
p2 = p1->next;
free(p1);
listtop->next = p2;
```



**요소 표시**

```c
p = listtop;
while(p!=NULL){
	printf("%s\n", p->name);
	p = p->next;
}
```

