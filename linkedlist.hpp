//Brent Roberson HW2 
#include <iostream>
#include "linkedlist.h"

using namespace std;

template <class T>
LinkedList<T>:: ~LinkedList(){
  clear();
  delete m_head;
};

template <class T>
void LinkedList<T>::clear(){
  LLNode<T>* tmp = m_head;
  while(tmp->m_next!=NULL){
    m_head = tmp->m_next;
    delete tmp;
    tmp = m_head;
  }
  m_size = 0;
};

template <class T>
LLNode<T>* LinkedList<T>::getFirstPtr(){
  if(isEmpty()){
    return NULL;
  }
  return m_head;
}

template <class T>
bool LinkedList<T>::isEmpty() const{
  if(m_size>0){
    return false;
  }
  return true;
}


template <class T>
LLNode<T>* LinkedList<T>::getAtPtr(int i){
  if(i<0 || i>m_size){
    return NULL; 
  }
  LLNode<T>* tmp = m_head;
  for (int k=0; k<i; k++)
    tmp = tmp->m_next;
  return tmp;
}

template <class T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos){
  LLNode<T>* tmp = new LLNode<T>;
  *tmp = *pos;
  pos->m_data = x;
  pos->m_next = tmp;
  m_size++;
};

template <class T>
void LinkedList<T>::insert_front(const T& x){
  if(m_size == 0){
    LLNode<T>* tmp = new LLNode<T>(x, m_head);
	  m_head = tmp;
	  m_size++;
  }
  else{
    insert(x, getFirstPtr());
  }
}

template <class T>
void LinkedList<T>::insert_back(const T& x){
  insert(x, getAtPtr(m_size));
}

template <class T>
void LinkedList<T>::remove(LLNode<T>* pos){
  LLNode<T>* tmp = pos->m_next;
  *pos = *tmp;
  delete tmp;
  m_size--;
}

template <class T>
void LinkedList<T>::remove_front(){
  remove(getFirstPtr());
}

template <class T>
void LinkedList<T>::remove_back(){
  remove(getAtPtr(m_size-1));
}

template <class T>
LLNode<T>* LinkedList<T>::find(const T& x){
  LLNode<T>* tmp = m_head;
  for(int i = 0; i<m_size-1; i++){
    if(tmp->m_data==x){
      return tmp;
    }
    tmp = tmp->m_next;
  }
  return NULL;
}

template <class T>
int LinkedList<T>::size() const {return m_size;};

template <class T>
const LinkedList<T>& LinkedList<T>:: operator= (const LinkedList<T>& rhs){
  clear();
  LLNode<T>* p = m_head;
  LLNode<T>* q = rhs.m_head;
  while( q->m_next != NULL ){
    insert(q->m_data, p);
    q = q->m_next;
    p = p->m_next;        
  }
  m_size = rhs.m_size;
  return *this;
}

template <class T>
bool LinkedList<T>:: operator== (const LinkedList<T>& rhs) const{
  LLNode<T>* p = m_head;
  LLNode<T>* q = rhs.m_head;
  if(rhs.m_size!=m_size){return false;}

  for(int i = 0; i<m_size-1; i++){
    if(p->m_data!=q->m_data){
      return false;
    }
    p = p->m_next;
    q = q->m_next;
  }
  return true;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
  m_head = new LLNode<T>;
  m_head->m_next = NULL;
  *this = rhs;
}

template <class T>
void LinkedList<T>::reverse(){
  for(int i = m_size; i>=0; i--){
    insert(getAtPtr(i)->m_data,getAtPtr(m_size));
    remove(getAtPtr(i));
  }
}

template <class T>
void LinkedList<T>::append(const LinkedList<T>& l2){
  LLNode<T>* tmp = l2.m_head;
  for(int i = 0; i<l2.m_size; i++){
    insert_back(tmp->m_data);
    tmp = tmp->m_next;
  }
}


template <class T>
void LinkedList<T>::slice( const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop){
  clear();
  LLNode<T>* tmp = start;
  while(tmp!=stop){
    insert_back(tmp->m_data);
    tmp = tmp->m_next;
  }
}


