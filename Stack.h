#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if (this->first == 0) {
				return false;
			}

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>* current = this->first; //현재 노드를 헤드 노드로 설정
			if (current->link == 0) { //다음 노드가 없을경우
				delete current; //그냥 현재 노드 삭제 -> 노드 없음
			}
			else {
				this->first = current->link; //헤드를 두 번째 노드로 변경
				element = current->data;
				delete current; //첫 번째 노드 삭제
				this->current_size--; //사이즈 1 줄이기
			}

			return true;
			}
};
