# C++ Basic

## 템플릿 함수(template function0



## 제너릭 프로그래밍 개념 




## 선언 구문과 유형이 정해진 상수


## 함수 객체 (function object)

일련의 초기화 과정이 필요하고 특정 상태를 유지하는 함수가 필요한 경우 C++에서 함수 객체를 사용하여 이 기능을 구현한다. 함수 객체는 하나의 (이름 없는) 함수를 캡슐화한 객체이다. 
함수 객체는 직접적인 함수 호출에 비해 두 가지 장점을 가진다. 첫 번째 장점은 함수 객체에 상태를 포함할 수 있다는 점이고 두 번쨰 장점은 객체가 자료형이므로 템플릿 매개변수로 사용할 수 있다.

### 함수 객체 만들기 
함수 객체를 만들기 위해서 다음과 같은 형식을 만들고 ```operator()```를 구현한다. 

```c++
class Functor{
public:
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

int main(int argc, char const *argv[])
{
	Functor f;
	int a = 5, b = 6;

	bool result = f(a, b);  // 함수 객체 호출 
	cout << "f(" << a <<", " << b <<"): " << result << endl;
	return 0;
}
```
```f(a, b)```는 함수를 호출하는 것과 같으나 실제로 Functor 자료형의 ```()``` 연산자를 호출한 것이다. 

다음 함수 객체 환율을 변환하는 함수 객체의 간단한 예이다. 객체 안에 포함되는 이름없는 함수를 선언할 때는 ```operator()``` 연산자를 사용하면 된다.

```c++

class converter{
	double exchange_rate;

public:
	converter(double ex) : exchange_rate(ex) {}

	double operator()(double amt) {
		return amt * exchange_rate;
	}
};

int main(int argc, char const *argv[])
{
	converter dollarToWon(1182);
	double won = dollarToWon(100);   // dollar to won converter

	cout << "won: " << won << endl;
}

```


### 함수 객체 및 알고리즘 

함수 객체의 다른 용도는 알고리즘이다. 

## 전제 조건, 사후 조건 그리고 assert 구문 


## STL 알고리즘과 자료구조 


## 반복자와 구간 


## C++ 11의 using을 이용한 유형 앨리어스와 유형 함수 

type alias와 type function


## C++ 11의 리스트 초기화


## C+11 람다 함수 


## inline 지시자

함수 앞에 inline 지시자를 붙이면 컴파일러는 함수 호출 위치에 inline 지시자를 붙은 함수 본체를 포함 시킨다. 이 경우 함수 호출 오버해드를 없앨 수 있다. inline 함수는 비교적 짧은 코드에서만 효과가 좋다. 
