### 해시 알고리즘

- 해시 알고리즘은 Key 와 Value 로 데이터를 저장하는 자료구조이다. 특정 해시함수를 사용해서 고유한 인덱스를 정하고, 그 인덱스에 해당하는 값을 저장하는 구조이다.
- 해시 인덱스가 충돌할 경우
    - 분리 연결법
        - Chaining 방식(연결해주는 방식) 을 사용해서 특정 인덱스에 겹칠 경우 자료구조를 활용해서 추가메모리를 활용한 다음 데이터를 저장하는 방식이다. Java8 의 Hash 테이블이 실제로 아래의 트리구조로 이루어져있다. 연결리스트로 하는 방식또한 있다.
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f6984146-c4ca-40a7-b6b5-e9149ba3bc90/Untitled.png)
        
    - 개방 주소법
        1. 겹칠 경우 설정해준 고정 폭만큼 이동해서 비어있는 인덱스에 넣어주기
        2. 폭을 제곱으로 해주는 방법 2^n 승 이다. 충돌이 있는 처음에는 2의 폭, 또 충돌이 있을 경우는 4의 폭, 이런식으로 옮기는 방식이다.
        3. 해시된 값을 한번더 해싱해서 위와 같은 규칙성이 없도록 한 방식이다. 새로운 주소할당을 해주는 해시연산을 해야되서 많은 연산을 해야한다.
- 시간 복잡도
    
    평균적으로 O(1) 의 시간복잡도로 데이터를 조회, 그러나 최악의 경우는 모든 데이터가 다 충돌이 일어날 경우이다. 이 경우는 O(n) 이다. 
    
- HashMap vs HashTable
    - HashTable 에서는 Synchronized 키워드가 붙어있다. 이것은 병렬 프로그래밍을 할 때에, 동기화를 지원해준다는 것을 의미한다.
    - 병렬 처리를 하지 않거나 자원의 동기화를 고려하지 않는 상황이면 HashMap, 병렬 처리를 하면서 자원의 동기화를 고려해야 하는 상황이면 HashTable을 사용해야한다.
        
        ※ 여기서 병렬처리란 CPU 의 멀티코어를 사용해서 Task 를 나누어서 연산을 수행하는 것이다. 
        

### HashMap

- 짝지어서 이루어져있는 구조로 많이 사용한다.
- HashMap 에서 key value 를 이용해서 hashcode 를 생성

```java
import java.util.HashMap;

//아래처럼 선언해 줄 수 있다.
HashMap <String, Integer> map = new HashMah<>();

//삽입
map.put("사과", 0);

//확인 - 해당 키가 있을 경우 true 아닐 경우 false
if(map.containsKey("사과") == true) ;

//해당 Key 값의 value 가져오기
Integer appleCount = map.get("사과");

//삭제
map.remove("사과");
map.clear(); //전체 삭제

//값 출력
//1. entrySet() 활용
for(Entry<Integer, String> entry : map.entrySet()){
	System.out.println("[Key] : " + entry.getKey() + ", [value] : " 
		+ entry.getValue());
}

//2. KeySet() 활용
for(Integer i : map.keySet()){
	System.out.println("[key] : " + i + ", [value] : " + map.get(i));
}
		//아래는 풀어서 쓴 코드
for(Iterator<Integer> keys = map.keySet().iterator() ; keys.hasNext() ; keys.next()){
	System.out.println("key : " + key + ", value : " + map.get(key));
}

//정렬 알고리즘
//1. value 를 이용 
		// map.entrySet 이 map 부분에 정렬해줄 map 객체를 넣어주면 된다.
List<Entry<Integer, Integer>> entryList= new ArrayList<Entry<Integer, Integer>>(map.entrySet());

            // Comparator를 사용하여 정렬
Collections.sort(entryList, new Comparator<Entry<Integer, Integer>>() {
    // 값 비교
    public int compare(Entry<Integer, Integer> obj1, Entry<Integer, Integer> obj2) {
        //오름차순 정렬
				//return obj2.getValue().compareTo(obj1.getValue());

				// 내림차순 정렬
        //return obj2.getValue().compareTo(obj1.getValue());
    }
}); //comparator 의 장점은 중간중간 키와 밸류 둘다 고려 가능이다!

		//결과 출력
for(Entry<Integer, Integer> tmp : inListtmpentryList){
    System.out.println(tmp.getKey() + " : " + tmp.getValue());
}

//2. Key 값을 이용
Object[] mapKey = animalMap.keySet().toArray();
Arrays.sort(mapKey);

		// 결과 출력하기
for(Integer keyVal : animalMap.keySet()) {
	System.out.println(animalMap.get(keyVal));
}

//Vector to Int 배열
Vector<Integer> vector = new Vector<>();
int[] answer = new int[vector.size()];
int answerCount = 0;

for(int i : vector){
    answer[answerCount++] = i;
}
```

### HashSet

- HashSet 은 Hash 알고리즘을 사용하는, set 의 구조이다. Map 은 짝지어서 값을 넣어줄 수 있지만, Set 은 불가능하다.
- Set 의 특성 상 중복이 불가능하다.
- Set 의 특성 상 순서를 유지할 수 없다.
- HashMap 에 비해서 느리다, set 내부에 중복이 된 애가 있는지 확인하고 추가나 삭제를 해야되기 때문에.
- 들어가는 객체를 이용해서 hashcode 를 생성

```java
import java.util.HashSet

//생성
HashSet <Integer> set = new HashSet<>();

//값 추가
set.add(30);

//값 확인
set.contains(30);

//값 삭제
set.remove(30); // 특정 값 제거
set.clear(); //모든 값 제거

//값 출력
for(Iterator iter = set.iterator() ; iter.hasNext() ; iter.next()){
	 System.out.println(iter);
}
```